/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:showwidget.cpp
  摘要:添加学生信息源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "showwidget.h"
#include "ui_showwidget.h"

showWidget::showWidget(completeBinaryTree<student> *btStu, QWidget *parent):QWidget(parent),
    ui(new Ui::showWidget),binaryTreeFile(btStu)
{
    ui->setupUi(this);
}

showWidget::~showWidget()
{
    delete ui;
}

void showWidget::on_pushButtonSearch_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    auto show=[&](binTreeNode<student> *current)
    {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::fromUtf8(current->data.number)));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString::fromUtf8(current->data.name)));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString::fromUtf8(current->data.sex)));
        QString birthday=QString::number(current->data.birthday>>9)+"/"
                +QString::number(current->data.birthday<<23>>28)+"/"
                +QString::number(current->data.birthday<<27>>27);
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(birthday));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString::fromUtf8(current->data.phonenum)));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::fromUtf8(current->data.addr)));
    };
    if(ui->radioButtonPreOrder->isChecked())binaryTreeFile->preOrder(show);
    else if(ui->radioButtonInOrder->isChecked())binaryTreeFile->inOrder(show);
    else if(ui->radioButtonPostOrder->isChecked())binaryTreeFile->postOrder(show);
    else
        QMessageBox::critical(NULL,"错误","请选择一种方式");
}

void showWidget::on_pushButtonYoungestSearch_clicked()
{
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    clock_t startTime, endTime;
    startTime = clock();
    if(binaryTreeFile->isEmpty())
    {
        QMessageBox::critical(NULL,"错误","当前未有任何记录");
        return;
    }
    binTreeNode<student> *root=binaryTreeFile->getRoot();
    binTreeNode<student> *temp=NULL;
    binTreeNode<student> *youngest=root;

    queue<binTreeNode<student> *>Q;
    Q.enQueue(root);

    while(!Q.isEmpty())
    {
        Q.deQueue(temp);
        for(unsigned i=0;i<3;i++)
        {
            if(temp->data.birthday <= youngest->data.birthday)
                break;
            else if(temp->data.birthday > youngest->data.birthday)
            {
                youngest=temp;
                break;
            }
        }
        if(temp->child[0]!=NULL)Q.enQueue(temp->child[0]);
        if(temp->child[1]!=NULL)Q.enQueue(temp->child[1]);

    }
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString::fromUtf8(youngest->data.name)));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::fromUtf8(youngest->data.number)));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::fromUtf8(youngest->data.sex)));
    QString birthday=QString::number(youngest->data.birthday>>9)+"/"
            +QString::number(youngest->data.birthday<<23>>28)+"/"
            +QString::number(youngest->data.birthday<<27>>27);
    ui->tableWidget->setItem(0,3,new QTableWidgetItem(birthday));
    ui->tableWidget->setItem(0,4,new QTableWidgetItem(QString::fromUtf8(youngest->data.phonenum)));
    ui->tableWidget->setItem(0,5,new QTableWidgetItem(QString::fromUtf8(youngest->data.addr)));

    endTime = clock();                //计时
    double time=(double) (endTime - startTime) / CLOCKS_PER_SEC;
    QMessageBox::information(NULL,"提示","查找时间为"+QString::number(time)+"s");

}
