/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 29 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "HLEDMAT_config.h"

u8 cols[8]={0,1,5,6,7,8,9,10};

void HLEDMAT_voidDisplayText(u8 *Copy_u8Frame)
{
	u8 Copy_Data[8];
	u8 index=0;
	while(index < 70)
	{

		for(int j=0 ; j<8 ;j++)
		{
			Copy_Data[j]=Copy_u8Frame[index+j];
		}

		for(int k=0 ; k<50 ;k++)
		{
			for(int i=0 ; i<8 ;i++)
			{
				/* Col 0*/
				DisableAllCols();
				SetRowsValue(Copy_Data[i]);
				MGPIO_voidSetPinValue(1,cols[i],GPIO_LOW);
				/* Delay 2.5 ms*/
				MSTK_voidSetBusyWait(2000);
			}
		}
		index++;
	}
}

void HLEDMAT_voidInit(void)
{
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_3,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_4,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_5,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_6,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_ROW_7,OUTPUT_2MHZ_PP);

	MGPIO_voidSetPinDirection(HLEDMAT_COL_0,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_1,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_2,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_3,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_4,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_5,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_6,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(HLEDMAT_COL_7,OUTPUT_2MHZ_PP);
}

void HLEDMAT_voidDisplayFrame(u8 *Copy_u8Frame)
{
	while(1)
	{
		/* Col 0*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[0]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);

		/* Col 1*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[1]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);


		/* Col 2*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[2]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_2,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);

		/* Col 3*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[3]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);

		/* Col 4*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[4]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);

		/* Col 5*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[5]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);

		/* Col 6*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[6]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);

		/* Col 7*/
		DisableAllCols();
		SetRowsValue(Copy_u8Frame[7]);
		MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_LOW);
		/* Delay 2.5 ms*/
		MSTK_voidSetBusyWait(2500);
	}
}

static void DisableAllCols(void)
{
	/* Disable All Cols*/
	MGPIO_voidSetPinValue(HLEDMAT_COL_0,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_1,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_2,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_3,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_4,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_5,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_6,GPIO_HIGH);
	MGPIO_voidSetPinValue(HLEDMAT_COL_7,GPIO_HIGH);	
}


static void SetRowsValue  (u8 Copy_u8Value)
{
	u8 Local_u8Bit;

	Local_u8Bit = GET_BIT(Copy_u8Value , 0);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_0,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 1);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_1,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 2);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_2,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 3);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_3,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 4);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_4,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 5);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_5,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 6);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_6,Local_u8Bit);

	Local_u8Bit = GET_BIT(Copy_u8Value , 7);
	MGPIO_voidSetPinValue(HLEDMAT_ROW_7,Local_u8Bit);
}
