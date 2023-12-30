#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    createColor = new CreateColorDialog;
    showColor = new ShowColorDialog;

    loginDialog = new LoginDialog;

    connect(createColor, &CreateColorDialog::createdColor, this, &MainWindow::on_createdColor);
    connect(createColor, &CreateColorDialog::createdColor, showColor, &ShowColorDialog::on_createdColor);
    connect(showColor, &ShowColorDialog::chosColor, this, &MainWindow::on_createdColor);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCreateColor(){

    createColor->setModal(true);
    createColor->exec();
}



void MainWindow::on_createBtn_1_clicked()
{
    changed = 1;
    openCreateColor();
}
void MainWindow::on_createBtn_2_clicked()
{

    changed = 2;
    openCreateColor();
}
void MainWindow::on_createBtn_3_clicked()
{

    changed = 3;
    openCreateColor();
}
void MainWindow::on_createBtn_4_clicked()
{

    changed = 4;
    openCreateColor();
}

void MainWindow::on_chosBtn_1_clicked()
{
    changed = 1;
    showColor->exec();
}
void MainWindow::on_chosBtn_2_clicked()
{
    changed = 2;
    showColor->exec();
}
void MainWindow::on_chosBtn_3_clicked()
{
    changed = 3;
    showColor->exec();
}
void MainWindow::on_chosBtn_4_clicked()
{
    changed = 4;
    showColor->exec();
}

void MainWindow::on_createdColor(Color *color)
{
    switch(changed){
    case 1:
        ui->colorlb_1->setStyleSheet(QString("background-color: %1;").arg(color->getCode()));
        ui->namelbl_1->setText(color->getName());
        ui->codelbl_1->setText(color->getCode());
        break;
    case 2:
        ui->colorlbl_2->setStyleSheet(QString("background-color: %1;").arg(color->getCode()));
        ui->namelbl_2->setText(color->getName());
        ui->codelbl_2->setText(color->getCode());
        break;
    case 3:
        ui->colorlbl_3->setStyleSheet(QString("background-color: %1;").arg(color->getCode()));
        ui->namelbl_3->setText(color->getName());
        ui->codelbl_3->setText(color->getCode());
        break;
    case 4:
        ui->colorlbl_4->setStyleSheet(QString("background-color: %1;").arg(color->getCode()));
        ui->namelbl_4->setText(color->getName());
        ui->codelbl_4->setText(color->getCode());
        break;
    default:
        QMessageBox::critical(this, "помилка", "cталась технічна помилка спробуйте створити колір");
    }
}


void MainWindow::on_regbtn_clicked()
{
    loginDialog->exec();
}

