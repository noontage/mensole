/*
 * core.h
 *
 * author: noontage
 */
#ifndef _PAW_CORE_
#define _PAW_CORE_
#include "common.h"

//
// event type
//
#define _PAW_ON_BOOT_     0b00000001
#define _PAW_ON_COMMAND_  0b00000010
#define _PAW_ON_COMMIT_   0b00000100
#define _PAW_ON_WRITE_    0b00001000

//
// initialize
//
void paw_init();

//
// clean
//
#ifdef _PAW_USE_GC_
void paw_clean();
static void paw_clean_context(paw_context* _base);
#endif

//
// get root context
//
//paw_context* paw_get_root_context();

//
// get call type
//
//paw_call_type paw_get_last_call_type();

//
// current context
//
// paw_get_current_context();

//
// write memory
//
void paw_write_memory();

//
// commit
//
void paw_commit();

//
// define context
//
paw_context* paw_define_context(
  paw_string _name,               //   context name
  paw_context* _parent            //   parent context
);

//
// define config
//
void paw_define_config(
  paw_context* _context,     // belong context
  paw_string _key            // config keyname
);

//
// define command
//
void paw_define_command(
  paw_string _command,                            //  command name
  paw_context* _context,                          //  belong context (paw_null = global function)
  paw_result(*function)(paw_string _param)        //  be called function
);

//
// define function
// function is called when on each event.
//
void paw_define_function(
  paw_context* _context,                          //  belong context (paw_null = root)
  paw_result(*function)(paw_string _param),       //  be called function
  paw_uint8 _call_event                           //  call event (ex. _PAW_ON_BOOT || _PAW_ON_COMMAND_ )
);

//
// define function
// function is called when change config
//
void paw_define_function_on_change_config(
  paw_config_value* config_value,                 //
  paw_result(*function)(paw_string _param)        //  be called function
);

#endif