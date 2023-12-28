#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "color.h"
#include "createcolordialog.h"
#include "showcolordialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
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

    void on_createdColor(Color *color);

private:
    Ui::MainWindow *ui;

    Color *color;

    CreateColorDialog *createColor;
    ShowColorDialog *showColor;

    void openCreateColor();
    void openShowColor();

    int changed;
};
#endif // MAINWINDOW_H
