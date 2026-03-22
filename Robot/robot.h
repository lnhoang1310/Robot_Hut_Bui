#ifndef ROBOT_H
#define ROBOT_H

#include "stm32f1xx.h"
#include "Motor.h"

typedef enum{
	ROBOT_STOP,
	ROBOT_RUN,
	INVALID
} Robot_State;

typedef struct{
	Motor_TypeDef *motorLeft;
	Motor_TypeDef *motorRight;
	float v_left;
	float v_right;
	Robot_State state;
} Robot_Typedef;

void robot_init(Robot_Typedef *robot, Motor_TypeDef *_motorLeft, Motor_TypeDef *_motorRight);
void robot_control(Robot_Typedef *robot, float speed_left, float speed_right);
#endif
