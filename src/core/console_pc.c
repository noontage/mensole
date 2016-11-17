/*
 * console_pc
 *
 * note: console for PC
 * author: noontage
 */
#include "paw/console.h"
#ifdef _BUILD_FOR_PC_

// include
#include <stdio.h>
#include <conio.h>

//
// puts
//
void  paw_console_puts(const paw_string str)
{
  printf("%s\n",str);
}

//
// print
//
void  paw_console_print(const paw_string str)
{
  printf("%s", str);
}

//
// gets
//
paw_string paw_console_gets()
{
  paw_uint8 ch;
  for (paw_uint8 i=0; i < sizeof(paw_temp_buf) - 1; i++) {
    ch = paw_console_getc();
    if (ch == '\r' || ch == '\n' || ch == '?') {
      paw_console_print("\n");
      if (ch=='?') {
        paw_temp_buf[i]     = ch;
        paw_temp_buf[i + 1] = '\0';
      }
      else {
        paw_temp_buf[i] = ch = '\0';
      }
      return paw_temp_buf;
    }
    paw_temp_buf[i] = ch;
    paw_console_putch(ch);
  }
  return '\0';
}

//
//  paw_console_basic_shell
//
void  paw_console_basic_shell()
{
  // motd(welcome message)
  paw_console_puts(_PAW_MOTD_MSG_);
  while(1)
  {
    //  draw current context
    if (paw_current_context != paw_root_context){
      paw_console_print_current_context(paw_current_context);
    }
    paw_console_putch(_PAW_PROMPT_USER_);
    paw_console_gets();
  }
}

/*---------- static -------------*/

//
// getc
//
static paw_uint8 paw_console_getc()
{
  return (paw_uint8)getch();
}

//
// putc
//
static void paw_console_putch(paw_uint8 _ch)
{
  putch(_ch);
}

//
// paw_console_print_current_context
//
static void paw_console_print_current_context(paw_context* _context)
{
  if (_context->parent != paw_root_context) paw_console_print_current_context(_context->parent);
  paw_console_print(_context->name);
  if (_context != paw_current_context) paw_console_putch(_PAW_CONSOLE_CHAIN_CHAR_);
}

#endif