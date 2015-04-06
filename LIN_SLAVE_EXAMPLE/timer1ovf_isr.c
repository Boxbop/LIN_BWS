/*
**
****************************************************************************
**
**
**             Copyright (c) 2004 - Atmel Corporation
**             Proprietary Information
**
** Project    	: AVR LIN SLAVE EXAMPLE
** Module     	: timer1_ovf.c
** Description	: Timer 1 overflow ISR
**
**
** Version :     Date:         Author:      Comment:
**    1.0        5.1.2005    E.G.          Creation
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

/*_____ I N C L U D E S ____________________________________________________*/
#include "config.h"
#include "lib_mcu/lin_uart/slave_lin.h"


/*_____ M A C R O S ________________________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/


//**************************************************************************
// Timer overflow interrupt service routine
//
// Overflow Rate is Tbit -  2400 Tbit  = 416us
//                          4800 Tbit  = 208us
//                          9600 Tbit  = 104us
//                          19200 Tbit = 52us
//
//**************************************************************************
#pragma optimize=z 2  // Force no optimization for this ISR.
#pragma vector= TIMER1_OVF_vect
__interrupt void TIMER1_Overflow_ISR (void){

  TCNT1H = _8MHZ_TCNT1H;  /* Reload: Set Timer Value for a Tbit overflow */
  TCNT1L = _8MHZ_TCNT1L;

  l_sch_tick();
}
