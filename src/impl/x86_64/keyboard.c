// keyboard.c

#include "keyboard.h"
#include "print.h"

void keyboard_loop() {
    while (1) {
        if (inb(0x64) & 1) { // if there is data in buffer
            uint8_t scancode = inb(0x60);
            print_str("Scancode: ");
            char hex[3];
            hex[0] = "0123456789ABCDEF"[scancode >> 4];
            hex[1] = "0123456789ABCDEF"[scancode & 0x0F];
            hex[2] = '\0';
            print_str(hex);
            print_str("\n");
        }
    }
}