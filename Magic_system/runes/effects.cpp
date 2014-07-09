#include "effects.h"

void fehuRuneEffect(Object &object, int n)
{
    qDebug() << "It's Fehu rune effect";
    switch (object.getType()) {
    case 'C':
        break;
    default:
        break;
    }
}

void urazRuneEffect(Object &object, int n)
{
    qDebug() << "It's Uraz rune effect";
    switch (object.getType()) {
    case 'C':
        object.addPower(n*object.getPower()/20);
        break;
    default:
        break;
    }
}

void thurisazRuneEffect(Object &object, int n)
{
    qDebug() << "It's Thurisaz rune effect";
    switch (object.getType()) {
    case 'C':
        break;
    default:
        break;
    }
}


void increasePowerUseSpirit(Object &object, int n)
{
    qDebug() << "increase Power Use Spirit";
    switch (object.getType()) {
    case 'C':
        object.addPower(n*object.getSpirit()/20);
        break;
    default:
        break;
    }
}

void increaseIntellectUseSpirit(Object &object, int n)
{
    qDebug() << "increase Intellect Use Spirit";
    switch (object.getType()) {
    case 'C':
        break;
    default:
        break;
    }
}

void gostEffect(Object &object, int n)
{
    qDebug() << "gost Effect";
    switch (object.getType()) {
    case 'C':
        break;
    default:
        break;
    }
}

void magicPowerIncreaseEffect(Object &object, int n)
{
    qDebug() << "magic Power Increase Effect";
    switch (object.getType()) {
    case 'C':
        break;
    default:
        break;
    }
}
