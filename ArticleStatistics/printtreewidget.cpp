/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:printtreewidget.cpp
  摘要:打印哈夫曼树窗口源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "printtreewidget.h"
#include "ui_printtreewidget.h"
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>

using namespace std;

printTreeWidget::printTreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::printTreeWidget)
{
    ui->setupUi(this);
}

printTreeWidget::~printTreeWidget()
{
    delete ui;
}

void printTreeWidget::on_pushButtonPrintTree_clicked()
{
    if (myTree.isEmpty())
        {
            ifstream in("hfmTree.txt", ios::binary);
            if (!in)
            {
                QMessageBox::critical(NULL,"提示","请先初始化哈夫曼树");
                return;
            }
            //先读入种类数
            in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
            myTree.keys = new char[myTree.typeNum + 1];
            myTree.times = new unsigned short[myTree.typeNum];
            myTree.codes = new string[myTree.typeNum];
            //接着读入字符和频度
            for (int i = 0; i < myTree.typeNum; i++)
            {
                in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
                in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
            }
            myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//建立树
            myTree.setWpl(myTree.root);//统计wpl
            myTree.encode(myTree.root, "");//对每个字符进行相应的编码
            myTree.setCodeArray(myTree.root);
            myTree.save();//保存
            myTree.displayHuffman();
        }
        else
            myTree.displayHuffman();
        QMessageBox::information(NULL,"提示","哈夫曼树已经写入文件TreePrin.txt，非叶子结点的关键字默认显示\\0");

        QTextCodec *codec=QTextCodec::codecForName("Utf8");
        QFile printFile("TreePrin.txt");
        if(!printFile.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            QMessageBox::critical(NULL,"错误","读取代码文件失败");
            return;
        }

        while(!printFile.atEnd())//读取哈夫曼树并显示
        {
            QByteArray line=printFile.readLine();
            QString str=codec->toUnicode(line);
            ui->textBrowser->insertPlainText(str);
        }

}

void printTreeWidget::on_pushButtonExit_clicked()
{
    this->close();
}
