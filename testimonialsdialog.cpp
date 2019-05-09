#include "testimonialsdialog.h"
#include "ui_testimonialsdialog.h"
#include <QMessageBox>
#include <parser.h>

TestimonialsDialog::TestimonialsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestimonialsDialog)
{
    ui->setupUi(this);
}

TestimonialsDialog::~TestimonialsDialog()
{
    delete ui;
}

void TestimonialsDialog::on_pushButton_submit_clicked()
{
    QMessageBox::information(this, "Testimonial", "Thank you for your feedback!");

    QFile outFile("testimonial.txt");
    outFile.open(QIODevice::Append);
    QTextStream stream(&outFile);
    stream << ui->textEdit->toPlainText();
    stream << endl << endl;
    outFile.close();

    this->close();
    QWidget *parent = this->parentWidget();
    parent->show();
}
