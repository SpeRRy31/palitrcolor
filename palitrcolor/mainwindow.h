#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "color.h"
#include "createcolordialog.h"
#include "showcolordialog.h"
#include "user.h"
#include "palettelist.h"
#include "aboutdialog.h"
#include "logindialog.h"
#include "palitr.h"

#include <QSqlTableModel>
class QSqlTableModel;
class DBManager;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DBManager* dbManager, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_createBtn_1_clicked();
    void on_createBtn_2_clicked();
    void on_createBtn_3_clicked();
    void on_createBtn_4_clicked();

    void on_chosBtn_1_clicked();
    void on_chosBtn_2_clicked();
    void on_chosBtn_3_clicked();
    void on_chosBtn_4_clicked();

    void on_createdColor(Color *color, int colorID);

    void on_regbtn_clicked();
    void on_login(User* user);


    void on_pushButton_clicked();

    void on_loadbtn_clicked();

    void on_savebtn_clicked();

    void on_pallete_load(Palitr *pallete);

    void on_pushButton_2_clicked();

signals:
    void createdPallete(Palitr *pallete);
    void userSend(User *user);

private:
    Ui::MainWindow *ui;

    Color *color;

    bool login = false;

    User *current_user;

    Palitr *palette;

    Color colorArray[4];

    CreateColorDialog *createColor;
    ShowColorDialog *showColor;
    PaletteList *paletteList;
    AboutDialog *about;
    LoginDialog *loginDialog;

    void openCreateColor();

    int changed;


    DBManager* dbManager;

};
#endif // MAINWINDOW_H
