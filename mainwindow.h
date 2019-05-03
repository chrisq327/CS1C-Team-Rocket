#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "guestdialog.h"
#include "admindialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Login_clicked();

private:
    GuestDialog *guestDialog;
    AdminDialog *adminDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
