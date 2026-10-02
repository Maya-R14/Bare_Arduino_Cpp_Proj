#pragma once

/**
 * @file uart.h
 * @brief UART driver interface for Arduino AVR devices.
 *
 * Provides the public API for initializing and transmitting data over the
 * hardware UART peripheral.
 */

/**
 * @brief Initialize the UART peripheral.
 *
 * Configures the baud rate, double-speed mode, and transmitter settings for
 * the AVR hardware UART.
 */
void uart_init(void);

/**
 * @brief Send a single character over UART.
 *
 * Waits until the transmit buffer is ready and then writes the byte.
 *
 * @param c Character to transmit.
 */
void uart_send_char(char c);

/**
 * @brief Send a null-terminated string over UART.
 *
 * Iterates over the string and transmits each character until the terminating
 * null byte is reached.
 *
 * @param s Pointer to the string buffer to transmit.
 */
void uart_send_string(const char* s);