#ifndef SHOWCOLORDIALOG_H
#define SHOWCOLORDIALOG_H

#include <QDialog>

#include "color.h"


#include <QListWidget>
#include <QListWidgetItem>


namespace Ui {
class ShowColorDialog;
}

class ShowColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowColorDialog(QWidget *parent = nullptr);
    ~ShowColorDialog();

signals:
    void chosColor(Color *color);
public slots:
    void on_createdColor(Color *color);

private slots:
    void on_close_clicked();

    void on_colorlist_itemClicked(QListWidgetItem *item);

private:
    Ui::ShowColorDialog *ui;

    Color *color;
};

#endif // SHOWCOLORDIALOG_H
