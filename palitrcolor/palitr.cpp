#include "palitr.h"

Palitr::Palitr(QString name, Color colors[], User* user)
    : name(name), user(user)
{
    for (int i = 0; i < 4; ++i) {
        this->colors[i] = colors[i];
    }
}

Palitr::Palitr(QString name, User *user)
    : name(name), user(user)
{

}

QString Palitr::getName() const{
    return name;
}

Color Palitr::getColor(int index) {
    if (index >= 0 && index < 4) {
        return colors[index];
    } else {
        // Обробка помилки або можливо повернення за замовчуванням
        // (залежить від ваших потреб)
        return Color();  // Повернення порожнього кольору як за замовчуванням
    }
}

void Palitr::putColor(int index, Color *color)
{
    if (index >= 0 && index < 4) {
        colors[index].setID(color->getID());
        colors[index].setName(color->getName());
        colors[index].setCode(color->getCode());
    }
}

User* Palitr::getUser() const{
    return user;
}

void Palitr::setID(int id)
{
    this->id=id;
}
int Palitr::getID() const
{
    return id;
}
