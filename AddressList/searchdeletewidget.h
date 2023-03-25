#ifndef SEARCHDELETEWIDGET_H
#define SEARCHDELETEWIDGET_H

#include <QWidget>
#include "student.h"
#include "completebinarytree.h"

namespace Ui {
class searchDeleteWidget;
}

class searchDeleteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit searchDeleteWidget(completeBinaryTree<student> *btStu, QWidget *parent = nullptr);
    ~searchDeleteWidget();

private slots:
    void on_pushButtonSearch_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonDel_clicked();

private:
    Ui::searchDeleteWidget *ui;
    completeBinaryTree<student> *binaryTreeFile;
    binTreeNode<student> *tempStu;
};

#endif // SEARCHDELETEWIDGET_H
