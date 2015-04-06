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

//PORTA
#define _PUSH1          0x01 //PA0/AD0
#define _PA1            0x02 //PA1/AD1
#define _PA2            0x04 //PA2/AD2
#define _PA3            0x08 //PA3/AD3
#define _PA4            0x10 //PA4/AD4
#define _PA5            0x20 //PA5/AD5
#define _PA6            0x40 //PA6/AD6
#define _PA7            0x80 //PA7/AD7

//PORTB
#define _PB0            0x01 //PB0 / SS
#define _PB1            0x02 //PB1 / SCK
#define _PB2            0x04 //PB2 / MOSI
#define _PB3            0x08 //PB3 / MISO
#define _PB4            0x10 //PB4 / OC2A
#define _PB5            0x20 //PB5 / OC1A
#define _PB6            0x40 //PB6 / OC1B
#define _PB7            0x80 //PB7 / OC0A/OC1C

//PORTC
#define _LIN_SLEEP      0x01  //PC0/A8
#define _PC1            0x02  //PC1/A9
#define _PC2            0x04  //PC2/A10
#define _PC3            0x08  //PC3/A11
#define _PC4            0x10  //PC4/A12
#define _PC5            0x20  //PC5/A13
#define _PC6            0x40  //PC6/A13
#define _PC7            0x80  //clock output

//PORTD
#define _PD0            0x01  //PD0/SCL/INT0
#define _PD1            0x02  //PD1/SDA/INT1
#define _LIN_RXD_A      0x04  //PD2/RxD1/INT2
#define _LIN_TXD        0x08  //PD3/TxD1/INT3
#define _LIN_RXD_B      0x10  //PD4/IC1
#define _PD5            0x20  //PD5/XCK1/TxCAN
#define _PD6            0x40  //PD6/T1/RxCAN
#define _GREEN_LED      0x80  //PD7/T0

//PORTE
#define _PE0            0x01  //PE0/RxD0/PDI
#define _PE1            0x02  //PE1/TxD0/PDO
#define _PE2            0x04  //PE2/XCK0/AIN0
#define _PE3            0x08  //PE3/OC3A/AIN1
#define _PE4            0x10  //PE4/OC3B/INT4
#define _PE5            0x20  //PE5/OC3C/INT5
#define _PE6            0x40  //PE6/T3/INT6
#define _PE7            0x80  //PE7/IC3/INT7

//PORTF
#define _PF0           0x01  //PF0 ADC
#define _PF1           0x02  //PF1 ADC
#define _PF2           0x03  //PF2 ADC
#define _PF3           0x04  //PF3 ADC
#define _PF4           0x10  //PF4 JTAG
#define _PF5           0x20  //PF5 JTAG
#define _PF6           0x40  //PF6 JTAG
#define _PF7           0x80  //PF7 JTAG

//PORTG
#define _PG0      0x01  //PG0/WR
#define _PG1      0x02  //PG1/RD
#define _PG2      0x02  //PG2/ALE
#define _PG3      0x08  //PG3/TOSC2
#define _PG4      0x10  //PG4/TOSC1

//----------------------------------------------------------------------//
//                     MCU SPECIFIC ENABLE/DISABLE MACROS               //
//----------------------------------------------------------------------//
#define ENABLE_LIN()          (DDRC |=_LIN_SLEEP , PORTC  |=_LIN_SLEEP)
#define DISABLE_LIN()         (DDRC |=_LIN_SLEEP , PORTC &=~_LIN_SLEEP)

//----------------------------------------------------------------------//
//                     MCU PORT CONFIG MACROS                           //
//----------------------------------------------------------------------//

#define  CONFIG_PORTA() (DDRA   = 0x00)
#define  CONFIG_PORTB() (DDRB   = 0x00)
#define  CONFIG_PORTC() (DDRC   = _LIN_SLEEP )
#define  CONFIG_PORTD() (DDRD   = _GREEN_LED   | _LIN_TXD ,  PORTD  = _LIN_TXD | _LIN_RXD_A | _LIN_RXD_B )
#define  CONFIG_PORTE() (DDRE   = DDRE  )
#define  CONFIG_PORTF() (DDRF   = DDRF )
#define  CONFIG_PORTG() (DDRG   = DDRG )

#define CONFIG_IO_PORTS() ( CONFIG_PORTA(),  CONFIG_PORTB(),  CONFIG_PORTC(),  CONFIG_PORTD(), CONFIG_PORTE(), CONFIG_PORTF(),CONFIG_PORTG())

//----------------------------------------------------------------------//
//                        MCU I/O MACROS                                //
//----------------------------------------------------------------------//
#define SET_GREEN_LED()         (PORTD |= _GREEN_LED )
#define SET_LIN_TXD()           (PORTD |= _LIN_TXD )

#define RESET_GREEN_LED()       (PORTD &= ~_GREEN_LED )
#define RESET_LIN_TXD()         (PORTD &= ~_LIN_TXD )

#define TOGGLE_GREEN_LED()      (PORTD ^= _GREEN_LED )
#define TOGGLE_LIN_TXD()        (PORTD ^= _LIN_TXD )

#define _TEST_PUSH1()           (PINA & _PUSH1 )

/*_____ D E C L A R A T I O N S ____________________________________________*/

#endif  /* _BOARD_H */



