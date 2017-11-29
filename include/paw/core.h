/*
 * core.h
 *
 * author: noontage
 */
#ifndef _PAW_CORE_
#define _PAW_CORE_
#include "common.h"

void paw_init();

paw_context* paw_define_context(paw_key _key, paw_context* _parent);
paw_config* paw_define_config(paw_context* _context, paw_key _key, paw_string _default_value);
void paw_define_function(paw_context* _context, void (*function)());

void       paw_set_config(paw_key _key, paw_string _value);
paw_string paw_get_config(paw_key _key);

#endif