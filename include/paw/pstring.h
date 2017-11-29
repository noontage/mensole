/*
 * pstring.h
 *
 * author: noontage
 */
#ifndef _PAW_STRING_
#define _PAW_STRING_

#include "paw/common.h"

// check
paw_bool paw_string_is_match(const paw_string* _a,const paw_string* _b);
paw_bool paw_string_is_forwardmatch(const paw_string* _a, const paw_string* _b);
paw_bool paw_string_is_empty(const paw_string* _pstr);

// char control
void paw_char_to_string(paw_string* _pawstr, const char* _pstr);

#endif // pstring.h
