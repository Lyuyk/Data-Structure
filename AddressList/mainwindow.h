#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "student.h"
#include "linkedlist.h"
#include "queue.h"
#include "stack.h"
#include "completebinarytree.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_readFromFile_clicked();

    void on_pushButton_writeToFile_clicked();

    void on_pushButton_buildStuData_clicked();

private:
    Ui::MainWindow *ui;
    completeBinaryTree<student> *binaryTreeStruct;
};
#endif // MAINWINDOW_H
