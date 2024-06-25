// CONFIG
#pragma config FOSC = HS// Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF  // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit
                          // (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF  // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF  // Flash Program Memory Write Enable bits
                          // (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF   // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include "I2C_LCD.h"

void main(void) {

    I2C_Master_Init();
    LCD_Init(0x4E); // Initialize LCD module with I2C address = 0x4E

    LCD_Set_Cursor(1, 1);
    LCD_Write_String(" deneme");
    LCD_Set_Cursor(2, 1);
    LCD_Write_String(" basarili");

    while(1)
    {

        }
    return;
}
