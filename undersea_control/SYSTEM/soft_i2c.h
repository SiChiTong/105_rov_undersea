#ifndef __SOFT_I2C__
#define __SOFT_I2C__
#include "sys.h"

#define I2C_GPIO_GROUP GPIOB
#define SDA_IN()  {I2C_GPIO_GROUP->CRH&=0XFFFF0FFF;I2C_GPIO_GROUP->CRH|=0X00008000;}
#define SDA_OUT() {I2C_GPIO_GROUP->CRH&=0XFFFF0FFF;I2C_GPIO_GROUP->CRH|=0X00003000;}

//IO��������	 
#define IIC_SCL    PBout(10) 		//SCL
#define IIC_SDA    PBout(11) 		//SDA	 
#define READ_SDA   PBin(11) 	 		//����SDA 

//IIC���в�������
void IIC_Init(void);                //��ʼ��IIC��IO��				 
void IIC_Start(void);				//����IIC��ʼ�ź�
void IIC_Stop(void);	  			//����IICֹͣ�ź�
void IIC_Send_Byte(u8 txd);			//IIC����һ���ֽ�
u8 IIC_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
u8 IIC_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC_Ack(void);					//IIC����ACK�ź�
void IIC_NAck(void);				//IIC������ACK�ź�

uint8_t I2C_ArrayRead(uint8_t SlaveAddress,uint8_t REG_Address,uint8_t *buff,uint8_t length);
void I2C_CmdWrite(uint8_t SlaveAddress,uint8_t command);
uint16_t I2C_ByteRead16(uint8_t SlaveAddress,uint8_t REG_Address);

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);


#endif
