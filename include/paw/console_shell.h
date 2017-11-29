/*
 * shell.h
 * ! this module depend console !
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

enum paw_shell_command_type { NONE, UNRECOGNIZED, AMBIGUOUS, CONTEXT, CONFIG, UP_TO_CONTEXT, COMMIT, WRITE };

#endif
