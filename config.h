/* 
 * File:   config.h
 * Author: Phil
 *
 * Created on 04 May 2018, 21:11
 */

#ifndef CONFIG_H
#define	CONFIG_H
// PIC16F1459 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config CPUDIV = CLKDIV6 // CPU System Clock Selection Bit (CPU system clock divided by 6)
#pragma config USBLSCLK = 48MHz // USB Low SPeed Clock Selection bit (System clock expects 48 MHz, FS/LS USB CLKENs divide-by is set to 8.)
#pragma config PLLMULT = 3x     // PLL Multipler Selection Bit (3x Output Frequency Selected)
#pragma config PLLEN = DISABLED // PLL Enable Bit (3x or 4x PLL Disabled)
#pragma config STVREN = OFF     // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will not cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdbool.h>
#define _XTAL_FREQ 4000000      // 4MHz internal clock frequency
#define SWIP PORTAbits.RA0      // pin 19 swip
#define DT PORTAbits.RA1        // DT input of rotary encoder
#define CLK PORTAbits.RA4       // CLK input of rotary encoder
#define LED PORTCbits.RC1       // pin 15 RC1
typedef unsigned char uchar;
// *****************aliases for PORT pins********************************
#define SCK PORTBbits.RB6       // serial clock pin 11
#define SDO PORTCbits.RC7       // serial data out pin 9
#define RST PORTCbits.RC5       // RESET pin 5
#define DC  PORTCbits.RC6       // D/C data/ command pin 8
#define CS  PORTAbits.RA5       // chip select (active low) pin 2



/********debounce constants*******/
enum buttonPos {pressed, notPressed};     // encoder switch - pressed = 0, notPressed = 1
enum buttonPos button = notPressed;         // variable button of data type buttonPos is given the value notPressed



/*******************global variables************/


enum dbStates {off, bouncingOn, on, bouncingOff};   // the four states of the debounce state machine
                                                    // off = 0, bouncingOn = 1, on = 2, bouncingOff = 3
enum dbStates currentState = off;

#endif	/* CONFIG_H */

