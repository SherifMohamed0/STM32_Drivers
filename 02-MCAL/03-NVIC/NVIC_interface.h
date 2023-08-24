/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 19 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Functions Definations */
void MNVIC_voidInit(void);
void MNVIC_voidSetPriority(u8 Copy_u8PeriphralIdx , u8 Copy_u8Priority);
void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidDisbleInterrupt  (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);



#endif
