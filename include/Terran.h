#ifndef TERRAN_H_
#define TERRAN_H_

#include "Defines.h"

typedef struct Viking{
    BaseTerranShip *baseShip;
    short int damage_multiplyer;
}Viking;

typedef struct BattleCruiser{
    BaseTerranShip *baseShip;
    short int yamatoCount;
}BattleCruiser;

BattleCruiser *battleCruiserInit();

#endif /* TERRAN_H_ */