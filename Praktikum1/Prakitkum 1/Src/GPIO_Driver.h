/*
 * GPIO_Driver.h
 *
 *  Created on: Nov 13, 2023
 *      Author: hanna
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_
#include "stm.h"

/*
 * GPIO pin numbers
 */
#define GPIO_PIN_NO_0  				0
#define GPIO_PIN_NO_1  				1
#define GPIO_PIN_NO_2  				2
#define GPIO_PIN_NO_3  				3
#define GPIO_PIN_NO_4  				4
#define GPIO_PIN_NO_5  				5
#define GPIO_PIN_NO_6  				6
#define GPIO_PIN_NO_7  				7
#define GPIO_PIN_NO_8  				8
#define GPIO_PIN_NO_9  				9
#define GPIO_PIN_NO_10  			10
#define GPIO_PIN_NO_11 				11
#define GPIO_PIN_NO_12  			12
#define GPIO_PIN_NO_13 				13
#define GPIO_PIN_NO_14 				14
#define GPIO_PIN_NO_15 				15

/*
 * GPIO pin Modes
 */
#define GPIO_MODE_IN 				0
#define GPIO_MODE_OUT 				1
#define GPIO_MODE_ALTFN 			2
#define GPIO_MODE_ANALOG 			3
#define GPIO_MODE_IT_FT     		4
#define GPIO_MODE_IT_RT     		5
#define GPIO_MODE_IT_RFT    		6

/*
 * GPIO pin Output-Modi
 */
#define GPIO_OP_TYPE_PP   			0
#define GPIO_OP_TYPE_OD   			1

/*
 * GPIO pin output speed settings
 */
#define GPIO_SPEED_LOW				0
#define GPIO_SPEED_MEDIUM			1
#define GPIO_SPEED_FAST				2
#define GPIO_SPEED_HIGH				3

/*
 * GPIO pin pull-up/down Konfigurationen
 */
#define GPIO_NO_PUPD   				0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2

/******************************************************************************************
 *									Driver functions
 ******************************************************************************************/

/*
 * Init PortA
 */
void GPIO_Init_PortA(uint8_t pGPIO_PinNumber, uint8_t pGPIO_PinMode);
/*
 * Write data for Pin/PortA
 */
void GPIO_WriteToOutputPinA(uint8_t pGPIO_PinNumber, uint8_t value);
void GPIO_WriteToOutputPortA(uint16_t Value);
void GPIO_ToggleOutputPinA(uint8_t pGPIO_PinNumber);
/*
 * Init PortC
 */
void GPIO_Init_PortC(uint8_t pGPIO_PinNumber, uint8_t pGPIO_PinMode);
/*
 * Write data for Pin/PortC
 */
void GPIO_WriteToOutputPinC(uint8_t pGPIO_PinNumber, uint8_t value);
void GPIO_WriteToOutputPortC(uint16_t Value);
void GPIO_ToggleOutputPinC(uint8_t pGPIO_PinNumber);

#endif /* GPIO_DRIVER_H_ */
