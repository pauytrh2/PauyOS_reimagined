// keyboard.c

#include "keyboard.h"
#include "print.h"
#include <stdint.h>

void disable_cursor() {
    outb(0x3D4, 0x0A);
    outb(0x3D5, 0x20);
}

static const char scancode_to_ascii[] = {
    0,  27, '1','2','3','4','5','6','7','8','9','0','-','=', '\b', // 0x00 - 0x0E
    '\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',     // 0x0F - 0x1C
    0,   'a','s','d','f','g','h','j','k','l',';','\'','`',         // 0x1D - 0x29
    0,  '\\','z','x','c','v','b','n','m',',','.','/',              // 0x2A - 0x35
    0,   '*', 0,  ' '                                              // 0x36 - 0x39
};

void keyboard_loop() {
    while (1) {
        if (inb(0x64) & 1) { // if there is data in buffer
            uint8_t scancode = inb(0x60);

            if (scancode < sizeof(scancode_to_ascii)) {
                char c = scancode_to_ascii[scancode];
                if (c) {
                    char str[2] = {c, '\0'};
                    print_str(str);
                }
            }
        }
    }
}