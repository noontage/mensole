/*
 * console.h
 *
 * author: noontage
 */
#include "common.h"

#ifndef _PAW_CONSOLE_
#define _PAW_CONSOLE_

// standard io
void        paw_console_print(const char* _pstr);
void        paw_console_puts(const char* _pstr);
paw_string* paw_console_gets();                           //  set user input on 'paw_buf_share'

// standard io a chara
paw_uint8   paw_console_getc();
void        paw_console_putc(paw_uint8 _ch);

#endif
