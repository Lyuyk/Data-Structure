/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:addstuinfo.cpp
  摘要:添加学生信息源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/
#include "addstuinfo.h"
#include "ui_addstuinfo.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

addStuInfo::addStuInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStuInfo)
{
    ui->setupUi(this);
}

addStuInfo::~addStuInfo()
{
    delete ui;
}

void addStuInfo::on_pushButton_clicked()
{
    ui->lineEditID->setFocus();

    //从文本框获取信息
    QString name=ui->lineEditName->text().trimmed();
    long long number = ui->lineEditID->text().toLongLong();
    int age = ui->spinBoxAge->text().toInt();
    QString gender = ui->comboBox->currentIndex()==0 ? "男" : "女";
    long long tel = ui->lineEditTel->text().toLongLong();
    QString bir = ui->lineEditBirthday->text().trimmed();
    QString address = ui->lineEditAddress->text().trimmed();
    QString bodyCondition = ui->lineEditBodyCondition->text().trimmed();

    if(ui->lineEditName->text()==""||ui->lineEditID->text()==""||ui->spinBoxAge->text()==""||ui->lineEditTel->text()==""
            ||ui->lineEditBirthday->text()==""||ui->lineEditAddress->text()==""||ui->lineEditBodyCondition->text()=="")
    {
        QMessageBox::about(0,"错误","存在空项");
        return;
    }

    QFile file("stuinfo.txt");//文件指针
    file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);//打开文件
    if(!file.isOpen()) {
        QMessageBox::about(0, "反馈", "数据文件打开失败");
        return;
    }
    QTextStream out(&file);//写入
    out<<name<<" "<<number<<" "<<age<<" "<<gender<<" "<<tel<<" "<<bir<<" "<<address<<" "<<bodyCondition<<"\n";
    qDebug()<<name<<" "<<number<<" "<<age<<" "<<gender<<" "<<tel<<" "<<bir<<" "<<address<<" "<<bodyCondition<<"\n";
    file.close();//关闭
    QMessageBox::about(0,"反馈","成功保存");

    //清除文本框信息
    ui->lineEditName->clear();
    ui->lineEditAddress->clear();
    ui->lineEditBirthday->clear();
    ui->lineEditBodyCondition->clear();
    ui->lineEditID->clear();
    ui->lineEditTel->clear();
}


void addStuInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
