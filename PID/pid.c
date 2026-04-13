#include "pid.h"

void pid_init(pid_typedef* pid, float _kp, float _ki, float _kd, float _out_min, float _out_max, float _sample_time){
	pid->kp = _kp;
	pid->ki = _ki;
	pid->kd = _kd;
	pid->out_min = _out_min;
	pid->out_max = _out_max;
	pid->setpoint = 0.0f;
	pid->derivative = 0.0f;
	pid->integral = 0.0f;
	pid->prev_error = 0.0f;
	pid->sample_time = _sample_time;
	pid->output = 0.0f; 
}

void pid_calculate(pid_typedef* pid, float mesurement){
	float error = pid->setpoint - mesurement;
	
	float P = pid->kd * error;
	
	pid->integral += error * pid->sample_time;
	if(pid->integral > pid->out_max) pid->integral = pid->out_max;
	if(pid->integral < pid->out_min) pid->integral = pid->out_min;
	float I = pid->ki * pid->integral;
	
	pid->derivative = (error - pid->prev_error) * pid->sample_time;
	float D = pid->kd * pid->derivative;
	
	pid->output = P + I + D;
	
	if(pid->output > pid->out_max) pid->output = pid->out_max;
	if(pid->output < pid->out_min) pid->output = pid->out_min;
	
	pid->prev_error = error;
}

void pid_reset(pid_typedef* pid){
	pid->derivative = 0.0f;
	pid->integral = 0.0f;
	pid->prev_error = 0.0f;
}
