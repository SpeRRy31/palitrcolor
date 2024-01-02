#ifndef SHOWCOLORDIALOG_H
#define SHOWCOLORDIALOG_H

#include <QDialog>

#include "color.h"


#include <QListWidget>
#include <QListWidgetItem>


#include <QVBoxLayout>
#include <QSqlTableModel>
#include "sqllitedbmanager.h"

class QSqlTableModel;
class DBManager;

namespace Ui {
class ShowColorDialog;
}

class ShowColorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowColorDialog(DBManager* dbManager, QWidget *parent = nullptr);
    ~ShowColorDialog();

signals:
    void chosColor(Color *color, int id);


private slots:

    void on_close_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::ShowColorDialog *ui;

    Color *color;


    DBManager* dbManager;
    QSqlTableModel* model;
    Color* getColorFromRow(int row);


    void setupModel(const QString& tableName, const QStringList& headers);
    void createUI();
};

#endif // SHOWCOLORDIALOG_H
