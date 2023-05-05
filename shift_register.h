/*
 * shift_register.h
 *
 * Created : 08/10/2019
 * Author  : Muhammad Khoiril Wafi
 * Company : Teknik Elektro Diponegoro University
 *
 */

#ifndef SHIFT_REGISTER_H
#define SHIFT_REGISTER_H

#include "stm32f1xx_hal.h"
#include "main.h"

#define Shift_PortType GPIO_TypeDef*
#define Shift_PinType uint16_t

// ---------- typedef ----------

typedef struct {
	Shift_PortType clk_port;
	Shift_PortType data_port;
	Shift_PortType latch_port;
	Shift_PinType clk_pin;
	Shift_PinType data_pin;
	Shift_PinType latch_pin;
} Shift_HandleTypeDef;

// ---------- public function ----------

void Register_create(Shift_PortType clk_port, Shift_PinType clk_pin, Shift_PortType data_port, Shift_PinType data_pin, Shift_PortType latch_port, Shift_PinType latch_pin);
void Register_send(uint8_t* data, uint32_t length);

#endif // SHIFT_REGISTER_H
