#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"
#include <QDebug>

class Character : public Object
{
public:
    Character();
    Character(int health, int power, int spirit, int concentration);

    int getHealth();
    void addHealth(int health);

    int getPower();
    void addPower(int power);

    int getSpirit();
    void addSpirit(int spirit);

    int getConcentration();
    void addConcentration(int concentration);

    void test();

private:
    int health;
    int power;
    int spirit;
    int concentration;
};

#endif // CHARACTER_H
