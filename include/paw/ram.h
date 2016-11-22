/*
 * ram.h
 *
 * describe: memory management and crete object.
 * author: noontage
 */
#ifndef _PAW_RAM_
#define _PAW_RAM_
#include "common.h"

paw_list*     paw_ram_create_list();
paw_config*   paw_ram_create_config();
paw_function* paw_ram_create_function();

#endif // ram.h