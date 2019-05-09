#ifndef GUESTDIALOG_H
#define GUESTDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include "shape.h"
#include "line.h"
#include "nonfillableshape.h"
#include "testimonialsdialog.h"

namespace Ui {
class GuestDialog;
}

class GuestDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GuestDialog(QWidget *parent = nullptr);
    ~GuestDialog();

private slots:
    void on_pushButton_Logout_clicked();

    void on_pushButton_testimonials_clicked();

private:
    TestimonialsDialog *testimonialsDialog;
    Ui::GuestDialog *ui;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GUESTDIALOG_H

