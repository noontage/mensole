/*
* util.c
*
* author: noontage
*/
#include "paw/util.h"
#include "paw/ram.h"
#include "paw/error.h"

//
// paw_util_clear_context
//
void paw_util_clear_context(paw_context *_context)
{
  _context->name.c_str = (char*)paw_char_empty;
  _context->name.len = 0;
  _context->child_list.next = paw_null;
  _context->child_list.value = paw_null;
  _context->config_list.next = paw_null;
  _context->config_list.value = paw_null;
  _context->function_list.next = paw_null;
  _context->function_list.value = paw_null;
  _context->parent = paw_null;
}

//
// paw_util_clear_config
// 
void paw_util_clear_config(paw_config* _config)
{
  _config->name.c_str    = (char*)paw_char_empty;
  _config->name.c_str    = (char*)paw_char_empty;
  _config->value.c_str  = (char*)paw_char_empty;
  _config->name.c_str    = (char*)paw_char_empty;

}


//
// list_init
//
void paw_util_clear_list(paw_list* _list)
{
  _list->next = paw_null;
  _list->value = paw_null;
}

//
// list_push
//
paw_list* paw_util_list_push(paw_list* _target, void* _value)
{
  while (_target->next != paw_null) {
    _target = _target->next;
  }
  paw_list* list = paw_ram_create_list();
  list->value = _value;
  _target->next = list;

  #ifdef _PAW_DEBUG_
  if (list == paw_null) {
    _PAW_ON_ERROR_FUNC_("out of memory - paw_list");
  }
  #endif

  return list;
}