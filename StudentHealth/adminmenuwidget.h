#ifndef ADMINMENUWIDGET_H
#define ADMINMENUWIDGET_H

#include <QWidget>

namespace Ui {
class adminMenuWidget;
}

class adminMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit adminMenuWidget(QWidget *parent = nullptr);
    ~adminMenuWidget();



private slots:
    void on_pushButton_addStu_clicked();//打开增加学生信息窗口

    void on_pushButton_insertStu_clicked();//打开插入学生信息窗口

    void on_pushButton_searchStu_clicked();//打开搜索学生信息窗口

    void on_pushButton_modifyStu_clicked();//打开修改学生信息窗口

    void on_pushButton_sortStu_clicked();//打开学生信息排序窗口

    void on_pushButton_deleteStu_clicked();//打开删除学生信息窗口

    void on_pushButton_clicked();//退出程序按钮

private:
    Ui::adminMenuWidget *ui;
};

#endif // ADMINMENUWIDGET_H
