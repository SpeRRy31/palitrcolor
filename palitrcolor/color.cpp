#include "color.h"

Color::Color(QString name, QString code)
    : name(name), code(code) {}

QString Color::getName() {
    return name;
}

QString Color::getCode() {
    return code;
}

QString Color::colorToString() {
    return name + ": " + code;
}
