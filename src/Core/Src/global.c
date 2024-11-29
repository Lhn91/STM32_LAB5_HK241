/*
 * global.c
 *
 *  Created on: Nov 27, 2024
 *      Author: 84859
 */
#include "global.h"

// Định nghĩa các biến toàn cục
uint8_t temp = 0;
uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint8_t command_flag = 0;
uint32_t timeout_start = 0;
uint8_t state = IDLE;
uint32_t ADC_value = 0;
uint8_t* dynamic_buffer = NULL;
uint16_t buffer_capacity = INITIAL_BUFFER_CAPACITY;
uint32_t temp2 = 0;
