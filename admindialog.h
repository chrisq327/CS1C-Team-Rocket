#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include "adddialog.h"
#include "shape.h"

namespace Ui {
class AdminDialog;
}

namespace adminFunc {
    void addShape(Shape *);
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);

    ~AdminDialog();

private slots:
    void on_pushButton_Logout_clicked();

    void on_pushButton_addShape_clicked();

private:
    AddDialog *addDialog;
    Ui::AdminDialog *ui;

protected:
    void paintEvent(QPaintEvent *event);

};


#endif // ADMINDIALOG_H

