// main.c

#include "print.h"
#include "keyboard.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_LIGHT_BLUE, PRINT_COLOR_BLACK);
    print_str("Welcome to PauyOS Reimagined!\n\n");

    // keyboard module test
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("Keyboard input test:\n\n");

    keyboard_loop();
}