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
 * Struct für PIN-Konfiguration
 */
typedef struct {
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	// uint8_t GPIO_PinAltFunMode;
} GPIO_PinConfig_t;

/*
 * Handle struct für GPIO pin
 */
typedef struct {
	GPIO_RegDef_t *pGPIOx;       		/*!< Basisadresse des GPIO ports >*/
	GPIO_PinConfig_t GPIO_PinConfig;	/*!< Pin Nummer und Konfiguration >*/
} GPIO_Handle_t;

/*
 * GPIO pin Nummern
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
 * GPIO pin pull-up/down configurations
 */
#define GPIO_NO_PUPD   				0
#define GPIO_PIN_PU					1
#define GPIO_PIN_PD					2

/******************************************************************************************
 *								Functions of the driver
 ******************************************************************************************/

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_Handle_t *pGPIO_Handle);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_Handle_t *pGPIO_Handle, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_Handle_t *pGPIO_Handle);

/*
 * Interrupt configuration
 */
void GPIO_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);



#endif /* GPIO_DRIVER_H_ */
