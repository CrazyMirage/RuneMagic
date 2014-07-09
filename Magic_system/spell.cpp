#include "spell.h"

Spell::Spell(QString name, int cost, ActiveEffect *effects, int effectsNumber):
    name(name),
    cost(cost),
    effects(effects),
    effectsNumber(effectsNumber)
{
    qDebug() << name << cost  << effectsNumber;
}

void Spell::activate(Object &object, Object &user, int mana)
{
    for(int i = 0; i < effectsNumber; ++i){
        effects[i].effect(object, effects[i].coefficient);
    }
}
