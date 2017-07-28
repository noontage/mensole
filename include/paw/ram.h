/*
 * ram.h
 *
 * describe: memory management and crete object.
 * author: noontage
 */
#ifndef _PAW_RAM_
#define _PAW_RAM_
#include "common.h"

#include <stddef.h>

void          paw_ram_init();
void*         paw_palloc(size_t _require_size);
paw_context*  paw_ram_create_context();
paw_list*     paw_ram_create_list();
paw_config*   paw_ram_create_config();

#endif // ram.h