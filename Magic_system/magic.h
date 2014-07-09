#ifndef MAGIC_H
#define MAGIC_H

#include <QString>
#include <QList>

#include "spell.h"
#include "runes/allrunes.h"
#include "character.h"

//typedef void (*Effect)(Object &, int);

struct Position{
    Position(){}
    Position(int x, int y);
    int x, y;
};

struct SpellField{
    SpellField(int x,int y);
    Runes::Runes **map;
    Position size;
    Position mainRune;
};

class Magic
{
public:
    Magic();
    ~Magic();

    Spell generateSpell(SpellField field);
    void testEffects();
    void testRunes();
private:
    void inizializeRunes();
    Rune **runes;
    void CreateRunes();
};

#endif // MAGIC_H
