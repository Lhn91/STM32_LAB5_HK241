/*
 * global.h
 *
 *  Created on: Nov 27, 2024
 *      Author: 84859
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "stdio.h"
#include "string.h"
#define IDLE       0
#define RECEIVING  1
#define DONE1       2
#define WAITING    3     // Chờ lệnh từ Command Parser
#define RESPONDING 4      // Đang gửi phản hồi (ADC Value)
#define WAIT_ACK   5      // Chờ ACK từ terminal (!OK#)
#define DONE2       6      // Kết thúc giao tiếp
#define MAX_BUFFER_SIZE 30
extern UART_HandleTypeDef huart2; // Khai báo handle UART
extern char str[20];
extern uint8_t temp;
extern uint8_t buffer [MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern uint8_t command_flag;
extern uint32_t timeout_start;
extern uint8_t state;
extern uint32_t ADC_value; // Biến lưu giá trị ADC
#define INITIAL_BUFFER_CAPACITY 30

extern uint8_t* dynamic_buffer;
extern uint16_t buffer_capacity;

#endif /* INC_GLOBAL_H_ */
