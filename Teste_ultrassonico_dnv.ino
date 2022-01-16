#include <Ultrasonic.h>
#define pino_trigger 10 //Sensor de Cima
#define pino_echo 9

Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
}
void loop()
{
 
//Le as informacoes do sensor, em cm e pol

  float cmMsec1,inMsec1;
  
  long microsec1 = ultrasonic.timing();
  cmMsec1 = ultrasonic.convert(microsec1, Ultrasonic::CM);
  inMsec1 = ultrasonic.convert(microsec1, Ultrasonic::IN);
  delay(100);
  
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm sensor largura (1): ");
  Serial.print(cmMsec1);
  Serial.print(" - Distancia em polegadas sensor largura (1): ");
  Serial.println(inMsec1);
  delay(500); 
}
