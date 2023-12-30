#include "palitr.h"

Palitr::Palitr(QString name, Color colors[])
    : name(name)
{
    for (int i = 0; i < 4; ++i) {
        this->colors[i] = colors[i];
    }
}

QString Palitr::getName() {
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
