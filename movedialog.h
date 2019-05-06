#ifndef MOVEDIALOG_H
#define MOVEDIALOG_H

#include <QDialog>

namespace Ui {
class MoveDialog;
}

class MoveDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MoveDialog(QWidget *parent = nullptr);
    ~MoveDialog();

private slots:
    void on_pushButton_move_clicked();

private:
    Ui::MoveDialog *ui;
};

#endif // MOVEDIALOG_H
