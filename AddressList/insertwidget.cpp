/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:insertwidget.cpp
  摘要:插入学生信息源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "insertwidget.h"
#include "ui_insertwidget.h"
#include "completebinarytree.h"
#include "student.h"

insertWidget::insertWidget(completeBinaryTree<student> *btStu, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertWidget),
    binaryTreeFile(btStu)
{
    ui->setupUi(this);
    QRegExp rxNumber("\\d+$");
    QRegExp rxChar("[^0-9]+$");
    QRegExpValidator *numberValidator=new QRegExpValidator(rxNumber);
    QRegExpValidator *charValidator=new QRegExpValidator(rxChar);
    //设置合法输入
    ui->lineEditName->setValidator(charValidator);
    ui->lineEditTel->setValidator(numberValidator);
    ui->lineEditID->setValidator(numberValidator);
    ui->lineEditAddress->setValidator(charValidator);
}

insertWidget::~insertWidget()
{
    delete ui;
}

void insertWidget::on_pushButtonInsert_clicked()
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
        student stu;
        strcpy_s(stu.name, ui->lineEditName->text().toUtf8().data());
        strcpy_s(stu.number, ui->lineEditID->text().toUtf8().data());
        strcpy_s(stu.sex, ui->comboBoxSex->currentText().toUtf8().data());
        QString strYear = ui->dateEditBirth->sectionText(QDateEdit::YearSection);
        QString strMonth = ui->dateEditBirth->sectionText(QDateEdit::MonthSection);
        QString strDay = ui->dateEditBirth->sectionText(QDateEdit::DaySection);
        stu.birthday = strYear.toInt();
        stu.birthday = (stu.birthday << 4) + strMonth.toInt();
        stu.birthday = (stu.birthday << 5) + strDay.toInt();
        strcpy_s(stu.phonenum, ui->lineEditTel->text().toUtf8().data());
        strcpy_s(stu.addr, ui->lineEditAddress->text().toUtf8().data());

        binaryTreeFile->insert(stu);
        QMessageBox::information(NULL,"提示","插入成功");
    }
}

void insertWidget::on_pushButtonCancel_clicked()
{
    this->close();
}
