/*
  PAW CONFIGRATION FILE
  author: noontage
*/

#define _PAW_DEBUG_               // recommend disable when release

////
// message
////
#define _PAW_MSG_ABOUT_           "mensole"
#define _PAW_MSG_VERSION_         "1.0"

#define _PAW_ON_ERROR_FUNC_(msg)  paw_error(msg);

////
// Platform 
////
#if defined(_WIN32) || defined(__x86_64__)
  // PC
  #define _PAW_BUILD_FOR_PC_
#elif defined(__AVR__)
  // AVR
  #define _BUILD_FOR_AVR
#elif defined(ESP8266)
  // ESP8266
  #define _BUILD_FOR_ESP8266
#endif

////
//  malloc
////
#define _PAW_ENABLE_MALLOC_
#ifdef _PAW_ENABLE_MALLOC_
  #define _PAW_HEAP_SIZE 512
#else
  #define _PAW_POOLSIZE_CONFIG_          10     //  prepare context (first, on memory)  
  #define _PAW_POOLSIZE_FUNCTION_        10     //  prepare function (first, on memory)  
  #define _PAW_POOLSIZE_LIST_            10     //  prepare list (first, on memory)  
#endif

////
// console
////
#define _PAW_ENABLE_CONSOLE_
#ifdef  _PAW_ENABLE_CONSOLE_
  #define _PAW_CONSOLE_BUFSIZE_GETS_     40             //  console workspace buffer
#endif

////
// console shell
////
#define _PAW_ENABLE_CONSOLE_SHELL_
#ifdef _PAW_ENABLE_CONSOLE_SHELL_
  #define _PAW_CONSOLE_SHELL_USE_FORWARD_MATCH_
  #define _PAW_CONSOLE_SHELL_MSG_CONFIG_                "cfg"
  #define _PAW_CONSOLE_SHELL_MSG_UNREC_                 "% Unrecognized"
  #define _PAW_CONSOLE_SHELL_MSG_AMBIG_                 "% Ambiguous"
  #define _PAW_CONSOLE_SHELL_TOPARENT_COMMAND_          ".."
  #define _PAW_CONSOLE_SHELL_CHAIN_CHAR_                '-'   //  context chain
  #define _PAW_CONSOLE_SHELL_PROMPT_USER_               '>'		//	prompt char
  #define _PAW_CONSOLE_SHELL_PROMPT_SUPER_              '#'		//	prompt char(super)
#endif

#define _PAW_ENABLE_AT_SHELL_

////
// access control
////
//#define _PAW_ENABLE_ACL_					//	use access control

////
//  use http client
////
//#define _PAW_ENABLE_HTTP_CLIENT_					//	use http