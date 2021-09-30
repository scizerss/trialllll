/*
* TWI.c
*
* Created: 2/20/2021 8:57:13 PM
*  Author: karim
*/

#include "TWI.h"

void TWI_MASTER_Init(void)
{
	TWBR = 0x0C;/*Prescaler of the clock*/
	SET_BIT(TWCR, TWEN);/*Enable Two wire Interface*/
}
void TWI_SLAVE_Init(void)
{
	/*Set address for slave*/
	TWAR = (0x01 << 1); /*Disable general call*/
	SET_BIT(TWCR, TWEA);/*Slave enable acknowledgment*/
	SET_BIT(TWCR, TWEN);/*Enable Two wire Interface*/
}
void TWI_START_Condition(void)
{
	SET_BIT(TWCR, TWSTA);/*Start condition*/
	SET_BIT(TWCR, TWINT);/*Hard set for flag waiting for dominant bit (0)*/
	while(GET_BIT(TWCR, TWINT) != 0);/*When start condition finished*/
	while((TWSR & 0xF8) != START_ACK);/*Waiting for master send start condition*/
}
void TWI_REPEATED_Condition(void)
{
	TWCR = (1 << 7) | (1 << 5) | (1 << 2);
	SET_BIT(TWCR, TWINT);/*Hard set for flag waiting for dominant bit (0)*/
	while(GET_BIT(TWCR, TWINT) != 0);/*When start condition finished*/
	while((TWSR & 0xF8) != REP_START_ACK);/*Waiting for master send start condition*/
}
void TWI_SLAVE_WRITE_Data(uint8_t address)
{
	TWDR = (address << 1) | (0x00);/*Send address of chosen slave, Write*/
	TWCR = (1 << 7) | (1 << 2);
	while(GET_BIT(TWCR, TWINT) != 0);/*When start condition finished*/
	while((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK);/*Waiting for slave send start ACK*/
}
void TWI_SLAVE_READ_Data(uint8_t address)
{
	TWDR = (address << 1) | (0x01);/*Send address of chosen slave, Read*/
	TWCR = (1 << 7) | (1 << 2);
	while(GET_BIT(TWCR, TWINT) != 0);/*When start condition finished*/
	while((TWSR & 0xF8) != SLAVE_ADD_AND_RD_ACK);/*Waiting for slave send start ACK*/
}
void TWI_TRANSMIT_Data(uint8_t data)
{
	TWDR = data;
	TWCR = (1 << 7) | (1 << 2);
	while(GET_BIT(TWCR, TWINT) != 0);/*When start condition finished*/
	while((TWSR & 0xF8) != WR_BYTE_ACK);/*Waiting for slave send start ACK*/
}
uint8_t TWI_RECEIVE_Data(void)
{
	TWCR = (1 << 7) | (1 << 2);
	while(GET_BIT(TWCR, TWINT) != 0);/*When start condition finished*/
	while((TWSR & 0xF8) != RD_BYTE_WITH_ACK);/*Waiting for slave send start ACK*/
	return TWDR;
}
void TWI_STOP_Condition(void)
{
	SET_BIT(TWCR, TWSTO);/*Send stop condition*/
}