#include <Ultrasonic.h>
#define pino_trigger 9 //Sensor de Cima
#define pino_echo 8

Ultrasonic ultrasonic(pino_trigger, pino_echo);
Ultrasonic ultrasonic2(pino_triggger, pino_eccho);

void setup()
{
  Serial.begin(115200);
  
  Serial.println("Lendo dados do sensor...");
}
void loop()
{
//Le as informacoes do sensor, em cm e pol
}
  float cmMsec1,cmMsec2,inMsec1, inMsec2;
  
  long microsec1 = ultrasonic.timing();
  cmMsec1 = ultrasonic.convert(microsec1, Ultrasonic::CM);
  inMsec1 = ultrasonic.convert(microsec1, Ultrasonic::IN);
  delay(100);
  
  long microsec2 = ultrasonic2.timing();
  cmMsec2 = ultrasonic.convert(microsec2, Ultrasonic::CM);
  inMsec2 = ultrasonic.convert(microsec2, Ultrasonic::IN);
  delay(100);
  
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm sensor largura (1): ");
  Serial.print(cmMsec1);
  Serial.print(" - Distancia em polegadas sensor largura (1): ");
  Serial.println(inMsec1);
  delay(500); 
  Serial.print("Distancia em cm sensor altura (2): ");
  Serial.print(cmMsec2);
  Serial.print(" - Distancia em polegadas sensor de altura (2): ");
  Serial.println(inMsec2);
  delay(500);
  }
