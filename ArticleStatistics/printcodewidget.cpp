/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:printcodewidget.cpp
  摘要:添加学生信息源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "printcodewidget.h"
#include "ui_printcodewidget.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>

printCodeWidget::printCodeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::printCodeWidget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

printCodeWidget::~printCodeWidget()
{
    delete ui;
}

void printCodeWidget::on_pushButtonPrintCode_clicked()
{
    ui->progressBar->setVisible(1);
        //为省去建树的时间，考虑将wpl直接写入文件，则读取时可不依赖Huffman树即可输出二进制码
        string fileName;
        fileName=(QFileDialog::getOpenFileName(NULL,"请选择要显示二进制码的文件名","./*.txt","*.txt")).toUtf8().data();

        ifstream in(fileName, ios::binary);

        ofstream out("CodePrin.txt", ios::out);//输出到编码打印文件中

        if (!in||!out)
        {
            QMessageBox::critical(NULL,"错误","文件打开失败");
            return;
        }

        //统计文件大小，为进度条显示进度数据做准备
        in.seekg(0,ios::end);
        const double LENGTH=in.tellg()*8;
        in.seekg(0,ios::beg);

        double length=0;
        int wpl;
        in.read((char*)&wpl, sizeof(int));
        unsigned char c;
        int temp=0;//计数器
        ui->label_progress->setText("加载文件中……");

        //将读入的十进制数转换成01二进制代码
        for (int i = 0; i < wpl / 8; i++)
        {
            in.read((char*)&c, sizeof(c));
            int num = c;
            for (int i = 8; i > 0; i--)
            {
                if (c & (1 << i))
                {
                    ui->textBrowser->insertPlainText("1");
                    out << '1';
                    length+=100;
                }
                else
                {
                    ui->textBrowser->insertPlainText("0");
                    out << '0';
                    length+=100;
                }

                temp++;
                if (temp % 50 == 0)//保证每行50个
                {
                    ui->textBrowser->insertPlainText("\n");
                    out << endl;
                }
            }
            if(int(length)%102400==0)
            {
                ui->progressBar->setValue(length/LENGTH);
                qDebug()<<length/LENGTH;
            }
        }

        //对最后一位十进制数是否转成8位二进制代码的处理
        if (wpl % 8 != 0)
        {
            in.read((char*)&c, sizeof(c));
            int num = c;
            for (int i = wpl%8; i > 0; i--)
            {
                if (c & (1 << i))
                {
                    out << '1';
                    ui->textBrowser->insertPlainText("1");
                }
                else
                {
                    out << '0';
                    ui->textBrowser->insertPlainText("0");
                }
                temp++;
                if (temp % 50 == 0)//保证每行50个
                {
                    out << endl;
                    ui->textBrowser->insertPlainText("\n");
                }
            }
        }
        cout << endl;
        ui->label_progress->setText("文件加载完成");
        ui->progressBar->setValue(100);
}

void printCodeWidget::on_pushButtonExit_clicked()
{
    this->close();
}
