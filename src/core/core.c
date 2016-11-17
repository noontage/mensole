/*
 * core.h
 *
 * author: noontage
 */
#include "paw/core.h"
#include "paw/util.h"

// global var
char paw_temp_buf [_PAW_TEMP_BUF_LENGTH_];        //  temporary buffer(global)
paw_context* paw_root_context;                    //  root context

// global status
paw_context* paw_current_context;                //   current_context
paw_call_type paw_last_call_type;                //   last(or now) called type


//
// paw_init
//
void paw_init()
{
  paw_util_init();                                      // util init
  paw_root_context = paw_define_context("", paw_null);  // create root context
  paw_current_context = paw_root_context;
}

//
// define(create) context
//
paw_context* paw_define_context(paw_string _name, paw_context* _parent)
{
  //  create context
  paw_context* context = (paw_context*)paw_alloc(sizeof(paw_context));
  paw_uint size = paw_strnlen(_name, _PAW_MAX_CONTEXT_NAME_) + 1;
  context->parent = _parent;
  context->name = (char*)paw_alloc(size);
  paw_strncpy(context->name, _name, size);
  paw_util_list_init(&context->child_context_list);
  paw_util_list_init(&context->paw_config_value_list);
  paw_util_list_init(&context->paw_function_list);
  
  //  add to context_list
  if(_parent != paw_null) paw_util_list_push(&_parent->child_context_list, context);

  return context;
}


//
// define config
//
void paw_define_config(
  paw_context* _context,     // belong context
  paw_string _key            // config keyname
)
{}

//
// define command
//
void paw_define_command(
  paw_string _command,                            //  command name
  paw_context* _context,                          //  belong context (paw_null = global function)
  paw_result(*function)(paw_string _param)        //  be called function
)
{}

//
// define function  
// function is called when on each event.
//
void paw_define_function(
  paw_context* _context,                          //  belong context (paw_null = root)
  paw_result(*function)(paw_string _param),       //  be called function
  paw_uint8 _call_event                           //  call event (ex. _PAW_ON_BOOT || _PAW_ON_COMMAND_ )
)
{}

//
// define function
// function is called when change config
//
void paw_define_function_on_change_config(
  paw_config_value* config_value,                 //
  paw_result(*function)(paw_string _param)        //  be called function
)
{}

//
// write memory
//
void paw_write_memory()
{
  paw_last_call_type = WRITE;
}

//
// commit
//
void paw_commit()
{
  paw_last_call_type = COMMIT;
}

/* -------------------------------------------------------------------------------------------------
//
// paw_get_last_call_type
//
paw_call_type paw_get_last_call_type() {
  return last_call_type;
}

//
// paw_core_get_root_context
//
paw_context* paw_get_root_context()
{
  return root_context;
}
----------------------------------------------------------------------------------------------------*/

//
// paw_clean
//
#ifdef _PAW_USE_GC_
void paw_clean()
{
  // clean context
  paw_clean_context(paw_root_context);

  // clean root context
  paw_free(paw_root_context);
  paw_util_clean();
}

// clean context
static void paw_clean_context(paw_context* _base)
{
}
#endif
