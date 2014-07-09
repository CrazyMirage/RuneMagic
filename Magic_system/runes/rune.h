#ifndef RUNE_H
#define RUNE_H

#include "../object.h"
#include "effects.h"

typedef void (*Effect)(Object &, int);

namespace  Runes{
    enum MagicType{Light, Dark, Neutral};
    enum Runes{Fehu,Uraz,Thurisaz
               ,End};//конец рун
}

class Rune
{
public:
    Rune();
    //Rune(QString name, int coefficient, Runes::MagicType type, Effect standartEffect);
    //virtual void effect(Object &);
    Effect combinationEffect(Runes::Runes rune);
    int getCost();

protected:
    Runes::Runes indentificator;
    QString name;
    int cost;
    Runes::MagicType type;
    Effect *effects;
};

#endif // RUNE_H
