#ifndef DEFINES_H_
#define DEFINES_H_

typedef struct BaseTerranShip{
  int health;
  int ID;
}BaseTerranShip;

typedef struct BaseProtossShip{
  int health;
  int ID;
  int shield;
}BaseProtossShip;


enum AirShipDefines {
  BATTLE_CRUSER_HEALTH = 450,
  BATTLE_CRUSER_DAMAGE = 40,

  VIKING_HEALTH = 150,
  VIKING_DAMAGE = 15,

  CARRIER_HEALTH = 200,
  CARRIER_SHIELD = 150,
  CARRIER_DAMAGE = 8,
  CARRIER_SHIELD_REGENERATE_RATE = 40,

  PHOENIX_HEALTH = 90,
  PHOENIX_SHIELD = 90,
  PHOENIX_DAMAGE = 20,
  PHOENIX_SHIELD_REGENERATE_RATE = 20
};

enum AirShipType {
  BATTLE_CRUSER, VIKING, CARRIER, PHOENIX
};

enum CarrierDefines {
  MAX_INTERCEPTORS = 8,
  DAMAGED_STATUS_INTERCEPTORS = 4
};

enum BattleCruserDefines {
  YAMATO_CANNON_LOADING_TURNS = 4
};

#endif /* DEFINES_H_ */
