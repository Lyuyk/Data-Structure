/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:main.cpp
  摘要:程序入口主函数源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 10/16/2021

=====================================================*/

#include "adminwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AdminWidget w;
    w.show();
    return a.exec();
}
