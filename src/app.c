/*
 * sample application
 *
 * author: noontage
 */
#include "pawos.h"

// context
static paw_context* c_net;      //  network
static paw_context* c_wlan;     //  wireless lan

// app init
void app_init()
{

  paw_init();                         //  required

  // ------------------------------------------------------
  //  define context
  // ------------------------------------------------------
  // root
  //  „¥„Ÿnet
  //  „   „¥„Ÿwlan
  //  „¥„Ÿio
  // ------------------------------------------------------
  c_net  = paw_define_context("net",paw_root_context);
  c_wlan = paw_define_context("wlan",c_net);

//  paw_current_context = c_wlan;
}

// main
int main()
{
  app_init();
  paw_console_basic_shell();
}