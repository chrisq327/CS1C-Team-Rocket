#ifndef CONTACTDIALOG_H
#define CONTACTDIALOG_H

#include <QDialog>

/** Class for contact window */

namespace Ui {
class ContactDialog;
}

class ContactDialog : public QDialog
{
    Q_OBJECT

public:
    /** Constructor for widget */
    explicit ContactDialog(QWidget *parent = nullptr);

    /** Destructor for widget */
    ~ContactDialog();

private slots:
    /** pushButton function to submit contact message */
    void on_pushButton_submit_clicked();

private:
    Ui::ContactDialog *ui;
};

#endif // CONTACTDIALOG_H
