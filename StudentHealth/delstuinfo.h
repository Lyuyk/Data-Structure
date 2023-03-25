#ifndef DELSTUINFO_H
#define DELSTUINFO_H

#include <QWidget>

namespace Ui {
class delStuInfo;
}

class delStuInfo : public QWidget
{
    Q_OBJECT

public:
    explicit delStuInfo(QWidget *parent = nullptr);
    ~delStuInfo();


private slots:
    void on_pushButtonSearch_clicked();//搜索学生信息操作

    void on_pushButtonDelete_clicked();//删除学生信息操作

    void on_pushButtonCancel_clicked();

private:
    Ui::delStuInfo *ui;
};

#endif // DELSTUINFO_H
