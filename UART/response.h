#ifndef RESPONSE_H
#define RESPONSE_H

#include "stm32f1xx.h"

uint8_t response_uart(char **argv, float* speed_left, float* speed_right, uint8_t* state);

#endif
