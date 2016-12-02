/*
 sample application 
 author: noontage
 */
#include "pawos.h"

paw_context ip;
paw_context wlan;
paw_context io;

void paw_error(const char* _msg)
{}

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
  paw_register_context(&ip,     "ip",        paw_null);
  paw_register_context(&wlan,   "wlan",      &ip);
  paw_register_context(&io,     "num",       paw_null);

  /* *  register config  * *
                                           
                                     default  
               belong context  key    value   
                        | 　　　|　     |     
                        |　　　 |　     |　　                                                                                              */
  paw_register_config(&wlan, "address", "");

}

// ------------------------------------------------------
//  entrypoint
// ------------------------------------------------------
int main()
{
  app_init();
  paw_shell_start();
}