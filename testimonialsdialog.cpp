#include "testimonialsdialog.h"
#include "ui_testimonialsdialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <parser.h>

TestimonialsDialog::TestimonialsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestimonialsDialog)
{
    ui->setupUi(this);

   QFile inFile("testimonial.txt");
   QTextStream in(&inFile);
   inFile.open(QIODevice::ReadOnly);
   ui->textBrowser_testimonials->setText(in.readAll());

   QLabel *label = new QLabel;
   label->setText("testing");
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
