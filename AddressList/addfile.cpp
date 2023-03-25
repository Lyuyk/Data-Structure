/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:addfile.cpp
  摘要:生成数据文件源文件
  当前版本号:v2.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "addfile.h"
#include "ui_addfile.h"
#include <QFileDialog>
#include <QDebug>
#include <fstream>
#include <QString>
#include <stdio.h>
#include "student.h"
#include "completebinarytree.h"

addFile::addFile(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addFile)
{
    ui->setupUi(this);
}

addFile::~addFile()
{
    delete ui;
}

void addFile::on_pushButtonCancel_clicked()
{
    this->close();
}

void addFile::on_pushButtonCreateFile_clicked()
{
    int n=ui->spinBoxAmount->text().toInt();
    QString fileName=QFileDialog::getOpenFileName(NULL,"选择写入路径","./*.dat","*.dat");
    student stu;
    ofstream outfile(fileName.toUtf8().data(), ios::out | ios::binary);
    char version[] = "0xA0B0C0";                                           //标志文件是否有效
    outfile.write(version, 8);
    if (!outfile) {QMessageBox::critical(NULL,"错误","文件打开失败"); return;}      //文件打开失败

    clock_t startTime, endTime;
    startTime = clock();                //计时开始
    const unsigned STU_SIZE = sizeof(stu);                                 //结构体大小
    for (int i = 1; i <= n; i++)
    {
            snprintf(stu.name, 21, "%d", i);
            snprintf(stu.sex, 4, "%s", "男");
            snprintf(stu.number, 21, "%d", i+1);
            snprintf(stu.phonenum, 11, "1314806849");
            snprintf(stu.addr, 21, "guangzhou");
            stu.birthday=i;
            outfile.write((char *) &stu, STU_SIZE);
    }
    endTime = clock();                //计时
    double time=(double) (endTime - startTime) / CLOCKS_PER_SEC;
    outfile.close();
    QMessageBox::information(NULL,"提示","数据创建成功\n生成数据时间为"+QString::number(time)+"s");
}
