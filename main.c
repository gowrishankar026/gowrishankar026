/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes



#define GY521_ADDRESS    0X68
static uint8_t who_am_i=0X75;
static uint8_t power=0X6B;
static uint8_t buff[2];

static uint8_t signal_path[10]={0X68,0X07};
static uint8_t sample_rate[10]={0X19,0X00};
static uint8_t config_reg[10]={0X1A,0X00};
static uint8_t gyro_config[10]={0X1B,0X08};
static uint8_t acc_config[10]={0X1C,0X00};

static uint8_t powr_mngt[10]={0X6B,0X01};
static uint8_t acc_config1[10]={0X1C,0X10};
static uint8_t config_reg1[2];


static uint8_t acc_high_xout=0X3B;
void delay(int ms);

// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    SERCOM2_I2C_Initialize();
    SERCOM5_USART_Initialize();
    //int i=0;
   uint8_t data;
   uint8_t data1;
   uint8_t dat;
   uint8_t data2;
   uint8_t data3;
     uint8_t data4,data5,data6,data7,data8,data9;
     
     uint8_t read_buff[14];
     
     int8_t xaxis,yaxis,zaxis,temp;


    while ( true )
    {
     SERCOM2_I2C_Write(GY521_ADDRESS,&who_am_i,1);            //who am i regg
     delay(100);
     
     SERCOM2_I2C_Read(GY521_ADDRESS,&data,1);                 //response  0x68
     delay(100);
      
     SERCOM2_I2C_Write(GY521_ADDRESS,&power,1);               // power management reg 0x6b
     delay(100);
     
     SERCOM2_I2C_Read(GY521_ADDRESS,&data1,1);                //read value 0x40
     delay(100);
     
     buff[0]=0X6B;
     buff[1]=0X00;
     SERCOM2_I2C_Write(GY521_ADDRESS,buff,2);                 // power management reg 0x6b ,set 0xc0
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&buff[0],1);             //power management reg 0x6b
     delay(1000);
    
     SERCOM2_I2C_Read(GY521_ADDRESS,&dat,1);                  //read value 0x00
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,signal_path,2);          // signal path reset reg 0x68 ,set 0x07
     delay(1000);
     SERCOM2_I2C_Write(GY521_ADDRESS,sample_rate,2);          // sample rate reg 0x19 ,set 0x00
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&config_reg[0],1);       //  config_reg 0x1A 
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data2,2);                //response  0x00
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,gyro_config,2);          //  gyro config_reg 0x1B ,set 0x08
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&acc_config[0],1);       //  ACC config_reg 0x1C
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data3,2);                //response  0x00
     delay(100);
      
     SERCOM2_I2C_Write(GY521_ADDRESS,acc_config,2);           //  acc config_reg 0x1C ,set 0x00
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,powr_mngt,2);            //  power mang config_reg 0x6b ,set 0x01
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&acc_config[0],1);       //  ACC config_reg 0x1C
     delay(100);
    
     SERCOM2_I2C_Read(GY521_ADDRESS,&data4,2);                //response  0x00
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,acc_config1,2);          //  acc config_reg 0x1C ,set 0x10
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&acc_config[0],1);       //  ACC config_reg 0x1C
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data5,2);                //response  0x10
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&gyro_config[0],1);      //  gyro config_reg 0x1B
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data6,2);                //response  0x00
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,gyro_config,2);          //  gyro config_reg 0x1A ,set 0x08
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&gyro_config[0],1);      //  gyro config_reg 0x1B
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data7,2);                //response  0x08
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,& config_reg[0],1);      //  config_reg 0x1A 
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data8,2);                //response  0x00
     delay(100);
     config_reg1[0]=0X1A;
     config_reg1[1]=0X04;
     SERCOM2_I2C_Write(GY521_ADDRESS,config_reg1,2);          //  config_reg 0x1A ,set 0x04
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,& config_reg[0],1);      //  config_reg 0x1A 
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,&data9,2);                //response  0x04
     delay(100);
     
     
     
 

     SERCOM2_I2C_Write(GY521_ADDRESS,&acc_high_xout,1);      //acc high reg
     delay(100);
     SERCOM2_I2C_Read(GY521_ADDRESS,read_buff,14);           //read reg value
     delay(100);
     
     
     xaxis=(int16_t)read_buff[0]<<8|read_buff[1];
     yaxis=(int16_t)read_buff[2]<<8|read_buff[3];
     zaxis=(int16_t)read_buff[4]<<8|read_buff[5];
     temp=(int16_t)read_buff[6]<<8|read_buff[7];
              
               printf("x=axis:%d\r\n",xaxis);
               printf("y=axis:%d\r\n",yaxis);
               printf("z=axis:%d\r\n",zaxis);
               printf("temp:%d\r\n",temp);
               delay(100);
               
     SERCOM2_I2C_Write(GY521_ADDRESS,&acc_config[0],1);        //  ACC config_reg 0x1C
     SERCOM2_I2C_Read(GY521_ADDRESS,&data,2);                    //read  0x10
     delay(100);
     
     SERCOM2_I2C_Write(GY521_ADDRESS,&gyro_config[0],1);        //  gyro config_reg 0x1B
     SERCOM2_I2C_Read(GY521_ADDRESS,&data,2);                    //read  0x08
     delay(100);
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        SYS_Tasks ( );
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}

void delay(int ms)
{
    int i;
    for(i=0;i<ms;i++)
    {
        TC0_TimerStart( );
        while(!TC0_TimerPeriodHasExpired())
        {
        }
       TC0_TimerStop( );
    }
}

/*******************************************************************************
 End of File
*/

