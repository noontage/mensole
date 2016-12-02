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
paw_context* paw_define_context(paw_key _key, paw_context* _parent)
{
  paw_context* context = paw_ram_create_context();
  #ifdef _PAW_DEBUG_
    if (context == paw_null) {
      _PAW_ON_ERROR_FUNC_("out of memory - paw_context");
    }
  #endif
  paw_util_clear_context(context);
  context->key = _key;
  context->parent = _parent;
  paw_util_list_push(&_parent->child_list, context);

  return context;
}

//
// register config
//
paw_config* paw_define_config(paw_context* _context, paw_key _key, paw_string _default_value)
{
  paw_config* config = paw_ram_create_config();
  #ifdef _PAW_DEBUG_
    if (config == paw_null) {
      _PAW_ON_ERROR_FUNC_("out of memory - paw_config");
    }
  #endif

  paw_util_clear_config(config);
  config->key = _key;
  config->value = _default_value;

  paw_util_list_push(&_context->config_list, config);

  return config;
}

void paw_define_function(paw_context* _context, void(*function)())
{

}