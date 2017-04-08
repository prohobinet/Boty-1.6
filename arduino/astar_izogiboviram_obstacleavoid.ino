/*
Boty1.6 demo program (prohobi.net 2017)

si-izogibanje oviram z miktostikalom (levo in desno spredaj) - veè na prohobi.net
en-avoiding obstacles with microswitch (left and right front) - more on prohobi.net
*/

#include <Servo.h>
//si-ustvarimo servo objekt za nadzor servo motorja
//en-create servo object to control a servo

Servo lservo;  // si-levi servo; en-left servo
Servo dservo;  // si-desni servo; en-right servo

//si-definiranje priklopov na vhode in izhode
//en-pin connection definiton for input and output

int lsenzorpin = 1;  // si-levi senzor; en-left sensor
int dsenzorpin = 2;  // si-desni senzor; en-right sensor
int lservopin = 10;  // si-left servo; en-left servo
int dservopin = 11;  // si-desni servo; en-right servo
int val = 0;    // variable to read the value from the digital pin

//si-konstante za krmiljenje servo motorjev
//en-constants for controlling servo motors

int vallevinaprej = 75;
int vallevinazaj = 60;
int vallevistop = 70;

int valdesnistop = 108;
int valdesninaprej = 100;
int valdesninazaj = 115;


void setup() {
  lservo.attach(lservopin);  // attaches the servo on pin -lservopin- to the servo object
  dservo.attach(dservopin);  // attaches the servo on pin -dservopin- to the servo object
  pinMode(2, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}

void loop() {
  val = digitalRead(lsenzorpin);
  if (val > 0) {
    desninaprej();
  } else {
    nazajvdesno();
  }
  delay(15);
  val = digitalRead(dsenzorpin);
  if (val > 0) {
    levinaprej();
  } else {
    nazajvlevo();
  }
  delay(15);
}

void nazajvdesno() {
  levinazaj();
  delay(15);
  desninazaj();
  delay(500);
  levistop();
  delay(500);
}

void nazajvlevo() {
  levinazaj();
  delay(15);
  desninazaj();
  delay(500);
  desnistop();
  delay(500);
}

void levistop(){
  lservo.write(vallevistop);
  delay(15);
}

void desnistop(){
  dservo.write(valdesnistop);
  delay(15);
}

void levinazaj(){
  lservo.write(vallevinazaj);
  delay(15);
}

void levinaprej(){
  lservo.write(vallevinaprej);
  delay(15);
}

void desninazaj(){
  dservo.write(valdesninazaj);
  delay(15);
}

void desninaprej(){
  dservo.write(valdesninaprej);
  delay(15);
}

