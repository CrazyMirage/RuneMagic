#include "fehurune.h"

FehuRune::FehuRune()
{
    cost = 10;
    type = Runes::Neutral;
    effects[Runes::Fehu] = &fehuRuneEffect;
    effects[Runes::Uraz] = &fehuRuneEffect;
    effects[Runes::Thurisaz] = &gostEffect;
}

