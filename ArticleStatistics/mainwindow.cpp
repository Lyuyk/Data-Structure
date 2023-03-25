/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:mainwindow.cpp
  摘要:主窗口源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "initialwidget.h"
#include "printtreewidget.h"
#include "printcodewidget.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_initialize_clicked()
{
    initialWidget* widget=new initialWidget();
    widget->show();
}

void MainWindow::on_pushButtonEncode_clicked()
{        
    ifstream in("hfmTree.txt", ios::binary);
    if (!in)
    {
        QMessageBox::critical(NULL,"提示","请先初始化哈夫曼树！");
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

        //接下来开始编码
    string fileName;
    fileName=(QFileDialog::getOpenFileName(NULL,"选择你要编码的文件","./*.txt","*.txt")).toUtf8().data();
    myTree.encoding(fileName);
}

void MainWindow::on_pushButtonDecode_clicked()//解码
{
    if (myTree.isEmpty())
        {
            ifstream in("hfmTree.txt", ios::binary);
            if (!in)
            {
                cout << "请先初始化哈夫曼树！" << endl;
                return;
            }
            //先读入种类数
            in.read((char*)&myTree.typeNum, sizeof(myTree.typeNum));
            //开始建立哈夫曼树
            myTree.keys = new char[myTree.typeNum + 1];
            myTree.times = new unsigned short[myTree.typeNum];
            myTree.codes = new string[myTree.typeNum];
            //先读入字符和频度
            for (int i = 0; i < myTree.typeNum; i++)
            {
                in.read((char*)&myTree.keys[i], sizeof(myTree.keys[i]));
                in.read((char*)&myTree.times[i], sizeof(myTree.times[i]));
            }
            myTree.createTree(myTree.keys, myTree.times, myTree.typeNum);//建立树
            myTree.setWpl(myTree.root);//统计wpl
            myTree.encode(myTree.root, "");//对每个字符进行相应的编码
            myTree.setCodeArray(myTree.root);//对编码数组codes[]进行赋值，以便后续操作
            myTree.save();//保存
        }
        //接下来开始解码
        //cout << "请输入要解码的文件名称" << endl;
        string fileName;
        fileName=(QFileDialog::getOpenFileName(NULL,"选择要解码的文件","./*.txt","*.txt")).toUtf8().data();

        myTree.decode(fileName);
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}

void MainWindow::on_pushButtonPrintTree_clicked()//显示哈夫曼树
{
    printTreeWidget* widget=new printTreeWidget();
    widget->show();
}

void MainWindow::on_pushButtonPrintCode_clicked()//显示编码文件
{
    printCodeWidget* widget=new printCodeWidget();
    widget->show();
}
