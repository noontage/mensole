/*
*  string.c
*
* author: noontage
*/
#include "paw/common.h"
#include "paw/pstring.h"
#include <string.h>

//
// match
//
paw_bool paw_string_is_match(const paw_string* _a, const paw_string* _b)
{
  paw_uint n = _PAW_MIN_(_a->len, _b->len);
  if(_a->len == _b->len && strncmp(_a->c_str, _b->c_str, n)==0) return paw_true;
  return paw_false;
}

//
// forward match
//
paw_bool paw_string_is_forwardmatch(const paw_string* _a, const paw_string* _b)
{
  paw_uint n = _PAW_MIN_(_a->len, _b->len);
  if (strncmp(_a->c_str, _b->c_str, n) == 0) return paw_true;
  return paw_false;
}

//
// empty?
//
paw_bool paw_string_is_empty(const paw_string* _pstr)
{
  if (strncmp(_pstr->c_str, paw_char_empty, 2) == 0) return paw_true;
  return paw_false;
}

//
// convert to paw_string(buffer is used source ptr)
//
void paw_char_to_string(paw_string* _pawstr, const char* _pstr)
{
  _pawstr->c_str = (char*)_pstr;
  _pawstr->len = (paw_uint)strlen(_pstr); // WARNING!!  possible buffer over flow. trust ptr when use
}