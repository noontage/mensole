/*
 *  ram_pool.c
 *
 * describe: pool
 * author: noontage
*/
#include "paw/ram.h"

#ifdef _PAW_ENABLE_MALLOC_
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
#else
  static paw_list     paw_list_pool[_PAW_POOLSIZE_LIST_];
  static paw_function paw_function_pool[_PAW_POOLSIZE_FUNCTION_];
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
  #else
    seek_list++;
    if(seek_list > _PAW_POOLSIZE_LIST_) return paw_null;
    return &paw_list_pool[seek_list-1];
  #endif
}

//
// paw_ram_create_context
//
paw_function* paw_ram_create_function()
{
  #ifdef _PAW_ENABLE_MALLOC_
  #else
    seek_function++;
    if (seek_function > _PAW_POOLSIZE_FUNCTION_) return paw_null;
    return &paw_function_pool[seek_function - 1];
  #endif
}


//
// paw_ram_create_config
//
paw_config* paw_ram_create_config()
{
  #ifdef _PAW_ENABLE_MALLOC_
  #else
    seek_config++;
    if (seek_config > _PAW_POOLSIZE_CONFIG_) return paw_null;
    return &paw_config_pool[seek_config - 1];
  #endif
}