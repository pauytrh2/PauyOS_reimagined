// main.c

#include "print.h"
#include "keyboard.h"
#include "shell.h"

void kernel_main() {
    disable_cursor();
    print_clear();
    print_set_color(PRINT_COLOR_LIGHT_BLUE, PRINT_COLOR_BLACK);
    print_str("Welcome to PauyOS Reimagined!\n");
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    print_str("You will now be placed into the basic shell that comes with this kernel.\n\n");

    // keyboard module test
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str(PROMPT);

    keyboard_loop();
}