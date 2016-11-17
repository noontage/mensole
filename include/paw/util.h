/*
 * util.h
 *
 * author: noontage
 */
#ifndef _PAW_UTIL_
#define _PAW_UTIL_

#include "common.h"

// system
void paw_util_init();
void paw_util_clean();

// list
paw_list* paw_util_create_list();
void paw_util_list_push(paw_list* _target, void* _value);
void paw_util_list_init(paw_list* _target);

// string
paw_int paw_strnlen(paw_string _str, paw_int _max);
void paw_strncpy(paw_string _dest, paw_string _src, paw_int _n);
paw_bool paw_string_is_match(paw_string _str1, paw_string _str2);
paw_string paw_string_dup(paw_string _str1);

// memory
#ifdef _PAW_USE_GC_
void paw_free(void* ptr);
#endif

#ifdef _PAW_USE_MALLOC_
void* paw_alloc(paw_int _size);
#endif

#endif // util.h