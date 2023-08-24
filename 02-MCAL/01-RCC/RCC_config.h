/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 14 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*Options:RCC_HSI
          RCC_HSE_CRYSTAL
          RCC_HSE_RC
		  RCC_PLL*/
#define RCC_Clk_SOURCE   RCC_HSE_CRYSTAL

#if (RCC_Clk_SOURCE == RCC_PLL)
{
	/*Options:
          RCC_PLL_IN_HSI_DIV_2
          RCC_PLL_IN_HSE_DIV_2
		  RCC_PLL_IN_HSE */    

	#define RCC_PLL_INPUT  RCC_PLL_IN_HSE

	/* Options: 2 to 16 */
	#define RCC_PLL_MUL  2
}

#endif

#endif
