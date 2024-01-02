#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

#include "user.h"

#include "sqllitedbmanager.h"

class QSqlTableModel;
class DBManager;

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(DBManager* dbManager, QWidget *parent = nullptr);
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

    void registerUser(const QString &login, const QString &password);
    void clearRegistrationFields();

    bool isLoginAvailable(const QString &login);
    void checkLogin(const QString &login, const QString &password);

    DBManager* dbManager;
};

#endif // LOGINDIALOG_H
