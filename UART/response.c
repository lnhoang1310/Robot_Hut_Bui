#include "response.h"
#include "string.h"
#include "math.h"

#define MAX_RANGE_SPEED 0.5
#define MIN_RANGE_SPEED -0.5

static float get_data(char *data){
    if(data == NULL) return -1;
    uint8_t flag = 0;        
    uint8_t count_minus = 0; 
    float value = 0; 
    uint8_t len = strlen(data);

    if(len == 0) return -1;

    for(uint8_t k = 0; k < len; k++){
        if(data[k] == '-'){
            if (count_minus >= 1 || k != 0) return -1;
            flag = 1;
            count_minus++;
            continue;
        }
		
		if(data[k] == '.') continue;
		
        if(data[k] < '0' || data[k] > '9') return -1;

        value = value * 10 + (data[k] - '0');
    }
	value /= 10;
    if(flag) value *= (-1.0f);;
    return value;
}


static void get_info_cmd(char **argv, float* speed_left, float* speed_right){
	*speed_left = get_data(argv[0]);
	*speed_right = get_data(argv[1]);
}

uint8_t response_uart(char **argv, float* speed_left, float* speed_right, uint8_t* state){
	get_info_cmd(argv, speed_left, speed_right);
	if(*speed_left == 0 && *speed_right == 0) *state = 0;
	else *state = 1;
	if (*speed_left > MAX_RANGE_SPEED || *speed_right > MAX_RANGE_SPEED || *speed_left < MIN_RANGE_SPEED || *speed_right < MIN_RANGE_SPEED)
		return 0;
	return 1;
}
