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
	case MOTOR_BACKWARD:
		HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_SET);
		PWM_Set_Duty(motor, 100 - speed);
		break;
	case MOTOR_FORWARD:
		HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_RESET);
		PWM_Set_Duty(motor, speed);
		break;
	case MOTOR_STOP:
		HAL_GPIO_WritePin(motor->in1_port, motor->in1_pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(motor->in2_port, motor->in2_pin, GPIO_PIN_SET);
		PWM_Set_Duty(motor, 0);
		break;
	}
}

void motor_init(Motor_TypeDef *motor, pid_typedef* _pid, GPIO_TypeDef *_in1_port, uint16_t _in1_pin, 
		GPIO_TypeDef* _in2_port, uint16_t _in2_pin, TIM_HandleTypeDef *htim, uint32_t Tim_Channel){
	motor->htim = htim;
	motor->pid = _pid;
	motor->Tim_Channel = Tim_Channel;
	motor->in1_port = _in1_port;
	motor->in1_pin = _in1_pin;
	motor->in2_port = _in2_port;
	motor->in2_pin = _in2_pin;
	HAL_TIM_PWM_Start(motor->htim, motor->Tim_Channel);
}

