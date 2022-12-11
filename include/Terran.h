#ifndef TERRAN_H_
#define TERRAN_H_

#include "Defines.h"
#include "Vector.h"

BaseTerranShip *terranShipInit(int id, int type, int health);
void terranAttack(BaseTerranShip *currentShip, Vector *protossFleet, int round);
void terranTakeDamage(BaseTerranShip *currentShip, int damage, Vector *terranFleet);
#endif /* TERRAN_H_ */