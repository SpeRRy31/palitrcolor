#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColor>
#include <QMessageBox>
#include <QDebug>


#include "dbmanager.h"
#include "sqllitedbmanager.h"

MainWindow::MainWindow(DBManager* dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), dbManager(dbManager)
{
    ui->setupUi(this);


    createColor = new CreateColorDialog;
    showColor = new ShowColorDialog;
    about = new AboutDialog;
    loginDialog = new LoginDialog;
    paletteList = new PaletteList;

    connect(createColor, &CreateColorDialog::createdColor, this, &MainWindow::on_createdColor);
    connect(createColor, &CreateColorDialog::createdColor, showColor, &ShowColorDialog::on_createdColor);
    connect(showColor, &ShowColorDialog::chosColor, this, &MainWindow::on_createdColor);
    connect(this, &MainWindow::createdPallete, paletteList, &PaletteList::on_createdPalette);
    connect(loginDialog, &LoginDialog::loginAccount, this, &MainWindow::on_login);
    connect(paletteList, &PaletteList::paletteLoad, this, &MainWindow::on_pallete_load);


    ui->colorlb_1->setStyleSheet(QString("background-color: #c1c1c1"));
    ui->colorlbl_2->setStyleSheet(QString("background-color: #c1c1c1"));
    ui->colorlbl_3->setStyleSheet(QString("background-color: #c1c1c1"));
    ui->colorlbl_4->setStyleSheet(QString("background-color: #c1c1c1"));


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

    colorArray[changed-1].setCode(color->getCode());
    colorArray[changed-1].setName(color->getName());
    qDebug() << "колір створено " << changed-1 << " "<<changed;
    qDebug() << colorArray[changed-1].colorToString();
}


void MainWindow::on_regbtn_clicked()
{
    loginDialog->exec();
}

void MainWindow::on_login(User *user){
    current_user = new User(user->getLogin(), user->getPassword());
    login = true;
    ui->accountlbl->setText(current_user->getLogin());    ui->regbtn->setText("змінити акаунт");
}


void MainWindow::on_pushButton_clicked()
{
    this->close();
}


void MainWindow::on_loadbtn_clicked()
{
    if (login){
        paletteList->exec();
    }else{
            QMessageBox::information(this, "помилка", "щоб завантажити палітру потрібно зареєструватись.");
        }
}


void MainWindow::on_savebtn_clicked()
{

    if (login){
        if (!ui->palletename->text().isEmpty()){
            palette = new Palitr(ui->palletename->text(), colorArray, current_user);
            qDebug() << palette->getColor(0).colorToString() << " "
                     << palette->getColor(1).colorToString() << " "
                     << palette->getColor(2).colorToString() << " "
                     << palette->getColor(3).colorToString();
            emit createdPallete(palette);
        }else{
            QMessageBox::critical(this, "помилка", "введіть назву палітри *поле вище*");
        }
    }else{
        QMessageBox::information(this, "помилка", "щоб створити палітру потрібно зареєструватись.");
    }
}

void MainWindow::on_pallete_load(Palitr *pallete)
{
    ui->colorlb_1->setStyleSheet(QString("background-color: %1;").arg(pallete->getColor(0).getCode()));
    ui->namelbl_1->setText(pallete->getColor(0).getName());
    ui->codelbl_1->setText(pallete->getColor(0).getCode());
    colorArray[0].setCode(pallete->getColor(0).getCode());
    colorArray[0].setName(pallete->getColor(0).getName());

    ui->colorlbl_2->setStyleSheet(QString("background-color: %1;").arg(pallete->getColor(1).getCode()));
    ui->namelbl_2->setText(pallete->getColor(1).getName());
    ui->codelbl_2->setText(pallete->getColor(1).getCode());
    colorArray[1].setCode(pallete->getColor(1).getCode());
    colorArray[1].setName(pallete->getColor(1).getName());

    ui->colorlbl_3->setStyleSheet(QString("background-color: %1;").arg(pallete->getColor(2).getCode()));
    ui->namelbl_3->setText(pallete->getColor(2).getName());
    ui->codelbl_3->setText(pallete->getColor(2).getCode());
    colorArray[2].setCode(pallete->getColor(2).getCode());
    colorArray[2].setName(pallete->getColor(2).getName());

    ui->colorlbl_4->setStyleSheet(QString("background-color: %1;").arg(pallete->getColor(3).getCode()));
    ui->namelbl_4->setText(pallete->getColor(3).getName());
    ui->codelbl_4->setText(pallete->getColor(3).getCode());
    colorArray[3].setCode(pallete->getColor(3).getCode());
    colorArray[3].setName(pallete->getColor(3).getName());

}


void MainWindow::on_pushButton_2_clicked()
{
    about->exec();
}

