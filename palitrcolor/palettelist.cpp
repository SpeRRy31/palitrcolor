#include "palettelist.h"
#include "ui_palettelist.h"

PaletteList::PaletteList(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PaletteList)
{
    ui->setupUi(this);
}

PaletteList::~PaletteList()
{
    delete ui;
}

void PaletteList::on_createdPalette(Palitr *pallete)
{
    QListWidgetItem *item = new QListWidgetItem(pallete->getName());

    item->setData(Qt::UserRole, QVariant::fromValue(pallete));

    ui->paletteList->addItem(item);
}

void PaletteList::on_paletteList_itemClicked(QListWidgetItem *item)
{
    QVariant userData = item->data(Qt::UserRole);

    // Перевірте, чи дані не є нульовими та чи можна їх розпізнати як об'єкт класу Color
    if (userData.canConvert<Palitr*>()) {
        // Отримайте об'єкт класу Color з QVariant
        Palitr *chosPalette = userData.value<Palitr*>();


        emit paletteLoad(chosPalette);
    }
}

