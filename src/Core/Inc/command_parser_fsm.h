/*
 * command_parser_fsm.h
 *
 *  Created on: Nov 27, 2024
 *      Author: 84859
 */

#ifndef INC_COMMAND_PARSER_FSM_H_
#define INC_COMMAND_PARSER_FSM_H_
#include "main.h"
#include "global.h"
// Định nghĩa các trạng thái FSM

void command_parser_fsm();
uint8_t validate_command(uint8_t *buffer);

#endif /* INC_COMMAND_PARSER_FSM_H_ */
