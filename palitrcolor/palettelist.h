#ifndef PALETTELIST_H
#define PALETTELIST_H

#include <QDialog>
#include "palitr.h"


#include <QListWidget>
#include <QListWidgetItem>
namespace Ui {
class PaletteList;
}

class PaletteList : public QDialog
{
    Q_OBJECT

public:
    explicit PaletteList(QWidget *parent = nullptr);
    ~PaletteList();

public slots:
    void on_createdPalette(Palitr *pallete);

signals:
    void paletteLoad(Palitr *pallete);

private slots:
    void on_paletteList_itemClicked(QListWidgetItem *item);

private:
    Ui::PaletteList *ui;
};

#endif // PALETTELIST_H
