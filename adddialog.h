#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "shape.h"

/** Class for add diolog window
*
*/

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    /** Constructor for widget */
    explicit AddDialog(QWidget *parent = nullptr);

    /** Destructor for widget */
    ~AddDialog();


private slots:
    /** Function to add a shape to rendering window */
    void on_pushButton_addShape_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
