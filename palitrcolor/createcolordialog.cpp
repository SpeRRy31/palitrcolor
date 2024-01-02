#include "createcolordialog.h"
#include "ui_createcolordialog.h"

#include <QMessageBox>
#include <QColorDialog>

#include <QDebug>

CreateColorDialog::CreateColorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateColorDialog)
{
    ui->setupUi(this);
}

CreateColorDialog::~CreateColorDialog()
{
    delete ui;
}

void CreateColorDialog::on_nextbtn_clicked()
{
    if (!ui->colorname_edit->text().isEmpty()) {
        QColorDialog colorDialog;
        colorDialog.exec();
        color = new Color(ui->colorname_edit->text(),  colorDialog.selectedColor().name());
        emit createdColor(color, -1);  // -1 означає, що ID ще не визначено
        this->close();
    } else {
        QMessageBox::critical(this, "помилка", "Введіть ім'я кольору, щоб вибрати #rrggbb");
    }
}


void CreateColorDialog::on_cancel_btn_clicked()
{
    this->close();
}

