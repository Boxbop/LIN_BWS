/*
**
****************************************************************************
**
**
**
**             Copyright (c) 2003, 2004 - Atmel Corporation
**             Proprietary Information
**
** Project    	: AVR LIN SLAVE EXAMPLE
** Module     	: main.C
** Description	: main application
**                Compatible with LIN Specifications 1.3
**
**
**
** Version :     Date:         Author:      Comment:
**    1.0        19.01.2004    E.G.          Creation
**
**
**
**              Assumes 8MHz external oscillator
**
**
**
** LICENSE -
**
** ATMEL - 2003,2004
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


/*__________________________________________________________________________*/
/*_____ I N C L U D E S ____________________________________________________*/
/*__________________________________________________________________________*/
#include "config.h"
#include "lib_mcu/lin_uart/slave_lin.h"
#include "lib_mcu/lin_uart/lin_lib.h"
#include "inavr.h"

U8 Buf_SET_SLAVE [4];
U8 Buf_GET_SLAVE [4];


/* ************************************************************************** */
/*
** Description :	The main C function.  Program execution starts here.
**
** ------------------------------------------------------------------------------
*/
void main (void) {
  t_frame MESS_SET_SLAVE;
  t_frame MESS_GET_SLAVE;
  U8 number_of_frame ;

  //no system clock divider
  CLKPR   = 0x80; CLKPR   = 0x00;

  //SET SLAVE FRAME
  MESS_SET_SLAVE.frame_id    = 0x00 ;
  MESS_SET_SLAVE.frame_size  = 4 ;
  MESS_SET_SLAVE.frame_type  = 0 ;
  MESS_SET_SLAVE.frame_data  = Buf_SET_SLAVE;

  //GET SLAVE 0 FRAME DEFINITION
  MESS_GET_SLAVE.frame_id   = 0x01;
  MESS_GET_SLAVE.frame_size = 4;
  MESS_GET_SLAVE.frame_type = 1;
  MESS_GET_SLAVE.frame_data = Buf_GET_SLAVE;


  number_of_frame = 2;
  my_schedule.frame_message[0] = MESS_SET_SLAVE;
  my_schedule.frame_message[1] = MESS_GET_SLAVE;
  my_schedule.number_of_frame = number_of_frame;

  CONFIG_IO_PORTS();

  // Initialise LIN Controller
  lin_init();// Performs Initialisation of LIN Software Driver

  SREG |= 0x80; /* Interrupts globally enabled */

  while(1) {
    if(Buf_SET_SLAVE[0] == 0x01){
      SET_LED();
      Buf_GET_SLAVE[0] = 0x01;
    }
    else{
      RESET_LED();
      Buf_GET_SLAVE[0] = 0x00;
    }

  }//while(1)
}//main




