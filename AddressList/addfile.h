#ifndef ADDFILE_H
#define ADDFILE_H

#include <QWidget>

namespace Ui {
class addFile;
}

class addFile : public QWidget
{
    Q_OBJECT

public:
    explicit addFile(QWidget *parent = nullptr);
    ~addFile();

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonCreateFile_clicked();

private:
    Ui::addFile *ui;
};

#endif // ADDFILE_H
