#ifndef PID_H
#define PID_H

#include <stdint.h>

#define KP_LEFT 0.0f
#define KI_LEFT 0.0f
#define KD_LEFT 0.0f

#define KP_RIGHT 0.0f
#define KI_RIGHT 0.0f
#define KD_RIGHT 0.0f

#define PID_OUTPUT_MIN 0.0f
#define PID_OUTPUT_MAX 100.0f

#define PID_SAMPLE_TIME 0.01f

typedef struct{
	float kp;
	float ki;
	float kd;
	float setpoint;
	float integral;
	float derivative;
	float prev_error;
	float output;
	float out_min;
	float out_max;
	float sample_time;
}pid_typedef;

void pid_init(pid_typedef* pid, float _kp, float _ki, float _kd, float _out_min, float _out_max, float _sample_timm);
void pid_calculate(pid_typedef* pid, float mesurement);
void pid_reset(pid_typedef* pid);
#endif
