#ifndef PRINTCODEWIDGET_H
#define PRINTCODEWIDGET_H

#include <QWidget>
#include "huffmanTree.h"

namespace Ui {
class printCodeWidget;
}

class printCodeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit printCodeWidget(QWidget *parent = nullptr);
    ~printCodeWidget();

private slots:
    void on_pushButtonPrintCode_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::printCodeWidget *ui;
    HuffmanTree myTree;
};

#endif // PRINTCODEWIDGET_H
