/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:adminwidget.cpp
  摘要:管理员登录主界面源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "adminwidget.h"
#include "ui_adminwidget.h"
#include "adminmenuwidget.h"
#include <QLabel>
#include <QMessageBox>

AdminWidget::AdminWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminWidget)
{
    ui->setupUi(this);
}

AdminWidget::~AdminWidget()
{
    delete ui;
}


void AdminWidget::on_pushButton_login_clicked()
{
    adminMenuWidget *adMenu=new adminMenuWidget();//创建管理员界面
    adMenu->setWindowTitle("学生健康表管理系统");
    adMenu->setWindowIcon(QIcon(":/images/logo.ico"));
    if(ui->lineEdit_account->text().trimmed()==tr("admin")&&ui->lineEdit_pwd->text().trimmed()==tr("admin123456"))
    {
        adMenu->show();//密码正确则打开管理员界面
        this->close();
    }
    else
    {
        QMessageBox::warning(this,tr("警告"),tr("用户名或密码错误"),QMessageBox::Yes);//密码错误则清空
        ui->lineEdit_account->clear();
        ui->lineEdit_pwd->clear();
        ui->lineEdit_account->setFocus();
    }
}
