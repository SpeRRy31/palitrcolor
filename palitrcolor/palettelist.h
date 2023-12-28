#ifndef PALETTELIST_H
#define PALETTELIST_H

#include <QDialog>

namespace Ui {
class PaletteList;
}

class PaletteList : public QDialog
{
    Q_OBJECT

public:
    explicit PaletteList(QWidget *parent = nullptr);
    ~PaletteList();

private:
    Ui::PaletteList *ui;
};

#endif // PALETTELIST_H
