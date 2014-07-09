#include "urazrune.h"

UrazRune::UrazRune()
{
    cost = 15;
    type = Runes::Neutral;
    effects[Runes::Fehu] = &increasePowerUseSpirit;
    effects[Runes::Uraz] = &urazRuneEffect;
    effects[Runes::Thurisaz] = &magicPowerIncreaseEffect;
}

