/*
 * common.h
 *
 * author: noontage
 */
#ifndef _PAW_COMMON_
#define _PAW_COMMON_

/************************************************************************************************************
  Option
 ************************************************************************************************************/

/*
 * Settings
 */
#define _PAW_MAX_COMMAND_LENGTH_	  6 		//	max	command length
#define _PAW_MAX_HOSTNAME_LENGTH_	  6		  //	max hostname length
#define _PAW_MAX_CONTEXT_NAME_      6     //  max context name
#define _PAW_TEMP_BUF_LENGTH_       40    //  all share temporary buffer

#define _PAW_MSG_ABOUT_           "mensole"
#define _PAW_MSG_ABOUT_AUTOHR_    "noontage"
#define _PAW_MSG_VERSION_         "1.0"

#define _PAW_MOTD_MSG_		        _PAW_MSG_ABOUT_

#define _PAW_MSG_UNREC_CMD_       "% Unrecognized"
#define _PAW_MSG_AMBIGUOUS_       "% Ambiguous"

#define _PAW_CONSOLE_CHAIN_CHAR_   '-'    //  context chain
#define _PAW_PROMPT_USER_          '>'		//	prompt char
#define _PAW_PROMPT_SUPER_         '#'		//	prompt char(super)

/*
 * Used function
 */

// core
#define _PAW_USE_MALLOC_          //  use malloc
#define _PAW_USE_GC_              //  use gc
//#define _PAW_USE_ACL_					//	use access control

// comsole
#define _PAW_USE_COMPLEMENT_			//	use command complement
#define _PAW_USE_VIEW_BC_					//	use breadcrumb
//#define _PAW_USE_HOSTNAME_			//	use hostname

//#define _PAW_USE_HTTP_					//	use http

/************************************************************************************************************/

/*
 * PC
 */
#if defined(_M_IX86) ||  defined(_M_IX64) || defined(_WIN32)
#define _BUILD_FOR_PC_
#elif defined(__AVR__)
 /*
 * AVR
 */
#define _BUILD_FOR_AVR
#elif defined(ESP8266)
 /*
 * PC
 */
#define _BUILD_FOR_ESP8266
#endif

/* basic typedef */
#ifdef _BUILD_FOR_PC_
#include <stdint.h>
#pragma warning(disable:4996)
#define paw_null ((void *)0)
#define paw_false 0
#define paw_true 1
typedef unsigned char paw_bool;
typedef char* paw_string;
typedef int16_t paw_int;
typedef uint16_t paw_uint;
typedef uint8_t paw_uint8;
#endif

/* call type */
typedef enum PAW_CALL_TYPE { BOOT, COMMAND, WRITE, COMMIT } paw_call_type;

/* call result */
typedef enum PAW_RESULT { SUCCESS, INVALID, AMBIGUOUS } paw_result;

/* general list */
typedef struct {
	void* self;
	void* next;
} paw_list;

/* function */
struct paw_func_t
{
	paw_string name;
	paw_result(*function)(paw_call_type _call_type, ...);
};
typedef struct paw_func_t paw_func;

/* config context */
struct paw_context_t
{
	paw_string name;
	paw_list paw_command_list;
  paw_list paw_function_list;
  paw_list paw_config_value_list;
  void* parent;
  paw_list child_context_list;
};
typedef struct paw_context_t paw_context;

/* config value */
typedef struct {
  paw_string key;
  paw_string value;
  paw_list function_list;
} paw_config_value;

/* command */
typedef struct {
  paw_string command;
  paw_list arg;
} paw_command;

/* Hostname */
#ifdef _PAW_USE_HOSTNAME_
char hostname[_PAW_MAX_HOSTNAME_LENGTH_];
#endif

/* ACL */
#ifdef _PAW_USE_ACL_
enum PAW_ACL_TYPE { USER, SUPER };
#endif

// there is instance paw core(core.c)
extern paw_context* paw_root_context;                    //  root context
extern paw_call_type paw_last_call_type;                //  get last calling type
extern paw_context* paw_current_context;                //   current_context
extern char paw_temp_buf[_PAW_TEMP_BUF_LENGTH_];

#endif // commond.h