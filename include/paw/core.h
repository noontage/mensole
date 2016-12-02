/*
 * core.h
 *
 * author: noontage
 */
#ifndef _PAW_CORE_
#define _PAW_CORE_
#include "common.h"

void paw_init();

void paw_register_context(paw_context* _context, const char* _name, paw_context* _parent);
void paw_register_config(paw_context* _context, const char* _name, const char* _default_value);
void paw_register_function(paw_context* _context, void (*function)());

const char* paw_config_get_value(const char* _name);

#endif