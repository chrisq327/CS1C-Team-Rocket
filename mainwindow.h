#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "guestdialog.h"
#include "admindialog.h"
#include "contactdialog.h"
#include "vector.h"
#include "shape.h"

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

    void on_pushButton_contact_clicked();

private:
    GuestDialog *guestDialog;
    AdminDialog *adminDialog;
    ContactDialog *contactDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
