#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username == "guest" && password == "guest")
    {
        QMessageBox::information(this, "Login", "Username and password are correct");
        hide();
        guestDialog = new GuestDialog(this);
        guestDialog->show();
    }
    else if(username == "admin" && password == "admin")
    {
        QMessageBox::information(this, "Login", "Username and password are correct");
        hide();
        adminDialog = new AdminDialog(this);
        adminDialog->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username and password are incorrect");
    }
}

