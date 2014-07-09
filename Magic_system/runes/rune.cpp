#include "rune.h"


Rune::Rune(){
    effects = new Effect[Runes::End];
}
/*Rune::Rune(QString name, int coefficient, Runes::MagicType type, Effect standartEffect):
  name(name), coefficient(coefficient), type(type), standartEffect(standartEffect)
{}*/


Effect Rune::combinationEffect(Runes::Runes rune)
{
    return effects[rune];
}

int Rune::getCost()
{
    return cost;
}

