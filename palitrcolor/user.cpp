#include "user.h"

User::User(QString login, QString password)
    : login(login), password(password) {}

QString User::getLogin() {
    return login;
}

QString User::getPassword() {
    return password;
}
