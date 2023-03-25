/*====================================================

  Copyright(C) 2021-2022 Lyuyk
  All rights reserved

  文件名称:main.cpp
  摘要:主函数源文件
  当前版本号:v1.0
  版本历史信息：无

  created by Lyuyk at 12/29/2021

=====================================================*/
#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("statisticedFile.txt");
    file.open(QIODevice::WriteOnly);
    file.close();
    MainWindow w;
    w.show();
    return a.exec();
}
