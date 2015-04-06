/*
**
****************************************************************************
**
**
**             Copyright (c) 2005 - Atmel Corporation
**             Proprietary Information
**
** LICENSE -
**
** ATMEL - 2005
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

#ifndef _BOARD_H
#define _BOARD_H

/*_____ D E F I N I T I O N S ______________________________________________*/

//----------------------------------------------------------------------//
//                     MCU PORT DECLARATION                             //
//----------------------------------------------------------------------//

//PORTB
#define _LIN_RXD             0x01  //PB0(ICP1/CLKO/PCINT0) *
#define _LED                 0x02  //PB1(OC1A/PCINT1) *
#define _PB2                 0x04  //PB2(OC1B/SS/PCINT2) *
#define _MOSI                0x08  //PB3(MOSI/OC2A/PCINT3)
#define _MISO                0x10  //PB4(MISO/PCINT4)
#define _SCK                 0x20  //PB5(SCK/PCINT5)
#define _PB6                 0x40  //PB6(TOSC1/XTALL1/PCINT6) * not connected
#define _PB7                 0x80  //PB7(TOSC2/XTAL2/PCINT7) * not connected

//PORTC
#define _PC0                  0x01  //PC0(ADC0/PCINT8) *
#define _PC1                  0x02  //PC1(ADC1/PCINT9) *
#define _PC2                  0x04  //PC2(ADC2/PCINT10) *
#define _PC3                  0x08  //PC3(ADC3/PCINT11) *
#define _PC4                  0x10  //PC4(ADC4/SDA/PCINT12) * not connected
#define _LIN_SLEEP            0x20  //PC5(ADC5/SCL/PCINT13) *
#define _NRESET               0x40  //PC6(RESET/PCINT14)

//PORTD
#define _LIN_RXD_A            0x01  //PD0(RXD/PCINT16) *
#define _LIN_TXD              0x02  //PD1(TXD/PCINT17) *
#define _PD2                  0x04  //PD2(INT0/PCINT18) *
#define _PD3                  0x08  //PD3(INT1/OC2B/PCINT19) *
#define _PD4                  0x10  //PD4(T0/XCK/PCINT20) *
#define _PD5                  0x20  //PD5(T1/OC0B/PCINT21) *
#define _PD6                  0x40  //PD6(AIN0/OC0A/PCINT22) *
#define _PD7                  0x80  //PD7(AIN1/PCINT2) *


//----------------------------------------------------------------------//
//                     MCU SPECIFIC ENABLE/DISABLE MACROS               //
//----------------------------------------------------------------------//
#define ENABLE_LIN()          (DDRC|=_LIN_SLEEP , PORTC |=_LIN_SLEEP)
#define DISABLE_LIN()         (DDRC |=_LIN_SLEEP , PORTC &=~_LIN_SLEEP)

//----------------------------------------------------------------------//
//                     MCU PORT CONFIG MACROS                           //
//----------------------------------------------------------------------//

#define  CONFIG_PORTB() (DDRB   = _MISO | _LED , PORTB =  _LIN_RXD )
#define  CONFIG_PORTC() (DDRC   = _LIN_SLEEP ,  PORTC  = _LIN_SLEEP )
#define  CONFIG_PORTD() (DDRD   = _LIN_TXD , PORTD  = _LIN_TXD | _LIN_RXD_A )

#define  CONFIG_IO_PORTS() (CONFIG_PORTB(),CONFIG_PORTC() ,CONFIG_PORTD())

//----------------------------------------------------------------------//
//                     MCU I/O MACROS                            //
//----------------------------------------------------------------------//
#define SET_LIN_TXD()             (PORTD |= _LIN_TXD )
#define SET_LED()                 (PORTB |= _LED )
#define RESET_LED()               (PORTB &= ~_LED )

#define RESET_LIN_TXD()            (PORTD &= ~_LIN_TXD )

#endif  /* _BOARD_H */




