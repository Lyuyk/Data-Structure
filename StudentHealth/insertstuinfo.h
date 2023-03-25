#ifndef INSERTSTUINFO_H
#define INSERTSTUINFO_H

#include <QWidget>

namespace Ui {
class insertStuInfo;
}

class insertStuInfo : public QWidget
{
    Q_OBJECT

public:
    explicit insertStuInfo(QWidget *parent = nullptr);
    ~insertStuInfo();



private slots:

    void on_pushButtonInsert_clicked();//插入学生信息操作

    void on_pushButtonGetMaxIndex_clicked();//获取最大链表下标操作

    void on_pushButtonCancel_clicked();

private:
    Ui::insertStuInfo *ui;
};

#endif // INSERTSTUINFO_H
