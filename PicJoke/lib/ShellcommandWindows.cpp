#include <Arduino.h>
#include "PlaywithTeensy.h"


void writeline(String cmd){
    delay(100);
    Keyboard.print(cmd);  
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(KEY_ENTER);  
    Keyboard.send_now();
    delay(100);

    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
}

void openPowerShell(){
   delay(1000);
    
    Keyboard.set_modifier(MODIFIERKEY_GUI);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

  
    Keyboard.println("PowerShell");  
    Keyboard.send_now();
    delay(100);


     Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
}

void opencmd(){

    delay(1000);
    
    Keyboard.set_modifier(MODIFIERKEY_GUI);
    Keyboard.send_now();
    delay(100);
    
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

  
    Keyboard.print("cmd");  
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(KEY_ENTER);  
    Keyboard.send_now();
    delay(100);

    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);
  
}
