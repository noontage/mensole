/*
 * console_shell
 *
 * note: console for PC
 * author: noontage
 */
 // include
#include "paw/console_shell.h"
#include "paw/console.h"
#include "paw/pstring.h"
#include <stdio.h>
#include <conio.h>

#ifdef _PAW_ENABLE_CONSOLE_SHELL_

// global
static paw_string paw_string_buf;
static paw_string paw_csl_end = {
  _PAW_CONSOLE_SHELL_TOPARENT_COMMAND_,
  (sizeof(_PAW_CONSOLE_SHELL_TOPARENT_COMMAND_)-1)
};

// func
static struct COMMAND_RESULT{
  paw_uint8 match;
  enum paw_command_type type;
  void* data;
} command_result;


//
//  paw_console_basic_shell
//

// search match string
static void find_list_by_name(const paw_list* _list, const enum paw_command_type _type, const paw_string* _string)
{
  paw_list* plist = _list->next;
  paw_string* s=paw_null;
  enum paw_command_type type;
  
  // search
  while (plist != paw_null) {
    // set compare target strings
    if (_type == CONTEXT) {
      paw_context* pctx = (paw_context*)plist->value;
      s = &pctx->name;
      type = CONTEXT;
    }
    else if (_type == CONFIG) {
      paw_config* pcfg = (paw_config*)plist->value;
      s = &pcfg->name;
      type = CONFIG;
    }
    // is match?
    #ifdef _PAW_CONSOLE_SHELL_USE_FORWARD_MATCH_
    if (paw_string_is_forwardmatch(s, _string)) {
    #else
    if (paw_string_is_match(s, _string)) {
    #endif
      command_result.match++;
      command_result.data = plist->value;
      command_result.type = type;
    }
    plist = plist->next;
  }

}

// print_avairable_command
static void find_all_by_name(const paw_string* _command)
{
  command_result.type = UNRECOGNIZED;

  // ignore empty
  if (paw_string_is_empty(_command)) {
    command_result.type = NONE;
    return;
  }

  // go to parent context
  if (paw_current_context != &paw_root_context && paw_string_is_match(_command, &paw_csl_end)) {
    paw_current_context = paw_current_context->parent;
    command_result.type = UP_TO_CONTEXT;
    return;
  }

  // search
  find_list_by_name(&paw_current_context->child_list,    CONTEXT,    _command);
  find_list_by_name(&paw_current_context->config_list,   CONFIG,     _command);

  // ambig check
  #ifdef _PAW_CONSOLE_SHELL_USE_FORWARD_MATCH_
  if (command_result.match > 1) {
    command_result.type = AMBIGUOUS;
    return;
  }
  #endif

  return;
}

//
// print prompt
//
void paw_shell_print_prompt()
{
  // draw current context
  paw_shell_print_current_context();
  // mode
  paw_console_putc((paw_uint8)_PAW_CONSOLE_SHELL_PROMPT_SUPER_);
  paw_console_print(paw_char_space);
}

// basic shell
void  paw_shell_start()
{
  paw_config* pcfg;
  paw_string* argv;

  while(1)
  {
    // prompt
    paw_shell_print_prompt();

    // init
    paw_status_calltype  = 0;
    command_result.match = 0;
    command_result.data = paw_null;

    // get user command
    argv = paw_console_gets();
    find_all_by_name( argv );

    // analyze
    switch ( command_result.type )
    {
    // --- none
    case NONE:
      break;
    // --- context
    case CONTEXT:
      paw_current_context = (paw_context*)command_result.data;
      break;
    // --- config
    case CONFIG:
     pcfg = (paw_config*)command_result.data;
    // --- up to
    case UP_TO_CONTEXT:
      break;
    // --- anbig
    #ifdef _PAW_CONSOLE_SHELL_USE_FORWARD_MATCH_
    case AMBIGUOUS:
      paw_console_puts(_PAW_CONSOLE_SHELL_MSG_AMBIG_);
      break;
    #endif
    // --- not found 
    default:
      paw_console_puts(_PAW_CONSOLE_SHELL_MSG_UNREC_);
      break;
    }
  }
}

//
// paw_console_print_current_context
//
static void print_current_context(paw_context* _context)
{
  if (_context->parent != &paw_root_context) print_current_context(_context->parent);
  paw_console_print(_context->name.c_str);
  if (_context != paw_current_context) paw_console_putc(_PAW_CONSOLE_SHELL_CHAIN_CHAR_);
}

//
// current_context
//
void paw_shell_print_current_context()
{
  paw_console_putc('(');
  paw_console_print(_PAW_CONSOLE_SHELL_MSG_CONFIG_);
  if (paw_current_context != &paw_root_context) {
    paw_console_putc('-');
    print_current_context(paw_current_context);
  }
  paw_console_putc(')');
}

#endif