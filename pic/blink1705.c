//
// PIC16F1705 test code for the ESPPIC programmer
// Project located at github.com/SmallRoomLabs/esppic
// Copright (c) 2016 Mats Engstrom SmallRoomLabs
// Released under the MIT license
//

#define _XTAL_FREQ 32000000

#include <xc.h>

// PIC16F1705 Configuration Bit Settings
#pragma config FOSC = INTOSC    // Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover Mode (Internal/External Switchover Mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PPS1WAY = ON     // Peripheral Pin Select one-way control (The PPSLOCK bit cannot be cleared once it is set by software)
#pragma config ZCDDIS = ON      // Zero-cross detect disable (Zero-cross detect circuit is disabled at POR)
#pragma config PLLEN = ON       // Phase Lock Loop enable (4x PLL is always enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LPBOR = OFF      // Low-Power Brown Out Reset (Low-Power BOR is disabled)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#pragma config IDLOC0 = 0x01	// Set the User ID data to some
#pragma config IDLOC1 = 0x23    // values for testing
#pragma config IDLOC2 = 0x45
#pragma config IDLOC3 = 0x56

void main() {
  OSCCON=0b111110000;	// 32MHz
  ANSELA=0;		// Make sure all pins are digital
  ANSELC=0;
  TRISA=0;		// Set all pins as outputs
  TRISC=0;
  for (;;) {		  // Flash 50mS pulses at 1Hz to show some activity
    LATA=rand();
    LATC=rand();
    __delay_ms(200);
  }
}
