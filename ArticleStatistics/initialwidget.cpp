/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:initialwidget.cpp
  摘要:初始化哈夫曼树窗口源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "initialwidget.h"
#include "ui_initialwidget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

using namespace std;

initialWidget::initialWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::initialWidget)
{
    ui->setupUi(this);
    ui->spinBoxCharSize->setDisabled(1);
    ui->pushButtonInitial->setDisabled(1);//未统计字符前无法初始化哈夫曼树
}

initialWidget::~initialWidget()
{
    delete ui;
}

void initialWidget::on_pushButtonExit_clicked()
{
    this->close();
}

void initialWidget::on_pushButtonInitial_clicked()
{
    unsigned short num,times;
    char c;
    num=ui->spinBoxCharSize->value();//字符集大小
    QString outputFileName=ui->labelStoreStatisticFile->text();
    QFile inputFile(outputFileName);
    if(!inputFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(NULL,"错误","字符统计文件打开失败,无法读入数据文件");
        return;
    }
    QTextStream in(&inputFile);

    myTree.keys = new char[num+1];
    myTree.times = new unsigned short[num];
    myTree.codes = new string[num];

    for (int i = 0; i < num; i++)
    {
        myTree.keys[i] = in.readLine().at(0).unicode();
        myTree.times[i] = in.readLine().toInt();
    }
     myTree.typeNum = num;//字符种类数
     myTree.createTree(myTree.keys, myTree.times, num);//建立树
     myTree.setWpl(myTree.root);//统计wpl
     myTree.encode(myTree.root,"");//对每个字符进行相应的编码
     myTree.setCodeArray(myTree.root);
     myTree.save();//保存

}

void initialWidget::on_pushButtonChooseFile_clicked()
{
    int counts[128];
    memset(counts, 0, sizeof(counts));

    string fileName;
    QString qfileName=QFileDialog::getOpenFileName(NULL,"选择要统计的文章文件","./*.txt","*.txt");
    ui->labelStatisticedFile->setText(qfileName);
    fileName=qfileName.toUtf8().data();

    QString statisticsFileName="statisticedFile.txt";
    //statisticsFileName=QFileDialog::getOpenFileName(NULL,"选择要存储的文章统计数据文件","./*.txt","*.txt");
    ui->labelStoreStatisticFile->setText(statisticsFileName);

    QFile outputFile(statisticsFileName);
    if(!outputFile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QMessageBox::critical(NULL,"错误","统计文件打开失败");
        return;
    }
    QTextStream out(&outputFile);

    ifstream in(fileName, ios::in);
    if (!in)
    {
        QMessageBox::critical(NULL,"错误","待统计文件打开失败");
        return;
    }
    char c;

    while (in.peek() != EOF)
    {
        c=in.get(); //读入一个字符
        counts[c - '\0']++;
    }
    int num = 0;//统计出现的字符种类

    ui->tableWidget->setRowCount(128);
    for (int i = 31; i <128; i++)
    {
        if (counts[i] != 0)
        {
            c = i - 0;
            out << c << Qt::endl;
            out << counts[i] << Qt::endl;

            QChar qc=c;
            QString qchar(qc);
            QString qstr=QString::number(counts[i]);//将权值转换为字符串
            ui->tableWidget->setItem(i-31,0,new QTableWidgetItem(qchar));
            ui->tableWidget->setItem(i-31,1,new QTableWidgetItem(qstr));
            ui->textBrowser->append(qchar+" "+qstr);
            num++;
        }
        else
        {
            QChar qc=i-0;
            ui->tableWidget->setItem(i-31,0,new QTableWidgetItem(qc));
            ui->tableWidget->setItem(i-31,1,new QTableWidgetItem("0"));
        }
    }
    QMessageBox::information(NULL,"提示","字符集个数为："+QString::number(num)+"\n(默认不统计非英文字符和除空格外的不可见字符)");
    ui->spinBoxCharSize->setValue(num);//设置
    ui->pushButtonInitial->setEnabled(1);
    in.close();
    outputFile.close();
}
