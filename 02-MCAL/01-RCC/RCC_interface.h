/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 14 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/* Functions Definitions*/
void RCC_voidInit(void);
void RCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId);

/* Buses Definitions*/
#define AHB   0
#define APB1  1
#define APB2  2

#endif