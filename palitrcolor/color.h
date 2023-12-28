#ifndef COLOR_H
#define COLOR_H

#include <QString>

class Color
{
    QString name;
    QString code;
public:
    Color(QString name, QString code);

    QString getName();
    QString getCode();

    QString colorToString();
};

#endif // COLOR_H
