/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:adminmenuwidget.cpp
  摘要:系统菜单功能主界面源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "adminmenuwidget.h"
#include "ui_adminmenuwidget.h"
#include "addstuinfo.h"
#include "delstuinfo.h"
#include "insertstuinfo.h"
#include "modifystuinfo.h"
#include "searchstuinfo.h"
#include "sortstuinfo.h"

adminMenuWidget::adminMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminMenuWidget)
{
    ui->setupUi(this);
}

adminMenuWidget::~adminMenuWidget()
{
    delete ui;
}

void adminMenuWidget::on_pushButton_addStu_clicked()
{
    addStuInfo *widget=new addStuInfo;
    widget->show();
}

void adminMenuWidget::on_pushButton_insertStu_clicked()
{
    insertStuInfo *widget=new insertStuInfo;
    widget->show();
}

void adminMenuWidget::on_pushButton_searchStu_clicked()
{
    searchStuInfo *widget=new searchStuInfo;
    widget->show();
}

void adminMenuWidget::on_pushButton_modifyStu_clicked()
{
    modifyStuInfo *widget=new modifyStuInfo;
    widget->show();
}

void adminMenuWidget::on_pushButton_sortStu_clicked()
{
    sortStuInfo *widget=new sortStuInfo;
    widget->show();
}

void adminMenuWidget::on_pushButton_deleteStu_clicked()
{
    delStuInfo *widget=new delStuInfo;
    widget->show();
}

void adminMenuWidget::on_pushButton_clicked()
{
    this->close();
}
