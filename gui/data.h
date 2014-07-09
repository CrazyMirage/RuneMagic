#ifndef DATA_H
#define DATA_H

#include <QIcon>
#include <QFile>
#include <QDebug>

#include "../Magic_system/runes/rune.h"

class Data
{
public:
    Data();

    QIcon* getRuneImage(Runes::Runes rune);
private:

    QIcon **runeImages;
};

#endif // DATA_H
