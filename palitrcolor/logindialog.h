#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "user.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

signals:
    void loginAccount(User *user);
private slots:
    void on_pushButton_2_clicked();

    void on_login_btn_clicked();

    void on_pushButton_clicked();

private:
    Ui::LoginDialog *ui;

    bool sign = false;
    User *user_temp;
    User *user;
};

#endif // LOGINDIALOG_H
