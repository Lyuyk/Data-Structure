/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:insertstuinfo.cpp
  摘要:按下标插入学生信息窗口
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "insertstuinfo.h"
#include "ui_insertstuinfo.h"
#include "stuinfo.h"
#include "node.h"
#include <QDebug>

insertStuInfo::insertStuInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertStuInfo)
{
    ui->setupUi(this);
    ui->spinBoxInsertIndex->setDisabled(1);//一开始没获取下标范围前不允许选择下标
}

insertStuInfo::~insertStuInfo()
{
    delete ui;

}

void insertStuInfo::on_pushButtonInsert_clicked()
{
    Node<stuInfo> pHead;
    pHead.inputStuInfo();

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

    int nowIndex=ui->spinBoxInsertIndex->text().toInt();//获取要插入的下标
    int maxIndex=ui->labelInsertIndex->text().toInt();//获取允许插入的最大下标
    if(nowIndex<0||nowIndex>maxIndex)
    {
        QMessageBox::warning(0,"错误","下标值超出范围无效");
        return;
    }

    bool pd=pHead.addStuInfoAtIndex(nowIndex,name,number,age,gender,address,bir,tel,bodyCondition);//将信息插入链表中
    qDebug()<<"addStuInfoAtIndex(insertStuInfo)"<<"\n";
    pHead.outputStuInfo();//将链表数据写回文件中

    if(pd==true)
    {
        ui->lineEditAddress->clear();
        ui->lineEditBirthday->clear();
        ui->lineEditBodyCondition->clear();
        ui->lineEditID->clear();
        ui->lineEditName->clear();
        ui->lineEditTel->clear();
    }

}

void insertStuInfo::on_pushButtonGetMaxIndex_clicked()
{
    Node<stuInfo> pHead;
    pHead.inputStuInfo();//读取学生信息文件
    int maxIndex=pHead.stuInfoIndex();//获取最大插入下标
    ui->labelInsertIndex->setText(QString::number(maxIndex));//更新并显示下标范围
    ui->spinBoxInsertIndex->setEnabled(1);//此时允许选择下标范围
}

void insertStuInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
