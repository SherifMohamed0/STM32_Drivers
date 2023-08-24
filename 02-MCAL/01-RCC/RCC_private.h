/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 14 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* RCC Base ADDRESS*/
#define BASE_ADDRESS   0x40021000

/* Register Definitions */
#define RCC_CR  		*((u32*)(BASE_ADDRESS+0x00))
#define RCC_CFGR    	*((u32*)(BASE_ADDRESS+0x04))
#define RCC_CIR  		*((u32*)(BASE_ADDRESS+0x08))
#define RCC_APB2RSTR  	*((u32*)(BASE_ADDRESS+0x0C))
#define RCC_APB1RSTR  	*((u32*)(BASE_ADDRESS+0x10))
#define RCC_AHBENR  	*((u32*)(BASE_ADDRESS+0x14))
#define RCC_APB2ENR  	*((u32*)(BASE_ADDRESS+0x18))
#define RCC_APB1ENR  	*((u32*)(BASE_ADDRESS+0x1C))
#define RCC_BDCR  		*((u32*)(BASE_ADDRESS+0x20))
#define RCC_CSR  		*((u32*)(BASE_ADDRESS+0x24))


/* Clock Types */
#define RCC_HSI				0
#define RCC_HSE_CRYSTAL		1	
#define RCC_HSE_RC			2
#define RCC_PLL				3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

#endif
