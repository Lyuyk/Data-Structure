#ifndef MODIFYSTUINFO_H
#define MODIFYSTUINFO_H

#include <QWidget>

namespace Ui {
class modifyStuInfo;
}

class modifyStuInfo : public QWidget
{
    Q_OBJECT

public:
    explicit modifyStuInfo(QWidget *parent = nullptr);
    ~modifyStuInfo();



private slots:
    void on_pushButtonSearch_clicked();//搜索学生信息

    void on_pushButtonModify_clicked();//修改学生信息


    void on_pushButtonCancel_clicked();

private:
    Ui::modifyStuInfo *ui;
};

#endif // MODIFYSTUINFO_H
