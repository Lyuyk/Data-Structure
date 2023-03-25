#ifndef INSERTWIDGET_H
#define INSERTWIDGET_H

#include <QWidget>
#include "student.h"
#include "completebinarytree.h"

namespace Ui {
class insertWidget;
}

class insertWidget : public QWidget
{
    Q_OBJECT

public:
    explicit insertWidget(completeBinaryTree<student> *btStu, QWidget *parent = nullptr);
    ~insertWidget();

private slots:
    void on_pushButtonInsert_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::insertWidget *ui;
    completeBinaryTree<student> *binaryTreeFile;
};

#endif // INSERTWIDGET_H
