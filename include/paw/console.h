/*
 * console.h
 *
 * author: noontage
 */
#include "common.h"

#ifndef _PAW_CONSOLE_
#define _PAW_CONSOLE_

// basico io
void  paw_console_puts(const paw_string str);
void  paw_console_print(const paw_string str);
paw_string paw_console_gets();

// functional
void  paw_console_basic_shell();
void  paw_console_put_current_context();

static paw_uint8 paw_console_getc();
static void paw_console_putch(paw_uint8 _ch);
static void paw_console_print_current_context(paw_context* _context);

#endif