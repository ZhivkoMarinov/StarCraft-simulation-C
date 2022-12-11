#ifndef PROTOSS_H_
#define PROTOSS_H_

#include "Defines.h"
#include "Vector.h"

BaseProtossShip *protossShipInit(int id, int type, int health, int shield, int shieldRegen);
void protossAttack(BaseProtossShip *currentShip, Vector *protossFleet);
void protossTakeDamage(BaseProtossShip *currentShip, int damage, Vector *protossFleet);
void shieldRegen(BaseProtossShip *lastShip);

#endif /* PROTOSS_H_ */