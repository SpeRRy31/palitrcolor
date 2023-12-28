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
