#ifndef SHOWWIDGET_H
#define SHOWWIDGET_H

#include <QWidget>
#include "completebinarytree.h"
#include "student.h"

namespace Ui {
class showWidget;
}

class showWidget : public QWidget
{
    Q_OBJECT

public:
    explicit showWidget(completeBinaryTree<student> *btStu, QWidget *parent = nullptr);
    ~showWidget();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonYoungestSearch_clicked();

private:
    Ui::showWidget *ui;
    completeBinaryTree<student> *binaryTreeFile;
};

#endif // SHOWWIDGET_H
