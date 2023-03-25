#ifndef ADDSTUINFO_H
#define ADDSTUINFO_H

#include <QWidget>

namespace Ui {
class addStuInfo;
}

class addStuInfo : public QWidget
{
    Q_OBJECT

public:
    explicit addStuInfo(QWidget *parent = nullptr);//初始化学生健康表窗口
    ~addStuInfo();//窗口析构函数


private slots:
    void on_pushButton_clicked();//保存学生健康表信息



    void on_pushButtonCancel_clicked();

private:
    Ui::addStuInfo *ui;
};

#endif // ADDSTUINFO_H
