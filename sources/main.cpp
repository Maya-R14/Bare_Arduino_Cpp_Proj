#include <avr/io.h>
#include <util/delay.h>

//WORKS WITH ARDUINO AVR
#define BAUD 115200
#define UBRR_VALUE ((F_CPU / (8UL * BAUD)) - 1)  // note 8 for double speed
  //              "__AVR_ATmega328P__"

void uart_init(void) {
    // Enable double-speed mode
    UCSR0A = (1 << U2X0);

    // Set baud rate
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)(UBRR_VALUE);

    // Enable transmitter
    UCSR0B = (1 << TXEN0);

    // 8 data bits, 1 stop bit, no parity
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_char(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

void uart_send_string(const char* s) {
    while (*s) uart_send_char(*s++);
}

int main(void) {
    uart_init();

    while (1) {
         uart_send_string("Hello, Nano!\r\n");
         _delay_ms(1000);
     }
}
