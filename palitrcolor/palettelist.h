#ifndef PALETTELIST_H
#define PALETTELIST_H

#include <QDialog>
#include "palitr.h"
#include "user.h"

#include <QVBoxLayout>
#include <QSqlTableModel>
#include "sqllitedbmanager.h"

class QSqlTableModel;
class DBManager;

namespace Ui {
class PaletteList;
}

class PaletteList : public QDialog
{
    Q_OBJECT

public:
    explicit PaletteList(DBManager* dbManager, QWidget *parent = nullptr);
    ~PaletteList();


public slots:
    void on_login(User *user);
    void on_palitrAdd();

signals:
    void palitrSelected(Palitr *palitr);

private slots:
    void on_close_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::PaletteList *ui;

    DBManager* dbManager;
    QSqlTableModel* model;

    Palitr *selectedPalitr;

    void setFilter(User *user);

    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();
};

#endif // PALETTELIST_H
