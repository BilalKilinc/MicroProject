#ifndef RC522_H
#define RC522_H

#define _XTAL_FREQ 20000000  // Kristal frekans? 20MHz

void RC522_Init(void);
unsigned char RC522_CheckCard(void);
void RC522_Write(unsigned char, unsigned char);
unsigned char RC522_Read(unsigned char);

#endif // RC522_H
