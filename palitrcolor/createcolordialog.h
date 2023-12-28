#ifndef CREATECOLORDIALOG_H
#define CREATECOLORDIALOG_H

#include <QDialog>

#include "color.h"

namespace Ui {
class CreateColorDialog;
}

class CreateColorDialog : public QDialog
{
    Q_OBJECT

signals:
    void createdColor(Color *color);

public:
    explicit CreateColorDialog(QWidget *parent = nullptr);
    ~CreateColorDialog();

private slots:
    void on_nextbtn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::CreateColorDialog *ui;
    Color *color;
};

#endif // CREATECOLORDIALOG_H
