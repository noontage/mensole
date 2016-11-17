/*
* util.c
*
* author: noontage
*/
#include "paw/util.h"

#ifdef _PAW_USE_GC_
static paw_list gc_list;
#endif

//
// util_init
//
void paw_util_init()
{
  gc_list.next = paw_null;
  gc_list.self = paw_null;
}

//
// paw_util_clean
//
void paw_util_clean()
{
// clean gc_list
#ifdef _PAW_USE_GC_
  for (paw_list* now = &gc_list; now->next != paw_null; now = now->next) {
    paw_free(now->self);
  }
#endif

}

//
// list_init
//
paw_list* paw_util_create_list()
{
  paw_list* p_paw_list = paw_alloc(sizeof(paw_list));
  paw_util_list_init(p_paw_list);

// manage list of list
#ifdef  _PAW_USE_GC_
  paw_util_list_push(&gc_list, p_paw_list);
#endif

  return p_paw_list;
}

//
// list_push
//
void paw_util_list_push(paw_list* _target, void* _value)
{
  while (_target->next != paw_null) {
    _target = _target->next;
  }
  paw_list* list = (paw_list*)paw_alloc(sizeof(paw_list));
  list->self = _value;
  _target->next = list;
}

//
// paw_util_list_init
//
void paw_util_list_init(paw_list* _target)
{
  _target->next = paw_null;
  _target->self = paw_null;
}


// -------------------  paw_malloc ------------------------
#ifdef _PAW_USE_MALLOC_
#include <stdlib.h>
//
// paw_alloc
//
void* paw_alloc(paw_int _size)
{
  return malloc((size_t)_size);
}

//
// paw_free
//
void paw_free(void* ptr)
{
  free(ptr);
}
#endif
// -------------------------------------------


//
// String(for PC)
//
// -------------------------------------------
#ifdef  _BUILD_FOR_PC_
#include <string.h>

// strnlen
paw_int paw_strnlen(paw_string _str, paw_int _max)
{
  return (paw_int)strnlen(_str, _max);
}

// strncpy
void paw_strncpy(paw_string _dest, paw_string _src, paw_int _n)
{
  strncpy(_dest, _src, _n);
}

// is match
paw_bool paw_string_is_match(paw_string _str1, paw_string _str2)
{}

// dup(clone)
paw_string paw_string_dup(paw_string _str1)
{}

// -------------------------------------------
#endif
