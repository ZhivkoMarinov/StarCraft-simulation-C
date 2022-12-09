#ifndef PROTOSS_H_
#define PROTOSS_H_

#include "Defines.h"
#include "stdbool.h"

typedef struct Phoenix{
    BaseProtossShip *baseShip;    
}Phoenix;

typedef struct Carrier{
    BaseProtossShip *baseShip;
    bool isHealthFull;
}Carrier;

Carrier *carrierInit(int id);
Phoenix *phoenixInit(int id);

#endif /* PROTOSS_H_ */