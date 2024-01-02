#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>
#include <QDebug>


LoginDialog::LoginDialog(DBManager* dbManager, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog), dbManager(dbManager)
{
    ui->setupUi(this);
    if (!dbManager) {
        qDebug() << "Неправильний вказівник DBManager у конструкторі DialogPrintSong";
        // Обробте помилку, можливо, закрийте діалогове вікно або покажіть повідомлення про помилку
        // в залежності від логіки вашого додатка.
        return;
    }

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_2_clicked()
{
    this->close();
}


void LoginDialog::on_login_btn_clicked() {
    if (!ui->password->text().isEmpty() && !ui->login_2->text().isEmpty()) {
        checkLogin(ui->login_2->text(), ui->password->text());
    } else {
        QMessageBox::critical(this, "Помилка", "Поля не заповнені або заповнені не правильно.");
    }
}

void LoginDialog::on_pushButton_clicked() {
    if (!ui->passwordsign->text().isEmpty() && !ui->login_sign->text().isEmpty() && !ui->password_sign->text().isEmpty()) {
        if (ui->passwordsign->text() == ui->password_sign->text()) {
            if (isLoginAvailable(ui->login_sign->text())) {
                registerUser(ui->login_sign->text(), ui->password_sign->text());
            } else {
                QMessageBox::critical(this, "Помилка", "Користувач з таким логіном вже існує.");
            }
        } else {
            QMessageBox::critical(this, "Помилка", "Паролі не збігаються.");
        }
    } else {
        QMessageBox::critical(this, "Помилка", "Поля не заповнені або заповнені не правильно.");
    }
}


void LoginDialog::registerUser(const QString &login, const QString &password) {
    User newUser(login, password);
    if (dbManager->inserIntoTable(newUser)) {
        QMessageBox::information(this, "Успішна реєстрація", "Ви успішно зареєструвалися!");
        clearRegistrationFields();
    } else {
        QMessageBox::critical(this, "Помилка", "Не вдалося зареєструвати користувача.");
    }
}

void LoginDialog::clearRegistrationFields() {
    ui->login_sign->clear();
    ui->password_sign->clear();
    ui->passwordsign->clear();
}
bool LoginDialog::isLoginAvailable(const QString &login) {
    // Перевірка наявності користувача з таким логіном у базі даних
    return !dbManager->userExists(login);
}
void LoginDialog::checkLogin(const QString &login, const QString &password) {
    User *currentUser = dbManager->getUser(login);
    if (currentUser && currentUser->getPassword() == password) {
        qDebug() << "login";
        emit loginAccount(currentUser);
        this->close();
    } else {
        QMessageBox::critical(this, "Помилка", "Логін або пароль невірні.");
    }
}



