#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "guestdialog.h"
#include "admindialog.h"
#include "contactdialog.h"
#include "vector.h"
#include "shape.h"

/** MainWindow class */

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /** Constructor for widget */
    explicit MainWindow(QWidget *parent = nullptr);

    /** Destructor for widget */
    ~MainWindow();

private slots:
    /** pushButton function to login to program */
    void on_pushButton_Login_clicked();

    /** pushButton function to proceed to contact window */
    void on_pushButton_contact_clicked();

private:
    GuestDialog *guestDialog;
    AdminDialog *adminDialog;
    ContactDialog *contactDialog;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
