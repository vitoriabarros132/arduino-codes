const int verde = 3;
const int vermelho = 5;
const int azul = 4;

const int sensorPin = 6;

void setup()
{
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
  
  pinMode(sensorPin, OUTPUT);
}

long medirDistancia()
{
  //Lançar o pulso
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delay(2);
  digitalWrite(sensorPin, HIGH);
  delay(10);
  
  //Ler o pulso (somente valor HIGH)
  pinMode(sensorPin, INPUT);
  long duracao = pulseIn(sensorPin, HIGH);
  //0.034 cm/ms - velocidade do som; divide por 2 pra ter a ida
  //retorna em cm
  long distancia = duracao * 0.034 / 2;
  
  return distancia;
}

void loop()
{
  long distancia = medirDistancia();
  
  //limite mínimo = 20cm; (azul)
  //médio - entre 21 e 160; (verde)
  //limite máximo = 160cm (vermelho)
  
  if (distancia <= 20)
  {
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, HIGH);
  }
  else if (distancia >= 160)
  {
    digitalWrite(vermelho, HIGH);
    digitalWrite(verde, LOW);
    digitalWrite(azul, LOW);
  }
  else
  {
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    digitalWrite(azul, LOW);
  }
  
  delay(1000);
}
