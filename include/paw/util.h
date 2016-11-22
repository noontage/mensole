/*
 * util.h
 *
 * author: noontage
 */
#ifndef _PAW_UTIL_
#define _PAW_UTIL_

#include "common.h"

// clear
void paw_util_clear_context(paw_context* _context);
void paw_util_clear_config(paw_config* _config);
void paw_util_clear_list(paw_list* _list);

// list
paw_list* paw_util_list_push(paw_list* _target, void* _value);

#endif // util.h
