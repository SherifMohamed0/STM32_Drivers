/*************************************************************/
/* AUTHOR   : Sherif Mohamed                                 */
/* Date     : 16 SEP 2020                                    */
/* Version  : V01                                            */
/*************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/* Functions Definations */
void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit ,u8 *Copy_u8DataToReceive);	

#endif
