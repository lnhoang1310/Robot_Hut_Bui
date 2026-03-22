#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_
#include "stm32f1xx.h"
typedef enum{
	MOTOR_STOP,
	MOTOR_FORWARD,
	MOTOR_BACKWARD
}Motor_Direction;

typedef struct{
	TIM_HandleTypeDef *htim;
	uint32_t Tim_Channel;
	Motor_Direction direction;
	GPIO_TypeDef *IO_Port;
	uint16_t IO_Pin;
	uint8_t Speed;
}Motor_TypeDef;

void control_motor(Motor_TypeDef *motor, float speed);
void motor_init(Motor_TypeDef *motor, GPIO_TypeDef *IO_Port, uint16_t IO_Pin,
		TIM_HandleTypeDef *htim, uint32_t Tim_Channel);
#endif
