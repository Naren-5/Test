/*
 * File:   Led_blink.c
 * Author: Narendran
 *
 * Created on January 25, 2019, 12:16 PM
 */


// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define _XTAL_FREQ 4000000 

#define Led1 RB1
#define Led2 RB2
#define Led3 RB3
#define Led4 RB4

void main(void) {
    PORTB=0x00;
    TRISB=0x00;
    ANSEL=0x00;
    ANSELH=0x00;
    while(1)
    {
        Led1=1;
        Led2=0;
        Led3=0;
        Led4=0;
        __delay_ms(1000);
        Led1=0;
        Led2=1;
        Led3=0;
        Led4=0;
        __delay_ms(1000);
        Led1=0;
        Led2=0;
        Led3=1;
        Led4=0;
        __delay_ms(1000);
        Led1=0;
        Led2=0;
        Led3=0;
        Led4=1;
        __delay_ms(1000);
    }
    return;
}
