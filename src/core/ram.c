/*
 *  ram_pool.c
 *
 * describe: pool
 * author: noontage
*/
#include "paw/ram.h"

#ifdef _PAW_ENABLE_MALLOC_
static char       heap[_PAW_HEAP_SIZE];
static char*      pHeap_next = heap;
static char*      pHeapMax;

#ifdef _PAW_DEBUG_
  #include "paw/console.h"
  paw_uint paw_ram_used_size=0;
#endif

//
// alloc init
//
void paw_ram_init()
{
  pHeapMax = heap + _PAW_HEAP_SIZE;
}

//
// parmenent alloc
//
void* paw_palloc(size_t _require_size)
{
  void* p;

  if ((pHeap_next + _require_size) > pHeapMax) {
    p = NULL;
  }
  else {
    p = pHeap_next;
    pHeap_next = pHeap_next + _require_size;
    #ifdef _PAW_DEBUG_
    paw_ram_used_size += (paw_uint)_require_size;
    #endif
  }

  return p;
}

//
// not use heap
//
#else
  static paw_list     paw_list_pool[_PAW_POOLSIZE_LIST_];
  static paw_config   paw_config_pool[_PAW_POOLSIZE_CONFIG_];
  static paw_uint8    seek_list     = 0;
  static paw_uint8    seek_function = 0;
  static paw_uint8    seek_config   = 0;
#endif

//
// paw_ram_create_list
// 
paw_list* paw_ram_create_list()
{
  #ifdef _PAW_ENABLE_MALLOC_
    return (paw_list*)paw_palloc(sizeof(paw_list));
  #else
    seek_list++;
    if(seek_list > _PAW_POOLSIZE_LIST_) return paw_null;
    return &paw_list_pool[seek_list-1];
  #endif
}

//
// paw_ram_create_config
//
paw_config* paw_ram_create_config()
{
  #ifdef _PAW_ENABLE_MALLOC_
    return (paw_config*)paw_palloc(sizeof(paw_config));
  #else
    seek_config++;
    if (seek_config > _PAW_POOLSIZE_CONFIG_) return paw_null;
    return &paw_config_pool[seek_config - 1];
  #endif
}