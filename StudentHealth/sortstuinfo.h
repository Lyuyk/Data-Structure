#ifndef SORTSTUINFO_H
#define SORTSTUINFO_H

#include <QWidget>
#include <QVector>
#include <QButtonGroup>
#include "stuinfo.h"
#include "node.h"

namespace Ui {
class sortStuInfo;
}

class sortStuInfo : public QWidget
{
    Q_OBJECT

public:
    explicit sortStuInfo(QWidget *parent = nullptr);
    ~sortStuInfo();



private slots:
    void on_pushButton_clicked();//排序功能


    void on_pushButtonCancel_clicked();

private:
    Ui::sortStuInfo *ui;

};

#endif // SORTSTUINFO_H
