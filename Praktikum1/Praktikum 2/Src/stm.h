/*
 * stm.h
 *	VORLAGE
 *  Created on: Sep 12, 2023
 *  Author: hanna
 */

#ifndef STM_H_
#define STM_H_

#include<stddef.h>
#include<stdint.h>

/*
 * Allgemeine Makros
 */
#define SET 							1
#define RESET 							0

/*
 * Basis-Adressen der AHBx and APBx Busse
 */

#define PERIPH_BASEADDR 				0x40000000U
#define APB1PERIPH_BASEADDR				PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHB1PERIPH_BASEADDR				0x40020000U
#define AHB2PERIPH_BASEADDR				0x50000000U

/*
 * Basis-Adressen der AHBx and APBx Busse
 */
#define GPIOA_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1C00U)

/*
 * Basis Adresse des Reset and Clock control Module (RCC)
 */
#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x3800)

/********************************** Macros to access peripherals **********************************/

/*
 * Basisadressen gecastet auf entsprechende structs
 * TODO: Ergänzen Sie die gecasteten Adressen
 */

#define GPIOA		((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB		((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC		((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD		((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE		((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF		((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG		((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH		((GPIO_RegDef_t*) GPIOH_BASEADDR)
#define RCC			((RCC_RegDef_t*) RCC_BASEADDR)

/*
 * Clock Enable Makros für GPIO-Ports
 * TODO: Schreiben Sie Clock Enable und Disable Makros für die GPIO-Ports A bis H
 * Sehen Sie sich dazu die Informationen im Handbuch zum AHB1ENR-Register des RCC-Moduls an.
 */
#define GPIOA_PCLK_EN()		(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))

#define GPIOA_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()		(RCC->AHB1ENR &= ~(1 << 7))

/*
 *  Makros zum zurücksetzen des GPIO-Ports
 */
#define GPIOA_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()               do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)


// ####################################### PRAKTIKUM 2 ############################################################

/********************************** Register definition structs **********************************/

/*
 * Struct mit Konfigurations- und Daten-Registern der GPIO-Ports
 * TODO: Legen Sie ein entsprechendes Struct an!
 */
typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFRL;
	volatile uint32_t AFRH;
} GPIO_RegDef_t;

/*
 * Konfigurationsregister des RCC
 * TODO: Legen Sie ein entsprechendes Struct an!
 */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    uint32_t RESERVED0;
    volatile uint32_t APB1RSTR;
    volatile uint32_t APB2RSTR;
    uint32_t RESERVED1[2];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    uint32_t RESERVED2;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
    uint32_t RESERVED3[2];
    volatile uint32_t AHB1LPENR;
    volatile uint32_t AHB2LPENR;
    volatile uint32_t AHB3LPENR;
    uint32_t RESERVED4;
    volatile uint32_t APB1LPENR;
    volatile uint32_t APB2LPENR;
    uint32_t RESERVED5[2];
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    uint32_t RESERVED6[2];
    volatile uint32_t SSCGR;
    volatile uint32_t PLLI2SCFGR;
    volatile uint32_t PLLSAICFGR;
    volatile uint32_t DCKCFGR;
    volatile uint32_t CKGATENR;
    volatile uint32_t DCKCFGR2;
} RCC_RegDef_t;


/*
 * Peripherie Register struct für SYSCFG
 * TODO: Legen Sie ein entsprechendes Struct an!
 */
typedef struct
{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t CMPCR;
	uint32_t RESERVED0[2];
	volatile uint32_t CFGR;
} SYSCFG_RegDef_t;

/*
 * This macro returns a code( between 0 to 7) for a given GPIO base address(x)
 */
#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA)?0:\
										(x == GPIOB)?1:\
										(x == GPIOC)?2:\
										(x == GPIOD)?3:\
								        (x == GPIOE)?4:\
								        (x == GPIOF)?5:\
								        (x == GPIOG)?6:\
								        (x == GPIOH)?7:0)

/*
 * Sysconfig Adressen und Makros
 */
#define SYSCFG_BASEADDR        			(APB2PERIPH_BASEADDR + 0x3800)
#define SYSCFG							((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

/*
 * Clock Enable Macros für SYSCFG Peripherie
 * TODO: Vervollständigen Sie die Makros zum anschalten und abschalten der Syscfg clock
 */
#define SYSCFG_PCLK_EN()	(RCC->APB2ENR |= (1 << 14))
#define SYSCFG_PCLK_DI()	(RCC->APB2ENR &= ~(1 << 14))

#include "stm.h"

#endif /* STM_H_ */
