/*
 * common.h
 *
 * author: noontage
 */
#ifndef _PAW_COMMON_
#define _PAW_COMMON_

//
// load build config
//
#include "../pawconf.h"

//
// macro
//
#define _PAW_MAX_(a, b)            ((a) > (b) ? (a) : (b))
#define _PAW_MIN_(a, b)            ((a) < (b) ? (a) : (b))
#define _PAW_CHAR_EMPTY_           ""
#define _PAW_CHAR_SPACE_           " "
#define _PAW_NOP_                  0x00

//
// function event type
//
#define _PAW_WHEN_BOOT_              0x01
#define _PAW_WHEN_COMMAND_           0x02
#define _PAW_WHEN_CHANGED_CONFIG_    0x03
#define _PAW_WHEN_HELP_              0x04

//
// call result
//
#define _PAW_CALLTYPE_SUCCESS_     0x01
#define _PAW_CALLTYPE_FAILED_      0x02

//
// basic typedef
//
#ifdef _PAW_BUILD_FOR_PC_
#include <stdint.h>
#pragma warning(disable:4996)
#define paw_null ((void *)0)
#define paw_false 0
#define paw_true 1
typedef unsigned char paw_bool;
typedef int16_t paw_int;
typedef uint16_t paw_uint;
typedef uint8_t paw_uint8;
#endif

//
// general list
//
typedef struct {
	void* value;
	void* next;
} paw_list;

//
// string
//
typedef struct {
  char* c_str;
  paw_uint len;
} paw_string;

//
// function
//
typedef struct
{
	paw_string name;
	paw_uint8(*function)(paw_string param);
} paw_function;

//
// config
//
typedef struct {
  paw_string name;
  paw_string value;
  paw_list function_list;
} paw_config;

//
// context
//
struct paw_context_t
{
  void* parent;
  paw_string name;
  paw_list function_list;
  paw_list config_list;
  paw_list child_list;
};
typedef struct paw_context_t paw_context;

//
// global (instance is core.c)
//

// share buffer
extern const char* paw_char_empty;
extern const char* paw_char_space;

// current status
extern paw_context  paw_root_context;                  //  root context
extern paw_context* paw_current_context;               //  current_context
extern void* paw_status_result;

// autoset status
extern paw_uint8    paw_status_calltype;                //  last(or now) called type

#endif // common.h
