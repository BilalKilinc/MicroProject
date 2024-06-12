#include <xc.h>
#include "rc522.h"
#include "spi.h"  // SPI fonksiyonlar?

#define RC522_RST RC2

void RC522_Init(void) {
    RC522_RST = 1;  // RST pinini HIGH yap
    __delay_ms(50);
    RC522_Write(0x01, 0x0F);  // Soft reset
    // Di?er RC522 ba?latma kodlar?...
}

void RC522_Write(unsigned char address, unsigned char value) {
    RA5 = 0;  // SDA (SS) pinini LOW yap
    SPI_Write((address << 1) & 0x7E);
    SPI_Write(value);
    RA5 = 1;  // SDA (SS) pinini HIGH yap
}

unsigned char RC522_Read(unsigned char address) {
    unsigned char value;
    RA5 = 0;  // SDA (SS) pinini LOW yap
    SPI_Write(((address << 1) & 0x7E) | 0x80);
    value = SPI_Read();
    RA5 = 1;  // SDA (SS) pinini HIGH yap
    return value;
}

unsigned char RC522_CheckCard(void) {
    // RFID kart?n? kontrol etmek için gerekli fonksiyonlar
    // Kart bulunduysa 1 döndürün, aksi halde 0 döndürün
    return 1;  // Test amaçl? kart her zaman bulundu olarak kabul edilir
}
