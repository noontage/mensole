/*
 sample application 
 author: noontage
 */
#include "pawos.h"
#include "paw/util.h"

paw_context* ip;
paw_context* wlan;
paw_context* io;

void paw_error(const char* _msg)
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
    ├─ip
    │  ├─wlan
    ├─io
    
                   　　　　　      unique key    parent context
                                       |              　　|
                                       |             　 　|                                                                                   */
  ip   = paw_define_context(paw_create_uniq_key(), &paw_root_context);
  wlan = paw_define_context(paw_create_uniq_key(), ip);
  io   = paw_define_context(paw_create_uniq_key(), &paw_root_context);

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