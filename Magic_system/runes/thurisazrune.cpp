#include "thurisazrune.h"

ThurisazRune::ThurisazRune()
{
    cost = 50;
    type = Runes::Dark;
    effects[Runes::Fehu] = &increaseIntellectUseSpirit;
    effects[Runes::Uraz] = &thurisazRuneEffect;
    effects[Runes::Thurisaz] = &thurisazRuneEffect;
}
