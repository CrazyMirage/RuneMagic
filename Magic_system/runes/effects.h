#ifndef EFFECTS_H
#define EFFECTS_H

#include "QDebug"
#include "../object.h"
//основные руны
void fehuRuneEffect(Object &object, int n);
void urazRuneEffect(Object &object, int n);
void thurisazRuneEffect(Object &object, int n);

//комбинации рун
void increasePowerUseSpirit(Object &object, int n);
void increaseIntellectUseSpirit(Object &object, int n);
void gostEffect(Object &object, int n);
void magicPowerIncreaseEffect(Object &object, int n);


#endif // EFFECTS_H
