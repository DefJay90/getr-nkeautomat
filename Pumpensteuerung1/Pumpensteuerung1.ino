/// Dies ist das Programm zur Steuerung der Pumpen. Es empfängt das Jeweils gewählte Getränk und die ausgewählte Milliliteranzahl. 
/// Daraufhin werden die jeweiligen Pumpen aktiviert.




#include <SoftwareSerial.h>           //Importiert die Bibliothek für die Serververbindung. 
#include "DumbServer.h"             // Importiert die Serverdatein für die Serverertsellung. 

SoftwareSerial esp_serial(3, 2);    ///<Die Pins 2 und 3 werden für die Verbinung zum Esp-Shield benötigt. 
EspServer esp_server;
int Getraenk = 0;  ///< Hier wird das Getränk gewählt.
int i = 1;        ///< Variable für die While Schleife in Zeile 56.
long Zeit = 0; ///<  Git die Dauer an, wie lange die Pumpe laufen muss um die gewünscht Mililiteranzahl der Benutzer auszugeben.
               ///< Es wird ein long benutzt, da der Speicher von int nicht ausreicht.

void  Ledschaltung_1() {   /// Die Grüne Led wird ausgeschaltet und die rote Led eingeschaltet, darauf folgt eine Pause von 2 Sekunden bevor die Pumpen starten.
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(2000);
}


void Ledschaltung_2() {      /// Pause von 2 Sekunden, danach wird die rote Led ausgeschaltet und die grüne Led eingeschaltet.
  delay(2000);
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
}


void setup()                ///< Hier werden die einzelen Pumpen und LED's der Pins zugeordnet. 
                            ///< Wlan Koummunikation startet hier.
{
  pinMode(6, OUTPUT);    //LED Grün
  pinMode(7, OUTPUT);    //LED Rot
  pinMode(8, OUTPUT);    //Pumpe 1      Apfelssaft
  pinMode(9, OUTPUT);    //Pumpe 2      Orangensaft
  pinMode(10, OUTPUT);   //Pumpe 3      Eistee
  pinMode(11, OUTPUT);   //Pumpe 4      Korn
  pinMode(12, OUTPUT);   //Pumpe 5      Wodka

  Serial.begin(9600);   //Baudrate für den Seriellen Monitor wird auf 9600 gesetzt.
  esp_serial.begin(9600);    //Baudrate für die Serverausgabe wird auf 9600 gesetzt.
  Serial.println("Starting server...");
  esp_server.begin(&esp_serial, "AndroidAP", "123456789", 30303);    // Zugangsdaten für die Verbinung zum Internet.
  Serial.println("...server is running");



}

void loop() {

  digitalWrite(6, HIGH);    // Grüne LED wird eingeschaltet.
  Serial.println("Wähle ein Getränk!");     // Getränkeauswahl.

  Getraenk = esp_server.parseInt();                    //Gibt die erste gültige Ganze Zahl aus dem seriellen Puffer zurück. Buchstaben werden ignoriert.
  Serial.println ( Getraenk );


  if (Getraenk > 0) {                                // Wenn ein Getränk ausgewählt wurde, dann soll die nächste Schleife ausgeführt werden.

    while (i == 1) {                                  // Solange die Variable i auf 1 ist soll nach der Anzhal der Milliliter gefragt werden.
      Serial.println("Wie viele Milliliter ? ");     // Millilitereingabe.

      Zeit = esp_server.parseInt();                   //Gibt die erste gültige Ganze Zahl aus dem seriellen Puffer zurück. Buchstaben werden ignoriert.
      Serial.println ( Zeit);


      if (Zeit >= 1) { // Erst wenn der Benutzer die Milliter Anzahl eingegebn hat, wird für die Schleife für die Pumpen ausgeführt.


        if (Zeit == 1) {         // Falls der Benutzer den Bestellvorgang abricht, wird eine 1 gesendet und die Zeit und Getraenk auf Nulll gesetzt damit die Pumpen nicht laufen.
          Getraenk = 0;
          Zeit = 0;              
        }

        Zeit =  333 + Zeit * 1000 / 29  ;            // Die Pumpe pumpt 29 ml pro sekunde.

        if (Getraenk == 1) {               //Apfelsaft
          Ledschaltung_1();
          digitalWrite(8, HIGH);
          delay (Zeit);
          digitalWrite(8, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 2) {                  // Orangensaft
          Ledschaltung_1();
          digitalWrite(9, HIGH);
          delay (Zeit); 
          digitalWrite(9, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 3) {                 // Eistee
          Ledschaltung_1();
          digitalWrite(10, HIGH);
          delay (Zeit);
          digitalWrite(10, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 4) {                //KORN
          Ledschaltung_1();
          digitalWrite(11, HIGH);
          delay (Zeit); 
          digitalWrite(11, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 5) {               //WODKA
          Ledschaltung_1();
          digitalWrite(12, HIGH);
          delay (Zeit); 
          digitalWrite(12, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 6) {                 //Korn-Apfelsaft
          Ledschaltung_1();
          digitalWrite(11, HIGH);
          delay (Zeit * 0.25);
          digitalWrite(11, LOW);
          delay(2000);
          digitalWrite(8, HIGH);
          delay (Zeit * 0.75); 
          digitalWrite(8, LOW);
          Ledschaltung_2();

        }

        if (Getraenk == 7) {               //Korn-Orangensaft
          Ledschaltung_1();
          digitalWrite(11, HIGH);
          delay (Zeit * 0.25);
          digitalWrite(11, LOW);
          delay(2000);
          digitalWrite(9, HIGH);
          delay (Zeit * 0.75); 
          digitalWrite(9, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 8) {               //Wodka-Apfelsaft
          Ledschaltung_1();
          digitalWrite(12, HIGH);
          delay (Zeit * 0.25);
          digitalWrite(12, LOW);
          delay(2000);
          digitalWrite(8, HIGH);
          delay (Zeit * 0.75); 
          digitalWrite(8, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 9) {               //Wodka-Orangensaft
          Ledschaltung_1();
          digitalWrite(12, HIGH);
          delay( Zeit * 0.25);
          digitalWrite(12, LOW);
          delay(2000);
          digitalWrite(9, HIGH);
          delay (Zeit * 0.75); 
          digitalWrite(9, LOW);
          Ledschaltung_2();
        }

        if (Getraenk == 10) {               //Wodka-Eistee
          Ledschaltung_1();
          digitalWrite(12, HIGH);
          delay( Zeit * 0.25);
          digitalWrite(12, LOW);
          delay(2000);
          digitalWrite(10, HIGH);
          delay (Zeit * 0.75); 
          digitalWrite(10, LOW);
          Ledschaltung_2();
        }
        if (Getraenk == 11) {               //Korn-Eistee
          Ledschaltung_1();
          digitalWrite(11, HIGH);
          delay( Zeit * 0.25);
          digitalWrite(11, LOW);
          delay(2000);
          digitalWrite(10, HIGH);
          delay (Zeit * 0.75); 
          digitalWrite(10, LOW);
          Ledschaltung_2();
        }

        Getraenk = 0;    // Die Pumpen Schleife wurde ausgeführt, die Variable des gewählten Getränks wird wieder auf 0 gesetzt, damit kein Getränk mehr gewählt ist.

        i = 0;          //  Die Variable i wird auf 0 gesetzt, damit das Programm aus der while schleife " springt".
      }
    }
    i = 1;       //  Die Variable i wird wieder auf 1 gesetzt, damit beim nächsten Getränk die While schleife wieder nach der Milliliteranzahl fragt.
  }
  Zeit = 0;      // Mililiter wird auf 0 gesetzt.
}






