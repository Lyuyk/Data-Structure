/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:sortstuinfo.cpp
  摘要:学生信息排序窗口源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "sortstuinfo.h"
#include "ui_sortstuinfo.h"
#include "stuinfo.h"
#include "node.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

sortStuInfo::sortStuInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sortStuInfo)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(8);//设置表格列数为8
    QStringList headerLabels;
    headerLabels<<tr("姓名")<<tr("学号")<<tr("年龄")<<tr("性别")<<tr("电话")<<tr("生日")<<tr("地址")<<tr("健康状况");
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);//设置表格头
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setRowCount(1);//设置行数为1
}

sortStuInfo::~sortStuInfo()
{
    delete ui;
}

void sortStuInfo::on_pushButton_clicked()
{
    Node<stuInfo> pHead;
    pHead.inputStuInfo();//读取数据

    pHead.sortStuInfoByID();//链表排序
    qDebug()<<"sortStuInfoByID(sortStuInfo)\n";

    pHead.outputStuInfo();//将链表排序后的数据输出到文件

    QFile file("stuinfo.txt");//从文件中读入链表排序后的数据
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream inp(&file);
    if(!file.isOpen())
    {
        QMessageBox::about(0,"反馈","数据文件打开失败");
        return;
    }

    QVector<stuInfo> allStuInfo;


    while(!inp.atEnd()) {
        QString name;//姓名
        long long number;//学号
        int age;//年龄
        QString gender;//性别
        QString address;//地址
        long long tel; //电话号码 1XXXXXXXXXX
        QString bir;//生日
        QString bodyCondition;//学生成绩（0-100）
        inp>>name>>number>>age>>gender>>tel>>bir>>address>>bodyCondition;
        allStuInfo.push_back(stuInfo(name,number,age,gender,address,bir,tel,bodyCondition));//压入动态数组中
    }
    allStuInfo.pop_back();
    file.close();


    ui->tableWidget->setRowCount(allStuInfo.size());//设置行数
    for(int i=0;i<allStuInfo.size();i++)//显示获取的数据到表格
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(allStuInfo[i].getName()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(allStuInfo[i].getID())));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(allStuInfo[i].getAge())));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(allStuInfo[i].getGender()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(allStuInfo[i].getTel())));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(allStuInfo[i].getBirthday()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(allStuInfo[i].getAddress()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(allStuInfo[i].getBodyCondition()));
    }

}


void sortStuInfo::on_pushButtonCancel_clicked()
{
    this->close();
}
