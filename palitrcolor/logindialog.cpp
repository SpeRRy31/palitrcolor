#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>
#include <QDebug>


LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_2_clicked()
{
    this->close();
}


void LoginDialog::on_login_btn_clicked()
{

    if(!ui->password->text().isEmpty() && !ui->login_2->text().isEmpty()){

        user_temp = new User(ui->login_2->text(), ui->password->text());
        if (sign){
            if (user->getLogin()==ui->login_2->text() && user->getPassword() == ui->password->text()){
                emit loginAccount(user_temp);

                this->close();
            }
        }




        /*for (int i = 0; i < userList.size(); ++i) {
            qDebug() << userList[i].getLogin();

            if (user->getLogin() == userList[i].getLogin() && user->getPassword() == userList[i].getPassword()){
                emit loginAccount(user);

                qDebug() << "3l";
            }else{
                QMessageBox::critical(this, "помилка", "Логін або пароль невірні.");
            }
        }*/

    }else{
        QMessageBox::critical(this, "помилка", "Поля не заповнені або заповнені не правильно.");
    }

}


void LoginDialog::on_pushButton_clicked()//зареєструватиась
{
    qDebug() << "s1";
    if(!ui->password_sign->text().isEmpty() && !ui->login_sign->text().isEmpty() && !ui->passwordsign->text().isEmpty()){

        qDebug() << "s2";
        if(ui->passwordsign->text() == ui->password_sign->text()){

            qDebug() << "s3";
            user = new User(ui->login_sign->text(), ui->password_sign->text());
            sign = true;
        }else{

            qDebug() << "s4";
            QMessageBox::critical(this, "помилка", "Паролі не збігаються.");
        }
    }else{
        QMessageBox::critical(this, "помилка", "Поля не заповнені або заповнені не правильно.");
    }
}
