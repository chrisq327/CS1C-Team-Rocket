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

/** Class for guest rendering window */

namespace Ui {
class GuestDialog;
}

class GuestDialog : public QDialog
{
    Q_OBJECT

public:
    /** Constructor for widget */
    explicit GuestDialog(QWidget *parent = nullptr);

    /** Destructor for widget */
    ~GuestDialog();

private slots:
    /** pushButton function to logout of user */
    void on_pushButton_Logout_clicked();

    /** pushButton function to proceed to testimonial window */
    void on_pushButton_testimonials_clicked();

private:
    TestimonialsDialog *testimonialsDialog;
    Ui::GuestDialog *ui;

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GUESTDIALOG_H

