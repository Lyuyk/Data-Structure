#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Heap.h"
#include "huffmanTree.h"
#include "huffmannode.h"
#include "initialwidget.h"

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
    void on_pushButton_initialize_clicked();

    void on_pushButtonEncode_clicked();

    void on_pushButtonDecode_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonPrintTree_clicked();

    void on_pushButtonPrintCode_clicked();

private:
    Ui::MainWindow *ui;
    HuffmanTree myTree;

};
#endif // MAINWINDOW_H
