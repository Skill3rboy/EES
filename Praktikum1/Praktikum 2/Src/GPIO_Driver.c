/*
 * GPIO_Driver.c
 *
 * Created on: Nov 13, 2023
 * Author: hanna
 */
#include "GPIO_Driver.h"

/*
 * Peripheral Clock setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi){
	if(EnorDi == SET){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}else if (pGPIOx == GPIOB){
			GPIOB_PCLK_EN();
		}else if (pGPIOx == GPIOC){
			GPIOC_PCLK_EN();
		}else if (pGPIOx == GPIOD){
			GPIOD_PCLK_EN();
		}else if (pGPIOx == GPIOE){
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOF){
			GPIOF_PCLK_EN();
		}else if (pGPIOx == GPIOG){
			GPIOG_PCLK_EN();
		}else if (pGPIOx == GPIOH){
			GPIOH_PCLK_EN();
		}
	}
	else{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}else if (pGPIOx == GPIOB){
			GPIOB_PCLK_DI();
		}else if (pGPIOx == GPIOC){
			GPIOC_PCLK_DI();
		}else if (pGPIOx == GPIOD){
			GPIOD_PCLK_DI();
		}else if (pGPIOx == GPIOE){
			GPIOE_PCLK_DI();
		}else if (pGPIOx == GPIOF){
			GPIOF_PCLK_DI();
		}else if (pGPIOx == GPIOG){
			GPIOG_PCLK_DI();
		}else if (pGPIOx == GPIOH){
			GPIOH_PCLK_DI();
		}
	}
}

/*
 * Initialise the configuration of the pins
 * TODO: Ergänzen Sie die fehlenden Befehle!
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle){
	// Init clock
	/* note for gpio addr to rcc pin */
	//GPIO_RegDef_t* RCC = RCC_BASEADDR;
	//RCC->AHB1ENR = (0b1 << GPIO_BASEADDR_TO_CODE(pGPIO_Handle->pGPIOx));

	GPIO_PeriClockControl(pGPIO_Handle->pGPIOx, pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode);

	// Configuration of the pins as INPUT- or OUTPUT-Mode
	if(pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		pGPIO_Handle->pGPIOx->MODER = (pGPIO_Handle->pGPIOx->MODER & ~(0b11 << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber * 2))) | pGPIO_Handle->GPIO_PinConfig.GPIO_PinMode << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber * 2);
	}
	else
	{
		/* Hier folgt in Pratkikum 3 die Interrupt-Funktionalität */
	}

	// OUTPUT-Speed setzen:
	pGPIO_Handle->pGPIOx->OSPEEDR = (pGPIO_Handle->pGPIOx->OSPEEDR & ~(0b11 << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber * 2))) | pGPIO_Handle->GPIO_PinConfig.GPIO_PinSpeed << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber * 2);
	// Pull-Up-/Pull-Down setzen:
	pGPIO_Handle->pGPIOx->PUPDR = (pGPIO_Handle->pGPIOx->PUPDR & ~(0b11 << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber * 2))) | pGPIO_Handle->GPIO_PinConfig.GPIO_PinPuPdControl << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber * 2);
	// Output-Modus setzen:
	pGPIO_Handle->pGPIOx->OTYPER = (pGPIO_Handle->pGPIOx->OTYPER & ~(0b1 << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber ))) | pGPIO_Handle->GPIO_PinConfig.GPIO_PinOPType << (pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber );
}

/*
 * De-Initialise the configuration of the pins
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){
	if(pGPIOx == GPIOA)
		GPIOA_REG_RESET();
	else if(pGPIOx == GPIOB)
		GPIOB_REG_RESET();
	else if(pGPIOx == GPIOC)
		GPIOC_REG_RESET();
	else if(pGPIOx == GPIOD)
		GPIOD_REG_RESET();
	else if(pGPIOx == GPIOE)
		GPIOE_REG_RESET();
	else if(pGPIOx == GPIOF)
		GPIOF_REG_RESET();
	else if(pGPIOx == GPIOG)
		GPIOG_REG_RESET();
	else if(pGPIOx == GPIOH)
		GPIOH_REG_RESET();
}

/*
 * Read from input pin
 * TODO: Vervollständigen Sie die Funktion.
 */
uint8_t GPIO_ReadFromInputPin(GPIO_Handle_t *pGPIO_Handle) {
	return (uint8_t) ((pGPIO_Handle->pGPIOx->IDR & (0b1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber)) >> pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
}

/*
 * Read from input port
 * TODO: Vervollständigen Sie die Funktion.
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	return (uint16_t) pGPIOx->IDR;
}

/*
 * Write value to the pin
 * TODO: Vervollständigen Sie die Funktion.
 */
void GPIO_WriteToOutputPin(GPIO_Handle_t *pGPIO_Handle, uint8_t Value) {
    pGPIO_Handle->pGPIOx->ODR = (uint16_t)((pGPIO_Handle->pGPIOx->ODR & ~(0b1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber)) | (Value) << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber);
}

/*
 * Write value to the port
 * TODO: Vervollständigen Sie die Funktion.
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value) {
    pGPIOx->ODR = Value;
}

/*
 * Toggle value of the pin
 * TODO: Vervollständigen Sie die Funktion.
 */
void GPIO_ToggleOutputPin(GPIO_Handle_t *pGPIO_Handle) {
	pGPIO_Handle->pGPIOx->ODR ^= 0b1 << pGPIO_Handle->GPIO_PinConfig.GPIO_PinNumber;
}
