#include "showcolordialog.h"
#include "ui_showcolordialog.h"


ShowColorDialog::ShowColorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowColorDialog)
{
    ui->setupUi(this);
}

ShowColorDialog::~ShowColorDialog()
{
    delete ui;
}

void ShowColorDialog::on_close_clicked()
{
    this->close();
}

void ShowColorDialog::on_createdColor(Color *color){

    QListWidgetItem *item = new QListWidgetItem(color->colorToString());

    QColor backgroundColor = color->getCode();
    QBrush brush(backgroundColor);
    item->setBackground(brush);
    item->setData(Qt::UserRole, QVariant::fromValue(color));

    ui->colorlist->addItem(item);
}

void ShowColorDialog::on_colorlist_itemClicked(QListWidgetItem *item)
{
    // Отримайте дані з елемента за допомогою встановленої ролі (Qt::UserRole)
    QVariant userData = item->data(Qt::UserRole);

    // Перевірте, чи дані не є нульовими та чи можна їх розпізнати як об'єкт класу Color
    if (userData.canConvert<Color*>()) {
        // Отримайте об'єкт класу Color з QVariant
        Color *selectedColor = userData.value<Color*>();

        // Використовуйте отриманий об'єкт класу Color
        qDebug() << "Selected Color Name: " << selectedColor->getName();
        qDebug() << "Selected Color Code: " << selectedColor->getCode();

        emit chosColor(selectedColor);
    }
}

