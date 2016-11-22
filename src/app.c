/*
 sample application 
 author: noontage
 */
#include "pawos.h"

paw_context net;
paw_context wlan;
paw_context io;

void paw_error(const char* _s)
{

}

// ------------------------------------------------------
//  app_init
// ------------------------------------------------------
void app_init()
{
  paw_init();                         //  required

  /* * register to system * *
   
    root
    ├─net
    │  ├─wlan
    ├─io

                   paw_context  context name    parent context
                       |          |              |
                       |          |              |                                                                                   */
  paw_register_context(&net,    "net",       paw_null);
  paw_register_context(&wlan,   "wlan",      &net);
  paw_register_context(&io,     "num",       paw_null);

  /* *  register config  * *

                                       on change 
                                    function pointer
                                           |
                                  default  |
               belong context  key value   |
                        | 　　　|　 |      |
                        |　　　 |　 |　　  |                                                                                         */
    paw_register_config(&net, "ip", "", paw_null);

}

// ------------------------------------------------------
//  entrypoint
// ------------------------------------------------------
int main()
{
  app_init();
  paw_shell_start();
}