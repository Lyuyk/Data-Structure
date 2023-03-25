#ifndef PRINTTREEWIDGET_H
#define PRINTTREEWIDGET_H

#include <QWidget>
#include "huffmanTree.h"

namespace Ui {
class printTreeWidget;
}

class printTreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit printTreeWidget(QWidget *parent = nullptr);
    ~printTreeWidget();

private slots:
    void on_pushButtonPrintTree_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::printTreeWidget *ui;
    HuffmanTree myTree;
};

#endif // PRINTTREEWIDGET_H
