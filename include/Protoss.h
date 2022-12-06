#ifndef PROTOSS_H_
#define PROTOSS_H_

#include "Defines.h"
#include "stdbool.h"

typedef struct phoenix{
    BaseProtossShip *baseShip;    
}phoenix;

typedef struct carrier{
    BaseProtossShip *baseShip;
    bool isHealthFull;
}carrier;

#endif /* PROTOSS_H_ */