/*
**
****************************************************************************
**
**
**             Copyright (c) 2004 - Atmel Corporation
**             Proprietary Information
**
** Project    	: AVR LIN SLAVE EXAMPLE
** Module     	: config.h
** Description	: configuration header file
**
**
** Version :     Date:         Author:      Comment:
**    1.0        5.1.2005    E.G.          Creation
**
**
**
**
**
**
** LICENSE -
**
** ATMEL - 2004
** All software programs are provided 'as is' without warranty of any kind:
** Atmel does not state the suitability of the provided materials for any
** purpose. Atmel hereby disclaim all warranties and conditions with regard
** to the provided software, including all implied warranties, fitness for
** a particular purpose, title and non-infringement.In no event will Atmel
** be liable for any indirect or consequential damages or any damages
** whatsoever resulting from the usage of the software program.
****************************************************************************
**
*/


//#define AT90CAN128_USED
//#define ATMEGA168_USED
#define ATMEGA88_USED
//#define ATMEGA48_USED


#ifdef ATMEGA168_USED
#include <iom168.h>
#include "lib_board/board_example_mega168.h"
#define  USE_UART1
#endif

#ifdef ATMEGA88_USED
#include <iom88.h>
#include "lib_board/board_example_mega88.h"
#define  USE_UART1
#endif

#ifdef ATMEGA48_USED
#include <iom48.h>
#include "lib_board/board_example_mega48.h"
#define  USE_UART1
#endif

#ifdef AT90CAN128_USED
#include "lib_board/board_example_AT90CAN128.h"
#include <iocan128.h>
//#define  USE_UART1
#define  USE_UART2
//#define DISPLAY_ENABLED //for lcd
#endif

/*_____ LIN LIBRARY configuration ______*/
#define LIN_BAUDRATE 19200
//#define LIN_BAUDRATE 9600
//#define LIN_BAUDRATE 2400
#define LIN_CONFIG 1 //1:slave 0:master
#define FOSC 8000 // in kHz, only 8MHZ is supported

#ifndef _CONFIG_H_
#define _CONFIG_H_

/*_____ M A C R O S ________________________________________________________*/
/*_____ D E F I N I T I O N ________________________________________________*/
#define TRUE 1
/*_____ D E C L A R A T I O N S ____________________________________________*/
typedef unsigned char U8;
typedef unsigned int U16 ;
typedef signed int S16;
typedef signed long S32;
typedef unsigned long U32;



#endif  /* CONFIG_H */


