#include "uart.h"
#include "response.h"
#include <string.h>
#include <math.h>

uint8_t uart_buff[UART_BUFFER_SIZE] = {0};
uint8_t flag_cpltReceive = 0;
uint8_t buffer_index = 0;
float setpoint_left;
float setpoint_right;
char *argv[5];
uint8_t flag_data_error = 0;

void uart_receive_data(uint8_t data_rx)
{
	if (data_rx == '\n')
	{
		if(flag_data_error){
			flag_data_error = 0;
			return;
		}
		flag_cpltReceive = 1;
		uart_buff[buffer_index] = '\0';
		buffer_index = 0;
	}
	else
	{
		if (data_rx == ' ' || (data_rx >= '0' && data_rx <= '9') || data_rx == '-')
		{
			uart_buff[buffer_index++] = data_rx;
			if(buffer_index >= UART_BUFFER_SIZE - 2) buffer_index = 0;
		}else{	
			flag_data_error = 1;
			buffer_index = 0;
		}
	}
}

void uart_handle(Robot_Typedef* robot){
	if(flag_cpltReceive){
		flag_cpltReceive = 0;
		float speed_left = 0;
		float speed_right = 0;
		uint8_t state = 0;
		uint8_t index = 0;
		char *token = strtok((char *)uart_buff, " ");
		while (token != NULL){
			argv[index++] = token;
			token = strtok(NULL, " ");
		}

		if(!response_uart(argv, &speed_left, &speed_right, &state)) return;
		
		
		if(state) robot->state = ROBOT_RUN;
		else robot->state = ROBOT_STOP;

		robot->motorLeft->pid->setpoint = (speed_left >= 0) ? speed_left : speed_left * (-1.0f);
		robot->motorRight->pid->setpoint = (speed_right >= 0) ? speed_right : speed_right * (-1.0f);
		
		if (speed_left < 0) robot->motorLeft->direction = MOTOR_BACKWARD;
		else robot->motorLeft->direction = MOTOR_FORWARD;
		if (speed_right < 0) robot->motorRight->direction = MOTOR_FORWARD;
		else robot->motorRight->direction = MOTOR_BACKWARD;
	}
}

