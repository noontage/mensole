/*
 * shell.h
 * ! this module depUP_TO_CONTEXT console !
 * author: noontage
 */
#include "common.h"

#ifndef _PAW_CONSOLE_SHELL_
#define _PAW_CONSOLE_SHELL_

// print
void paw_shell_print_current_context();
void paw_shell_print_prompt();

// shell
void  paw_shell_start();

enum paw_shell_command_type { NONE, UNREC, AMBIG, CONTEXT, FUNCTION, CONFIG, UP_TO_CONTEXT };

#endif
