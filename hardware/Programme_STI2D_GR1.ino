// Variable axel mathieu
int variablePWM = 5;

//Variable adeel
int inputPin = 7;
int val = 0;                    // variable for reading the pin status
int per = 0;                    //variable for permission
unsigned long interval = 5;   // time i need to wait
unsigned long previousMillis = 0;   // return as unsigned long
unsigned long currentMillis;

//Variable momo
int ldr = A0;
int valphoto;  // nb de bits
int vldr; // tension Vs
float lux;
float res = 5100;
float R;

#include <SPI.h>
#include <SD.h>
#include <Ethernet2.h>


const int chipSelect = 4;
File dataFile;
byte mac[] = { 0x90, 0xA2, 0xDA, 0x10, 0x67, 0xFC };                                               // Adresse mac du shield Ethernet.
IPAddress ip(192, 168, 0, 50);                                                                     // Adresse ip du serveur.
EthernetServer server(80);                                                                         // Déclaration de l'objet server attaché à la classe EthernetServer sur le port 80.

void setup() {
  Serial.begin(9600);
  pinMode(variablePWM, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.print("Initializing SD card...");
  if (!SD.begin(chipSelect)) {                                                                     // Test de la validité de la carte micro SD et de sa présence dans le lecteur.
    Serial.println("Card failed, or not present");
    return;
  }
  Serial.println("card initialized.");                                                             // Si la carte micro SD fonctionne on affiche le message correspondant sur le moniteur série.
  dataFile = SD.open("index.htm");                                                                // Ouverture du fichier "PageWeb.htm" de la carte micro SD
  if (!dataFile) Serial.println("Fichier inexistant");                                             // Si le fichier n'existe pas on affiche sur le moniteur série le message correspondant.
  Ethernet.begin(mac, ip);                                                                         // Démarrage de la connexion Ethernet avec l'adresse mac du shield Ethernet et l'adresse ip du serveur.
  server.begin();                                                                                  // Démarrage du serveur avec l'objet server.
  Serial.print("seveur est connecté");                                                             // Affichage sur le moniteur série du texte " serveur est connecté "
  Serial.println(Ethernet.localIP());
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600);// et de l'adresse ip du serveur.
}

void loop() {

  String chaine = "";
  String actif = "o", checkvrai;
  unsigned int compteur = 0, index , check , valeurDeConsigne;
  int an0;
  int a = 1;
  int valTestMod; //float avant int
  int valTestModAffiche;
  float valInputAffiche;
  int valInput;
  float luminositeLED;

  // listen for incoming clients
  EthernetClient client = server.available();                                                     // Initialisation de l'objet client par la méthode (fonction) available de l'objet server.
  if (client) {
    Serial.println("new client");                                                                 // Affichage sur le moniteur série du texte "new client".
    // an http request ends with a blank line
    chaine = "";
    compteur = 0;
    boolean currentLineIsBlank = true;
    while (client.connected()) {                                                                  // Boucle principale tant que le client est connecté.
      if (client.available()) {                                                                   // Si le client est en ligne.
        char c = client.read();                                                                   // Réception de la trame caractère par caractère.
        if (compteur < 50) chaine = chaine + c;                                                  // On remplit la chaine de caractère tant que le nombre de caractère est inférieur à 100 (mémoire arduino limitée).
        compteur++;
        Serial.write(c);                                                                          // Affichage sur le moniteur série de la trame caractère par caractère.
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {                                                    // Si on reçoit une fin de ligne avec une ligne vide on affiche la page html.
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response  // refresh the page automatically every 10 sec
          client.println("Refresh: 5");  // refresh the page automatically every 10 sec
          client.println();

          //programme axel mathieu

          index = chaine.indexOf("inputtestm=");                                                        // Recherche de la position du texte "inputtestm=" dans la trame.
          check = chaine.indexOf("checktestm=");
          valeurDeConsigne = chaine.indexOf("consigne=");                                             // Recherche de la position du texte "consigne=" dans la trame.
          valTestModAffiche = atof(&chaine[index + 11]);                                        // On convertit la chaine ASCII de la tension pleine échelle saisie sur la page web en nombre réel, "11" est le nombre de caractère avant le text evoyer.
          valInputAffiche = atof(&chaine[valeurDeConsigne + 9]);
          if (valTestModAffiche > 163)
          {
            valTestModAffiche = 163;
          }
          if (valInputAffiche > 163)
          {
            valInputAffiche = 163;
          }
          valTestMod = map(valTestModAffiche, 0, 163, 0, 255);
          valInput  = map(valInputAffiche, 0, 163, 0, 255);

          //programme momo

          vldr = analogRead(ldr);
          float Vout = (vldr * 0.0048828125);
          R = ((5100.0 * (5 - Vout)) / Vout);
          lux = (log10(R) - 5.6) / -0.75;
          lux = pow(10, lux);
          float cd = lux * 0.0004079732727;

          if (valInputAffiche >= cd)
          {

            luminositeLED = (valInputAffiche-cd);
          }

          luminositeLED = map(luminositeLED,0,163,0,255);

          //programme adeel

          val = digitalRead(inputPin);  // read input value
          if (val == LOW) {    // check if the input is LOW
            delay(8000);
            val = digitalRead(inputPin);        // read input values
            if (val == LOW)   // check if the input is LOW
              previousMillis = millis();
            {
              per = 1;

              analogWrite(variablePWM, luminositeLED);

              Serial.println("Motion detected!");
            }
          }
          else
          {
            currentMillis = millis();      //current time
            if (currentMillis - previousMillis >= interval)
            {

              val = digitalRead(inputPin);   //read input value
              if (val == HIGH)          //check if input is high
                delay(8000);
              val = digitalRead(inputPin);   //read input value
              if (val == HIGH)          //check if input is high
              {
                per = 0;
                digitalWrite(variablePWM, LOW); // turn LED Off
                Serial.println("Motion not detected!");
              }
            }
          }
          Serial.print("luminositeLED:");
          luminositeLED=map(luminositeLED,0,255,0,163);
          Serial.println(luminositeLED);
          
          Serial.print("capteur = ");
          Serial.println(vldr);
          Serial.print("Rersistance = ");
          Serial.println(R);
          Serial.print("cd = ");
          Serial.println(cd);/*
          delay(1000);*/
          if (dataFile) {                                                                         // Si le fichier html est ouvert et au début on envoie le contenu du fichier octet par octet au client.
            while (dataFile.available()) {
              client.write(dataFile.read());
              if (dataFile.position() == 3733) {
                // Si on atteint la position du deuxiemme = on affiche la tension sur l'entrée analogique 0.
                //client.print(an0 * TensionPleineEchelle / 1024, 3);                               // On affiche la tension lue sur le CAN.
                checkvrai = chaine[check + 11];
                if (checkvrai == actif)
                {

                  client.print(valTestModAffiche);
                  analogWrite(variablePWM, valTestMod);
                  delay(5000);


                }
                else
                {
                  client.print(cd);
                  /*analogWrite(variablePWM, valInput);
                    delay(2000);*/
                }
              }
              if (dataFile.position() == 5080) {
                client.print(valInputAffiche);
              }
            }
          }
          else Serial.println("Le fichier est pas ouvert");                                       // Si le fichier n'est pas ouvert on affiche sur le moniteur série le message correspondant.
          dataFile.seek(0);                                                                       // Remise au début du fichier pour l'affichage suivant.
          break;
        }
        if (c == '\n') {                                      // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {                                 // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }


    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();                                                                              // Fermeture de la conexion.
    Serial.println("client disonnected");
  }
}
