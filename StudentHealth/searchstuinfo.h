#ifndef SEARCHSTUINFO_H
#define SEARCHSTUINFO_H

#include <QWidget>
#include <QFile>
#include <QVector>
#include <QMessageBox>
#include "stuinfo.h"
#include "node.h"

namespace Ui {
class searchStuInfo;
}

class searchStuInfo : public QWidget
{
    Q_OBJECT

public:
    explicit searchStuInfo(QWidget *parent = nullptr);//构造函数
    ~searchStuInfo();//析构函数



private slots:
    void on_pushButtonSearch_clicked();//搜索学生信息


    void on_pushButtonCancel_clicked();

private:
    Ui::searchStuInfo *ui;
};

#endif // SEARCHSTUINFO_H
