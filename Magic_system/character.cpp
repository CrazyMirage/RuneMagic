#include "character.h"

Character::Character():
    health(0),
    power(0),
    spirit(0),
    concentration(0)
{
    type ='C';
}

Character::Character(int health, int power, int spirit, int concentration):
    health(health),
    power(power),
    spirit(spirit),
    concentration(concentration)
{
    type ='C';
}



int Character::getHealth()
{
    return health;
}

void Character::addHealth(int health)
{
    this->health += health;
}

int Character::getPower()
{
    return power;
}

void Character::addPower(int power)
{
    this->power += power;
}

int Character::getSpirit()
{
    return spirit;
}

void Character::addSpirit(int spirit)
{
    this->spirit += spirit;
}

int Character::getConcentration()
{
    return concentration;
}

void Character::addConcentration(int concentration)
{
    this->concentration += concentration;
}

void Character::test()
{
    qDebug() << "Health:"<< health;
    qDebug() << "Power:"<<power;
    qDebug() << "Spirit:"<< spirit;
    qDebug() << "Concentration:"<< concentration;
}
