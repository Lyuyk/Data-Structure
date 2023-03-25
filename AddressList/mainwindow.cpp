/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:mainwindow.cpp
  摘要:主窗口函数源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include "createwidget.h"
#include "insertwidget.h"
#include "searchdeletewidget.h"
#include "showwidget.h"
#include "addfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),binaryTreeStruct(new completeBinaryTree<student>)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_create_clicked()
{
    createWidget *widget=new createWidget(binaryTreeStruct);
    widget->show();
}

void MainWindow::on_pushButton_insert_clicked()
{
    insertWidget *widget=new insertWidget(binaryTreeStruct);
    widget->show();
}

void MainWindow::on_pushButton_search_clicked()
{
    searchDeleteWidget *widget=new searchDeleteWidget(binaryTreeStruct);
    widget->show();
}

void MainWindow::on_pushButton_show_clicked()
{
    showWidget *widget=new showWidget(binaryTreeStruct);
    widget->show();
}

void MainWindow::on_pushButton_readFromFile_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(NULL,"选择读取路径","./*.dat","*.dat");
    if(binaryTreeStruct->load(fileName.toUtf8().data()))
        QMessageBox::information(NULL,"提示","读取成功");
    else
        QMessageBox::critical(NULL,"错误","文件读取失败\n请检查文件路径或文件格式是否正确");
}

void MainWindow::on_pushButton_writeToFile_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(NULL,"选择写入路径","./*.dat","*.dat");
    if(binaryTreeStruct->save(fileName.toUtf8().data()))
        QMessageBox::information(NULL,"提示","写出成功");
    else
        QMessageBox::critical(NULL,"错误","文件读取失败\n请检查文件路径或文件格式是否正确");
}

void MainWindow::on_pushButton_buildStuData_clicked()
{
    addFile *widget=new addFile;
    widget->show();
}
