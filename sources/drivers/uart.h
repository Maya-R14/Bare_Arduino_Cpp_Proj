#pragma once

void uart_init(void);
void uart_send_char(char c);
void uart_send_string(const char* s);