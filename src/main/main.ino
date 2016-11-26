#include <math.h>

#define inv(n) { (n) *= -1; }

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

#define TRIGGER 2
#define ECHO 3
  
void setup(){
  /* Serial.begin(9600); */

  pinMode(13, OUTPUT);
  
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void rotacaoParaFrente(int q){
  // gira para esquerda?
  if (q < 0){
    inv(q)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  // então gira para direita
  else if(q > 0){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  while(q){
    delay(10);
    q--;
  }
}

void rotacaoParaTras(int q){
  // gira para esquerda?
  if (q < 0){
    inv(q)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  // então gira para direita
  else if(q > 0){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  while(q){
    delay(10);
    q--;
  }
}

void movimentacao(int q)
{
  // move para frente?
  if (q > 0){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  // move para tras?
  else if (q < 0){
    inv(q)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  // fica parado
  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  while(q){
    delay(10);
    q--;
  }

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void girar(int q)
{
  // gira para frente?
  if (q > 0){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }

  // move para tras?
  else if (q < 0){
    inv(q)
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }

  // fica parado
  else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  while(q){
    delay(10);
    q--;
  }

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void rodaEsquerdaGraus(int x){
  digitalWrite(13, HIGH);
  
  if (x > 0){
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else{
    x *= -1;
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
  }

  delay(round(1200 * x / 360));

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(13, LOW);
}

void rodaDireitaGraus(int x){
  digitalWrite(13, HIGH);
  
  if (x > 0){
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  }
  else{
    x *= -1;
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);
  }

  delay(round(1200  * x / 360));

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(13, LOW);
}

unsigned int medirDistancia(){
    //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
  digitalWrite(TRIGGER, LOW);  
  // delay de 2 microssegundos  
  delayMicroseconds(2);  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
  digitalWrite(TRIGGER, HIGH);  
  //delay de 10 microssegundos  
  delayMicroseconds(10);  
  //seta o pino 12 com pulso baixo novamente  
  digitalWrite(TRIGGER, LOW);  
  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
  long duration = pulseIn(ECHO, HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
  return round(duration /29 / 2); 
}

void destruirAdversarios(){
  while(1) {
    
    while(medirDistancia() > 20){
      girar(10);
    }

    movimentacao(150);
    movimentacao(-150);
  
    delay(1000);
  }
}

void loop(){

  /* Serial.print("Distancia em CM: ");   */
  /* Serial.println(distancia);   */
  /* delay(1000); //espera 1 segundo para fazer a leitura novamente  */

  movimentacao(60);

  destruirAdversarios();
}
