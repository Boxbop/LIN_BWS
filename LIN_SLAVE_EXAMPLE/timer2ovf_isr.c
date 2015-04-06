/*
**
****************************************************************************
**
**
**             Copyright (c) 2004 - Atmel Corporation
**             Proprietary Information
**
** Project    	: AVR LIN SLAVE EXAMPLE
** Module     	: timer_2_isr.c
** Description	: timer 2 overflow interrupt subroutine
**
**
** Version :     Date:         Author:      Comment:
**    1.0        5.01.2005     E.G.          Creation
**    1.1        13.04.2005    E.G.          lin err value changed
**
**
**          Assumes 8MHz System Frequency
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

/*_____ I N C L U D E S ____________________________________________________*/
#include "config.h"
#include "lib_mcu/timer/timer2_lib.h"
#include "lib_mcu/lin_uart/lin_drv_usart.h"
#include "lib_mcu/lin_uart/slave_lin.h"
#include "lib_mcu/lin_uart/runtime_calibration_lib.h"

/*_____ M A C R O S ________________________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/


//**************************************************************************
// Timer overflow interrupt service routine for LIN time-out detection
//
// occurs if lin slave time-out detected (header and/or data)
//
//**************************************************************************
//#pragma optimize=z 2  // Force no optimization for this ISR.
#pragma vector= TIMER2_OVF_vect
__interrupt void TIMER2_Overflow_ISR (void){
#ifdef _TIMOUT_DETECTION
  Timer2_stop();
  Uart_set_baudrate(UART_BAUDRATE_SYNC);
  _lin_state = STATE_CHECK_BREAK;
  _lin_err = MSK_STATUS_TIME_OUT; //changed eg 13/04/2005
  _lin_status = MSK_STATUS_ERR;
#endif

#ifdef _RUN_TIME_RC_CALIBRATION_ENABLE
  Timer_stop_capture(); // stop autocalibration sequence
#endif
}
