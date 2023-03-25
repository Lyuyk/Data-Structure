/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:createwidget
  摘要:创建学生信息源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "createwidget.h"
#include "ui_createwidget.h"
#include <QMessageBox>
#include <QDebug>

createWidget::createWidget(completeBinaryTree<student> *btStu, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createWidget),
    binaryTreeFile(btStu)
{
    ui->setupUi(this);
    QRegExp rxNumber("\\d+$");
    QRegExp rxChar("[^0-9]+$");
    QRegExpValidator *numberValidator=new QRegExpValidator(rxNumber);
    QRegExpValidator *charValidator=new QRegExpValidator(rxChar);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    //设置合法输入
    ui->lineEditName->setValidator(charValidator);
    ui->lineEditTel->setValidator(numberValidator);
    ui->lineEditID->setValidator(numberValidator);
    ui->lineEditAddress->setValidator(charValidator);
}

createWidget::~createWidget()
{
    delete ui;
}

void createWidget::on_pushButtonAdd_clicked()
{
    if(ui->lineEditAddress->text().isEmpty()||
            ui->comboBoxSex->currentText().isEmpty()||
            ui->dateEditBirth->text().isEmpty()||
            ui->lineEditTel->text().isEmpty()||
            ui->lineEditID->text().isEmpty()||
            ui->lineEditAddress->text().isEmpty())
    {
        QMessageBox::warning(NULL,"提示","填入信息存在空项");
    }
    else
    {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(ui->lineEditID->text()));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(ui->lineEditName->text()));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(ui->comboBoxSex->currentText()));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(ui->dateEditBirth->text()));
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(ui->lineEditTel->text()));
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(ui->lineEditAddress->text()));
    }
}

void createWidget::on_pushButtonDel_clicked()
{
    QTableWidgetItem *item=ui->tableWidget->currentItem();
    if(item==Q_NULLPTR)return;
    ui->tableWidget->removeRow(item->row());
}

void createWidget::on_pushButtonCreate_clicked()
{
    int row=ui->tableWidget->rowCount();

    student *stu=new student[row]();

    for(int i=0;i<row;i++)
    {
        strcpy_s(stu[i].number, ui->tableWidget->item(i, 0)->text().toUtf8().data());
        strcpy_s(stu[i].name, ui->tableWidget->item(i, 1)->text().toUtf8().data());
        strcpy_s(stu[i].sex, ui->tableWidget->item(i,2)->text().toUtf8().data());


        QRegExp r("(\\d+)/(\\d+)/(\\d+)");// 日期正则表达式
        int pos=r.indexIn(ui->tableWidget->item(i,3)->text());
        if(pos<0){
            QMessageBox::warning(NULL,"错误",QString::number(pos));return;
        }
        stu[i].birthday = r.cap(1).toInt();                                      //年份
        stu[i].birthday = (stu[i].birthday << 4) + r.cap(2).toInt();             //月份
        stu[i].birthday = (stu[i].birthday << 5) + r.cap(3).toInt();             //日期

        strcpy_s(stu[i].phonenum, ui->tableWidget->item(i, 4)->text().toUtf8().data());
        strcpy_s(stu[i].addr, ui->tableWidget->item(i, 5)->text().toUtf8().data());
    }
    binaryTreeFile->CreateBinTree(stu,row);
    QMessageBox::information(NULL,"提示","创建成功");
    this->close();

}

void createWidget::on_pushButtonCancel_clicked()
{
    this->close();
}
