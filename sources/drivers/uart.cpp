#include "uart.h"
#include <avr/io.h>
#include <util/delay.h>

/**
 * @file uart.cpp
 * @brief Implementation of the AVR UART driver.
 *
 * Configures and uses the ATmega328P/Arduino-compatible UART peripheral for
 * serial transmission.
 */

// WORKS WITH ARDUINO AVR
#define BAUD 115200
#define UBRR_VALUE ((F_CPU / (8UL * BAUD)) - 1)  // note 8 for double speed

/**
 * @brief Initialize the UART controller.
 *
 * Enables double-speed mode, calculates the baud rate register value, enables
 * the transmitter, and configures 8-bit asynchronous serial output.
 */
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

/**
 * @brief Send a single character over the UART.
 *
 * @param c Character to transmit.
 */
void uart_send_char(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

/**
 * @brief Send a null-terminated string over the UART.
 *
 * @param s Pointer to the string to transmit.
 */
void uart_send_string(const char* s) {
    while (*s) uart_send_char(*s++);
}
