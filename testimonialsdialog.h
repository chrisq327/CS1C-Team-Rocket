#ifndef TESTIMONIALSDIALOG_H
#define TESTIMONIALSDIALOG_H

#include <QDialog>
#include <fstream>

namespace Ui {
class TestimonialsDialog;
}

class TestimonialsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TestimonialsDialog(QWidget *parent = nullptr);
    ~TestimonialsDialog();

private slots:
    void on_pushButton_submit_clicked();

private:
    Ui::TestimonialsDialog *ui;
};

#endif // TESTIMONIALSDIALOG_H
