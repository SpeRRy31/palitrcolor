#ifndef PALITR_H
#define PALITR_H

#include <QString>
#include "color.h"

class Palitr
{
    QString name;
    Color colors[4];
public:
    Palitr(QString name, Color colors[]);

    QString getName();
    Color getColor(int index);
};

#endif // PALITR_H
