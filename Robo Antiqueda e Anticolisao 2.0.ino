/*____________________________________________________________________________________________________

OBS: Esta é a versão mais atualizada que encontrei no pendrive, em breve providencio a versão final

_____________________________________________________________________________________________________*/
#include <Ultrasonic.h>
#include <Servo.h>
#define pino_trigger 9 //Sensor de Cima
#define pino_echo 8
#define leed 7

#define pino_triggger 12 //Sensor de Baixo
#define pino_eccho 11
#define led 13

//Definicoes pinos Arduino ligados a entrada da Ponte H
int val; 
int ChaveEsquerda;
int ChaveCentral;
int ChaveDireita; 
int IN1 = 1;
int IN2 = 2;
int IN3 = 3;
int IN4 = 4;
Servo myservo;
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
Ultrasonic ultrasonic2(pino_triggger, pino_eccho);

void setup()
{
  
  Serial.begin(115200);
  
  Serial.println("Lendo dados do sensor...");
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(leed, OUTPUT);
   myservo.attach(10); 
    pinMode(ChaveEsquerda, INPUT);        //Aciona o resistor pull-up interno  
    digitalWrite(ChaveEsquerda, HIGH);    
    pinMode(ChaveCentral, INPUT); 
    digitalWrite(ChaveCentral, HIGH); 
    pinMode(ChaveDireita, INPUT);  
    digitalWrite(ChaveDireita, HIGH);
}

void loop()
{
//Le as informacoes do sensor, em cm e pol

  float cmMsec1,cmMsec2,inMsec1, inMsec2;
  
  long microsec1 = ultrasonic.timing();
  cmMsec1 = ultrasonic.convert(microsec1, Ultrasonic::CM);
  inMsec1 = ultrasonic.convert(microsec1, Ultrasonic::IN);
//DELAY
  long microsec2 = ultrasonic2.timing();
  cmMsec2 = ultrasonic.convert(microsec2, Ultrasonic::CM);
  inMsec2 = ultrasonic.convert(microsec2, Ultrasonic::IN);
//DELAY
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm sensor largura (1): ");
  Serial.print(cmMsec1);
  Serial.print(" - Distancia em polegadas sensor largura (1): ");
  Serial.println(inMsec1);
  delay(100);
  Serial.print("Distancia em cm sensor altura (2): ");
  Serial.print(cmMsec2);
  Serial.print(" - Distancia em polegadas sensor de altura (2): ");
  Serial.println(inMsec2);
  delay(100);
  
  if((cmMsec1) >= 20){
  //Gira os Dois Motores no Sentido Horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //motor b
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(leed, LOW);
  
  }
  if((cmMsec1) < 20){ //imprime o valor da variavel distancia
  //Para os Motores A e B
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(leed, HIGH);
  delay(500);
  
  myservo.write(45);
  delay(500); 
  myservo.write(-100);
  delay(500);
  myservo.write(115);
  delay(500);
  myservo.write(45);
  delay(500);

  digitalWrite(IN1, LOW); // DA RÉ
  digitalWrite(IN2, HIGH);
  //motor b
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);
  
  digitalWrite(IN1, HIGH);  //VIRA PARA ESQUERDA
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(100);
  digitalWrite(leed, HIGH);
  
  }
  if((cmMsec2) >= 5){ //imprime o valor da variavel distancia
  //Para os Motores A e B
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  digitalWrite(led, HIGH);
  delay(500);
  
  digitalWrite(IN1, LOW); // DA RÉ
  digitalWrite(IN2, HIGH);
  //motor b
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(100);
  
  digitalWrite(IN1, HIGH);  //VIRA PARA ESQUERDA
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(100);
  }
  if((cmMsec2) < 5){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //motor b
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  digitalWrite(led, LOW);
  digitalWrite(leed, LOW);
  }
}
