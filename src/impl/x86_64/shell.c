// shell.c

#include "shell.h"
#include "print.h"

char *PROMPT = "$$ ";

void print_prompt_command() {
    print_str(PROMPT);
}