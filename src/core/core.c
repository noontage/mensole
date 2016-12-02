/*
 * core.h
 *
 * author: noontage
 */
#include "paw/core.h"

#include "paw/error.h"
#include "paw/util.h"
#include "paw/ram.h"
#include "paw/pstring.h"

// global share
const char* paw_char_empty = _PAW_CHAR_EMPTY_;
const char* paw_char_space = _PAW_CHAR_SPACE_;

//  global instance
paw_context  paw_root_context;                  //  root context
paw_context* paw_current_context;               //   current_context
paw_uint8    paw_status_calltype;               //   last(or now) called type

//
// paw_init
//
void paw_init()
{
  paw_ram_init();
  paw_util_clear_context(&paw_root_context);
  paw_current_context = &paw_root_context;
}

//
// register context
//
void paw_register_context(paw_context* _context, const char* _name, paw_context* _parent)
{
  paw_list* target;
  paw_util_clear_context(_context);
  if (_parent == paw_null) {
   target = &paw_root_context.child_list;
   _context->parent = &paw_root_context;
  }
  else {
    target = &_parent->child_list;
    _context->parent = _parent;
  }
  paw_util_list_push(target, _context);
  paw_char_to_string(&_context->name, _name);
}

//
// register config
//
void paw_register_config(paw_context* _context, const char* _name, const char* _default_value)
{
  paw_config* config = paw_ram_create_config();
  #ifdef _PAW_DEBUG_
    if (config == paw_null) {
      _PAW_ON_ERROR_FUNC_("out of memory - paw_config");
    }
  #endif

  paw_char_to_string(&config->name, _name);
  paw_char_to_string(&config->value, _default_value);
  paw_util_list_push(&_context->config_list, config);

}