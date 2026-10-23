// shell.c

#include "shell.h"
#include "print.h"
#include "utils.h"

const char *PROMPT = "> ";

void print_prompt_command() {
    print_str(PROMPT);
}

void process_command(const char* input) {
    if (strcmp(input, "help") == 0) {
        print_str("Available commands:\n");
        print_str("help - Show this message\n");
        print_str("clear - Clear the screen\n");
    } else if (strcmp(input, "clear") == 0) {
        print_clear();
    } else if (strcmp(input, "") == 0) {
        // do nothing
    } else {
        print_str("Unknown command. Type 'help' to see all commands.\n");
    }
}