#include "drivers/uart.h"
#include <util/delay.h>

int main(void) {
    uart_init();

    while (1) {
        #ifdef DEBUG
            uart_send_string("Debug mode is enabled.\r\n");
        #endif

        #ifdef RELEASE  
            uart_send_string("Release mode is enabled.\r\n");
        #endif

         uart_send_string("Hello, Nano!\r\n");
         _delay_ms(1000);
     }
}
