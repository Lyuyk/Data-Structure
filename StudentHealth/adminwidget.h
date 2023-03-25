#ifndef ADMINWIDGET_H
#define ADMINWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class AdminWidget; }
QT_END_NAMESPACE

class AdminWidget : public QMainWindow
{
    Q_OBJECT

public:
    AdminWidget(QWidget *parent = nullptr);
    ~AdminWidget();

private slots:
    void on_pushButton_login_clicked();//登录操作

private:
    Ui::AdminWidget *ui;
};
#endif // ADMINWIDGET_H
