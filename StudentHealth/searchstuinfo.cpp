/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:searchstuinfo.cpp
  摘要:搜索学生信息窗口源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "searchstuinfo.h"
#include "ui_searchstuinfo.h"
#include <QMessageBox>

searchStuInfo::searchStuInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchStuInfo)
{
    ui->setupUi(this);
    ui->lineEditAddress->setDisabled(1);
    ui->lineEditAge->setDisabled(1);
    ui->lineEditBirthday->setDisabled(1);
    ui->lineEditBodyCondition->setDisabled(1);
    ui->lineEditGender->setDisabled(1);
    ui->lineEditName->setDisabled(1);
    ui->lineEditTel->setDisabled(1);
}

searchStuInfo::~searchStuInfo()
{
    delete ui;
}

void searchStuInfo::on_pushButtonSearch_clicked()
{
    if(ui->lineEditID->text()=="") {
        QMessageBox::about(NULL, "反馈", "学号不能为空");
        return;
    }

    Node<stuInfo> pHead;//创建链表
    QString name;
    long long number = ui->lineEditID->text().toLongLong();
    int age;
    QString gender;
    long long tel;
    QString bir;
    QString address;
    QString bodyCondition;
    pHead.inputStuInfo();
    bool pd=pHead.searchStuInfo(name,number,age,gender,address,bir,tel,bodyCondition);//搜索操作
    if(pd==false)//若返回结果即搜索成功
    {
        QMessageBox::about(0,"错误","查无此人");
        return;
    }
    ui->lineEditName->setText(name);
    ui->lineEditAge->setText(QString::number(age));
    ui->lineEditGender->setText(gender);
    ui->lineEditTel->setText(QString::number(tel));
    ui->lineEditBodyCondition->setText(bodyCondition);
    ui->lineEditAddress->setText(address);
    ui->lineEditBirthday->setText(bir);
}



void searchStuInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
