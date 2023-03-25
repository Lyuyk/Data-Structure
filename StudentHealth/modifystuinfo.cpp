/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:modifystuinfo.cpp
  摘要:修改学生信息窗口源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "modifystuinfo.h"
#include "ui_modifystuinfo.h"
#include <QMessageBox>
#include <QFile>
#include "stuinfo.h"
#include "node.h"

modifyStuInfo::modifyStuInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::modifyStuInfo)
{
    ui->setupUi(this);
}

modifyStuInfo::~modifyStuInfo()
{
    delete ui;
}

void modifyStuInfo::on_pushButtonSearch_clicked()
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
    ui->comboBox->setItemText(0,gender);
    ui->lineEditTel->setText(QString::number(tel));
    ui->lineEditBodyCondition->setText(bodyCondition);
    ui->lineEditAddress->setText(address);
    ui->lineEditBirthday->setText(bir);
}

void modifyStuInfo::on_pushButtonModify_clicked()
{
    if(ui->lineEditName->text()==""||ui->lineEditID->text()==""||ui->spinBoxAge->text()==""||ui->lineEditTel->text()==""
            ||ui->lineEditBirthday->text()==""||ui->lineEditAddress->text()==""||ui->lineEditBodyCondition->text()=="")
    {
        QMessageBox::about(0,"错误","存在空项");
        return;
    }

    Node<stuInfo> pHead;
    pHead.inputStuInfo();//读取学生信息到链表
    QString name=ui->lineEditName->text().trimmed();
    long long number = ui->lineEditID->text().toLongLong();
    int age = ui->spinBoxAge->text().toInt();
    QString gender = ui->comboBox->currentIndex()==0 ? "男" : "女";
    long long tel = ui->lineEditTel->text().toLongLong();
    QString bir = ui->lineEditBirthday->text().trimmed();
    QString address = ui->lineEditAddress->text().trimmed();
    QString bodyCondition = ui->lineEditBodyCondition->text().trimmed();

    pHead.modifyStuInfo(name,number,age,gender,address,bir,tel,bodyCondition);//修改学生信息操作
    pHead.outputStuInfo();//将修改后的数据输出回文件中

    ui->lineEditName->clear();
    ui->lineEditAddress->clear();
    ui->lineEditBirthday->clear();
    ui->lineEditBodyCondition->clear();
    ui->lineEditID->clear();
    ui->lineEditTel->clear();
}


void modifyStuInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
