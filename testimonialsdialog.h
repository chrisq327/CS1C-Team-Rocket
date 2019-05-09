#ifndef TESTIMONIALSDIALOG_H
#define TESTIMONIALSDIALOG_H

#include <QDialog>
#include <fstream>

/** Class for testimonial window */

namespace Ui {
class TestimonialsDialog;
}

class TestimonialsDialog : public QDialog
{
    Q_OBJECT

public:
    /** Constructor for widget */
    explicit TestimonialsDialog(QWidget *parent = nullptr);

    /** Destructor for widget */
    ~TestimonialsDialog();

private slots:
    /** pushButton function to submit testimonial and save to a file */
    void on_pushButton_submit_clicked();

private:
    Ui::TestimonialsDialog *ui;
};

#endif // TESTIMONIALSDIALOG_H
