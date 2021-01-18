#include <stddef.h>
#include <stdint.h>
#include <kernel/uart.h>

void kernel_main(uint32_t r0, uint32_t r1, uint32_t atags)
{
    (void) r0;
    (void) r1;
    (void) atags;

    uart_init();
    uart_puts("Hello, kernel World!\r\n");
    delay(150);
    uart_puts("Terminating\n");
    while (1) {
        uart_putc(uart_getc());
        uart_puts('\n');
    }
}