/*
 * GPIO_Driver.c
 *
 * Created on: Nov 13, 2023
 * Author: hanna
 */
#include "GPIO_Driver.h"

/******************************************************************************************
 *									Functions for PortA
 ******************************************************************************************/

/*
 * Initialize the configuration of a PinA
 */
void GPIO_Init_PortA(uint8_t pGPIO_PinNumber, uint8_t pGPIO_PinMode){
	// TODO: Enable clock for PortA
	*((volatile uint32_t*) (RCC_BASEADDR + 0x30U)) |= (SET<<0);
	// TODO: Set mode bits for pinNumber on PortA
	*((volatile uint32_t*) GPIOA_BASEADDR) |= (pGPIO_PinMode << (pGPIO_PinNumber*2));

}

/*
 * Write value to PinA
 */
void GPIO_WriteToOutputPinA(uint8_t pGPIO_PinNumber, uint8_t value){
	// TODO: activate/deactivate pin on PortA
	*((volatile uint32_t*) (GPIOA_BASEADDR+0x14U)) = ((GPIOA_BASEADDR+0x14U) &~(1<<pGPIO_PinNumber)) | (value << pGPIO_PinNumber);
}

/*
 * Write value to PortA
 */
void GPIO_WriteToOutputPortA(uint16_t Value){
	// TODO: Set all pins of PortA
	*((volatile uint32_t*) (GPIOA_BASEADDR+0x14U))=Value;
}

/*
 * Toggle value of PinA
 */
void GPIO_ToggleOutputPinA(uint8_t pGPIO_PinNumber){
	 // TODO: Toggle pin on PortA
	*((volatile uint32_t*) (GPIOA_BASEADDR+0x14U)) ^= (1<<pGPIO_PinNumber);

}

/******************************************************************************************
 *									Functions for PortC
 ******************************************************************************************/

/*
 * Initialize the configuration of a PinA
 */
void GPIO_Init_PortC(uint8_t pGPIO_PinNumber, uint8_t pGPIO_PinMode){
	// TODO: Enable clock for PortC
	*((volatile uint32_t*) (RCC_BASEADDR + 0x30U)) |= (SET<<2);
	// TODO: Set mode bits for pinNumber on PortC
	*((volatile uint32_t*) (GPIOC_BASEADDR)) |= (pGPIO_PinMode << (pGPIO_PinNumber*2));
}

/*
 * Write value to PinC
 */
void GPIO_WriteToOutputPinC(uint8_t pGPIO_PinNumber, uint8_t value){
	// TODO: activate/deactivate pin on PortC
	*((volatile uint32_t*) (GPIOC_BASEADDR+0x14U)) = ((GPIOC_BASEADDR+0x14U) &~(1<<pGPIO_PinNumber)) | (value << pGPIO_PinNumber);
}

/*
 * Write value to PortC
 */
void GPIO_WriteToOutputPortC(uint16_t Value){
	// TODO: Set all pins of PortC
	*((volatile uint32_t*) (GPIOC_BASEADDR+0x14U))=Value;
}

/*
 * Toggle value of PinC
 */
void GPIO_ToggleOutputPinC(uint8_t pGPIO_PinNumber){
	 // TODO: Toggle pin on PortC
	*((volatile uint32_t*) (GPIOC_BASEADDR+0x14U)) ^= (1<<pGPIO_PinNumber);

}
