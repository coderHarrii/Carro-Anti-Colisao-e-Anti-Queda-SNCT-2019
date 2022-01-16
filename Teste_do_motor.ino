//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup()
{
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop()
{
  //Gira o Motor A e B no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //motor b
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
  //Para os Motores A e B
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(1000);
  //Gira o Motor A no sentido anti horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //motor b
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500); 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(1000);
  //Gira somente o Motor A no sentido horario (vai virar para a esquerda)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(500);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(1000);
  //Gira somente o Motor B no sentido horario (vai virar para a direita)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(1000);
}
