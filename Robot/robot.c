#include "robot.h"
#include "main.h"
#include "math.h"

void robot_init(Robot_Typedef *robot, Motor_TypeDef* _motorLeft, Motor_TypeDef* _motorRight){
	robot->motorLeft = _motorLeft;
	robot->motorRight = _motorRight;
	robot->v_left = 0.0f;
	robot->v_right = 0.0f;
	robot->state = ROBOT_STOP;
	robot_control(robot, 0, 0);
}

void robot_control(Robot_Typedef *robot, float speed_left, float speed_right){
	if (robot->state == ROBOT_RUN){
		control_motor(robot->motorLeft, speed_left);
		control_motor(robot->motorRight, speed_right);
	}
	else if (robot->state == ROBOT_STOP){
		control_motor(robot->motorLeft, 0);
		control_motor(robot->motorRight, 0);
	}
}
