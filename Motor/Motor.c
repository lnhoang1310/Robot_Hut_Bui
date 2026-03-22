#include "Motor.h"

void PWM_Set_Duty(Motor_TypeDef* motor, float duty){
	uint16_t ccr = (uint16_t)(duty / 100.0f * motor->htim->Instance->ARR);
	switch(motor->Tim_Channel){
		case 1: motor->htim->Instance->CCR1 = ccr; break;
		case 2: motor->htim->Instance->CCR2 = ccr; break;
		case 3: motor->htim->Instance->CCR3 = ccr; break;
		case 4: motor->htim->Instance->CCR4 = ccr; break;
	}
}

void control_motor(Motor_TypeDef *motor, float speed){
	switch(motor->direction){
	case MOTOR_STOP:
		HAL_GPIO_WritePin(motor->IO_Port, motor->IO_Pin, GPIO_PIN_RESET);
		PWM_Set_Duty(motor, 0);
		break;
	case MOTOR_FORWARD:
		HAL_GPIO_WritePin(motor->IO_Port, motor->IO_Pin, GPIO_PIN_RESET);
		PWM_Set_Duty(motor, speed);
		break;
	case MOTOR_BACKWARD:
		HAL_GPIO_WritePin(motor->IO_Port, motor->IO_Pin, GPIO_PIN_SET);
		PWM_Set_Duty(motor, 100 - speed);
		break;
	}
}

void motor_init(Motor_TypeDef *motor, GPIO_TypeDef *IO_Port, uint16_t IO_Pin,
		TIM_HandleTypeDef *htim, uint32_t Tim_Channel){
	motor->htim = htim;
	motor->Tim_Channel = Tim_Channel;
	motor->IO_Port = IO_Port;
	motor->IO_Pin = IO_Pin;
	HAL_TIM_PWM_Start(motor->htim, motor->Tim_Channel);
}

