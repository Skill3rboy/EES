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
 * TODO: Ergänzen Sie die Werte!
 */
#define SET 1
#define RESET 0

/*
 * Basis-Adressen der AHBx and APBx Busse
 * TODO: Ergänzen
 */

#define PERIPH_BASEADDR 0x40000000
#define APB1PERIPH_BASEADDR 0x40000000
#define APB2PERIPH_BASEADDR 0x40010000
#define AHB1PERIPH_BASEADDR 0x40020000
#define AHB2PERIPH_BASEADDR 0x50000000

/*
 * Basis Adresses der GPIO-Ports und Adresse des Reset an Clock control Modul (RCC)
 * TODO: Ergänzen Sie die Adressen der GPIO-Ports und des RCC-Registers!
 */

#define GPIOA_BASEADDR 0x40020000
#define GPIOB_BASEADDR 0x40020400
#define GPIOC_BASEADDR 0x40020800
#define GPIOD_BASEADDR 0X40020C00
#define GPIOE_BASEADDR 0x40021000
#define GPIOF_BASEADDR 0x40021400
#define GPIOG_BASEADDR 0x40021800
#define GPIOH_BASEADDR 0x40021C00
#define RCC_BASEADDR 0x40023800

#include "stm.h"

#endif /* STM_H_ */
