/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:searchdeletewidget.cpp
  摘要:搜索和删除学生信息源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "searchdeletewidget.h"
#include "ui_searchdeletewidget.h"
#include <QTableWidgetItem>
#include <string.h>
#include <QDebug>

searchDeleteWidget::searchDeleteWidget(completeBinaryTree<student> *btStu, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchDeleteWidget),
    binaryTreeFile(btStu),
    tempStu(NULL)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
}

searchDeleteWidget::~searchDeleteWidget()
{
    delete ui;
}

void searchDeleteWidget::on_pushButtonSearch_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    clock_t startTime, endTime;
    startTime = clock();
    if(binaryTreeFile->isEmpty())
    {
        QMessageBox::critical(NULL,"错误","通讯录无任何相关记录");return;
    }

    int index;
    if(ui->radioButtonID->isChecked())
        index=0;
    else if(ui->radioButtonName->isChecked())
        index=1;
    else
        index=2;

    char info[3][21];
    strcpy_s(info[index],ui->lineEditInfo->text().toUtf8().data());

    switch (index)
    {
        case 0:tempStu=binaryTreeFile->findNumber(info[index]);break;//查找（按学号）
        case 1:tempStu=binaryTreeFile->findName(info[index]);break;//查找（按名字）
        case 2:tempStu=binaryTreeFile->findTel(info[index]);break;//查找（按电话号码）
        default:break;
    }
    endTime = clock();                //计时
    double time=(double) (endTime - startTime) / CLOCKS_PER_SEC;
    QMessageBox::information(NULL,"提示","查找时间为"+QString::number(time)+"s");

    if(tempStu!=NULL)
    {
        ui->tableWidget->insertRow(0);
        ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::fromUtf8(tempStu->data.name)));
        ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::fromUtf8(tempStu->data.number)));
        ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::fromUtf8(tempStu->data.sex)));
        QString birthday=QString::number(tempStu->data.birthday>>9)+'/'
                +QString::number(tempStu->data.birthday<<23>>28)+'/'
                +QString::number(tempStu->data.birthday<<27>>27);
        ui->tableWidget->setItem(0,3,new QTableWidgetItem(birthday));
        ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::fromUtf8(tempStu->data.phonenum)));
        ui->tableWidget->setItem(0,5,new QTableWidgetItem(QString::fromUtf8(tempStu->data.addr)));
    }
    else
        QMessageBox::warning(NULL,"错误","未找到任何记录");

}

void searchDeleteWidget::on_pushButtonCancel_clicked()
{
    this->close();
}

void searchDeleteWidget::on_pushButtonDel_clicked()
{
    clock_t startTime, endTime;
    startTime = clock();
    if(tempStu==NULL)
        QMessageBox::critical(NULL,"错误","当前未找到任何记录");
    else if(binaryTreeFile->remove(tempStu->data))
    {
        tempStu=NULL;
        QMessageBox::information(NULL,"提示","删除成功");
    }
    endTime = clock();                //计时
    double time=(double) (endTime - startTime) / CLOCKS_PER_SEC;
    QMessageBox::information(NULL,"提示","删除操作时间为"+QString::number(time)+"s");
}
