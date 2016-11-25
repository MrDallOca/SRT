#define inv(n) { (n) *= -1; }

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
  
void setup(){
  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(13, OUTPUT);
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
}


void loop(){
  rotacaoParaFrente(400);
  rotacaoParaFrente(-400);
  
  rotacaoParaTras(400);
  rotacaoParaTras(-400);
  
  movimentacao(400);
  movimentacao(-400);
}
