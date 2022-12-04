#ifndef PROCESS_INPUT_H
#define PROCESS_INPUT_H

#include <stdbool.h>

void TakeInputData(char *terranFleer, char *protossFleet, int buffsize);
bool IsValid(char *inputData, int size);
void LowerCase(char *data, int size);

#endif /* PROCESS_INPUT_H */