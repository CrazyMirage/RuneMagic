#ifndef SPELL_H
#define SPELL_H

#include "runes/rune.h"


struct ActiveEffect{
    Effect effect;
    int coefficient;
};

class Spell
{
public:
    Spell(QString name, int cost, ActiveEffect *effects, int effectsNumber);
    void activate(Object &object, Object &user, int mana);

private:
    QString name;
    int cost;
    ActiveEffect *effects;
    int effectsNumber;
};

#endif // SPELL_H
