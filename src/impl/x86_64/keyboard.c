// keyboard.c

#include "keyboard.h"
#include "print.h"
#include "shell.h"
#include <stdint.h>

#define INPUT_BUFFER_SIZE 128
static char input_buffer[INPUT_BUFFER_SIZE];
static int input_index = 0;

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

void keyboard_loop() { // TODO declutter this into seperate funcs
    while (1) {
        if (inb(0x64) & 1) {
            uint8_t scancode = inb(0x60);

            if (scancode < sizeof(scancode_to_ascii)) {
                char c = scancode_to_ascii[scancode];
                if (c) {
                    if (c == '\b') {
                        if (input_index > 0) {
                            input_index--;
                            input_buffer[input_index] = '\0';
                            // print_str("\b \b");  // ! broken and prints out weird ascii shit instead of earsing previous char
                        }
                    } else if (c == '\n') {
                        input_buffer[input_index] = '\0';
                        print_str("\n");
                        process_command(input_buffer);
                        input_index = 0;
                        print_prompt_command();
                    } else {
                        if (input_index < INPUT_BUFFER_SIZE - 1) {
                            input_buffer[input_index++] = c;
                            char str[2] = {c, '\0'};
                            print_str(str);
                        }
                    }
                }
            }
        }
    }
}