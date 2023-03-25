/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:delstuinfo.cpp
  摘要:删除学生信息窗口
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "delstuinfo.h"
#include "ui_delstuinfo.h"
#include "node.h"
#include "stuinfo.h"
#include <QMessageBox>

delStuInfo::delStuInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delStuInfo)
{
    ui->setupUi(this);
    ui->lineEditAddress->setDisabled(1);
    ui->spinBoxAge->setDisabled(1);
    ui->lineEditBirthday->setDisabled(1);
    ui->lineEditBodyCondition->setDisabled(1);
    ui->lineEditGender->setDisabled(1);
    ui->lineEditName->setDisabled(1);
    ui->lineEditTel->setDisabled(1);
}

delStuInfo::~delStuInfo()
{
    delete ui;
}

void delStuInfo::on_pushButtonSearch_clicked()
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
    bool pd=pHead.searchStuInfo(name,number,age,gender,address,bir,tel,bodyCondition);
    if(pd==false)
    {
        QMessageBox::about(0,"错误","查无此人");
        return;
    }
    ui->lineEditName->setText(name);
    ui->spinBoxAge->setValue(age);
    ui->lineEditGender->setText(gender);
    ui->lineEditTel->setText(QString::number(tel));
    ui->lineEditBodyCondition->setText(bodyCondition);
    ui->lineEditAddress->setText(address);
    ui->lineEditBirthday->setText(bir);
}

void delStuInfo::on_pushButtonDelete_clicked()
{
    if(ui->lineEditID->text()=="") {
        QMessageBox::about(NULL, "反馈", "学号不能为空");
        return;
    }
    Node<stuInfo> pHead;
    pHead.inputStuInfo();//从文件中读入学生信息
    long long number = ui->lineEditID->text().toLongLong();//从文本框中获取信息
    pHead.deleteStuInfo(number);//在链表中删除学生信息
    pHead.outputStuInfo();//把链表中的学生信息写入文件
    ui->lineEditAddress->clear();//清空文本框
    ui->lineEditBirthday->clear();
    ui->lineEditBodyCondition->clear();
    ui->lineEditGender->clear();
    ui->lineEditID->clear();
    ui->lineEditName->clear();
    ui->lineEditTel->clear();
}

void delStuInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
