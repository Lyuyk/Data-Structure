#ifndef CREATEWIDGET_H
#define CREATEWIDGET_H

#include <QWidget>
#include "student.h"
#include "completebinarytree.h"

namespace Ui {
class createWidget;
}

class createWidget : public QWidget
{
    Q_OBJECT

public:
    explicit createWidget(completeBinaryTree<student> *btStu,QWidget *parent = nullptr);
    ~createWidget();

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonDel_clicked();

    void on_pushButtonCreate_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::createWidget *ui;
    completeBinaryTree<student> *binaryTreeFile;
};

#endif // CREATEWIDGET_H
