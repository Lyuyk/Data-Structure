#ifndef INITIALWIDGET_H
#define INITIALWIDGET_H

#include <QWidget>
#include "huffmanTree.h"

namespace Ui {
class initialWidget;
}

class initialWidget : public QWidget
{
    Q_OBJECT

public:
    explicit initialWidget(QWidget *parent = nullptr);
    ~initialWidget();

private slots:
    void on_pushButtonExit_clicked();//退出按钮

    void on_pushButtonInitial_clicked();//初始化功能（读取待统计文件并输出统计数据到选定文件中）

    void on_pushButtonChooseFile_clicked();//选择文件

private:
    Ui::initialWidget *ui;
    HuffmanTree myTree;
};

#endif // INITIALWIDGET_H
