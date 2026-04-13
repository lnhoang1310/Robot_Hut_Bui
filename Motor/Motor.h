#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f1xx.h"
#include "pid.h"

typedef enum{
	MOTOR_STOP,
	MOTOR_FORWARD,
	MOTOR_BACKWARD
}Motor_Direction;

typedef struct{
	TIM_HandleTypeDef *htim;
	uint32_t Tim_Channel;
	Motor_Direction direction;
	GPIO_TypeDef *in1_port;
	uint16_t in1_pin;
	GPIO_TypeDef* in2_port;
	uint16_t in2_pin;
	uint8_t Speed;
	pid_typedef* pid;
}Motor_TypeDef;

void control_motor(Motor_TypeDef *motor, float speed);
void motor_init(Motor_TypeDef *motor, pid_typedef* _pid, GPIO_TypeDef *_in1_port, uint16_t _in1_pin, 
		GPIO_TypeDef* _in2_port, uint16_t _in2_pin, TIM_HandleTypeDef *htim, uint32_t Tim_Channel);
#endif
