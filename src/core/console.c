/*
 * console_pc
 *
 * note: console for PC
 * author: noontage
 */
#include <stdio.h>
#include <conio.h>
#include "paw/pstring.h"
#include "paw/console.h"

// global
static char paw_share_buf[_PAW_CONSOLE_BUFSIZE_GETS_];
static paw_string paw_string_buf;

//
// print
//
void  paw_console_print(const char* _pstr)
{
  #ifdef _PAW_BUILD_FOR_PC_
  printf("%s", _pstr);
  #endif
}

//
// getc
//
paw_uint8 paw_console_getc()
{
  #ifdef _PAW_BUILD_FOR_PC_
  return (paw_uint8)getch();
  #endif
}

//
// putc
//
void paw_console_putc(paw_uint8 _ch)
{
  #ifdef _PAW_BUILD_FOR_PC_
  putch(_ch);
  #endif
}

//
// puts
//
void  paw_console_puts(const char* _pstr)
{
  paw_console_print(_pstr);
  paw_console_print("\n");
}

//
// gets
//
paw_string* paw_console_gets()
{
  paw_uint8 i,ch;
  for (i = 0; i < (_PAW_CONSOLE_BUFSIZE_GETS_ -2); i++) {
    ch = paw_console_getc();
    if (ch == '\r' || ch == '\n' || ch == '?') {
      if(ch=='?') paw_status_calltype= _PAW_WHEN_HELP_;
      break;
    }
    paw_share_buf[i] = ch;
    paw_console_putc(ch);
  }
  paw_share_buf[i] = '\0';
  paw_string_buf.c_str = paw_share_buf;
  paw_string_buf.len = i;
  paw_console_putc('\n');
  return &paw_string_buf;
}