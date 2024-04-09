#include <LiquidCrystal.h>

int alarme = 3;

// informa quais serao as portas utilizadas pelo lcd
LiquidCrystal lcd(11, 12, 2, 3, 4, 5);

void setup()
{
  // taxa de leitura do sensor
  Serial.begin(9600);

  // informa que a porta digital A0 vai ler os dados do sensor
  pinMode(A0, INPUT);

  // inicia o lcd
  lcd.begin(16, 2);
}

void loop()
{
  // armazena o dado lido pelo sensor
  int sensorValue = analogRead(A0);

  // informa porta de saida de dados  para o buzzer
  pinMode(8, OUTPUT);

  // print de variavel de controle no terminal
  Serial.println(sensorValue);

  // checagem de valores para alarme
  if (sensorValue > 700 && alarme > 0)
  {
    digitalWrite(8, HIGH);
    delay(700);
    digitalWrite(8, LOW);
    delay(700);
    Serial.println("ta ativado");
    alarme = alarme - 1;
  }

  lcd.clear();

  // condicao para output do lcd
  if (sensorValue > 700)
  {
    lcd.setCursor(0, 0);
    lcd.print("UMIDADE BAIXA");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("UMIDADE ACEITAVEL");
    alarme = 3; // reseta o alarme
  }
  lcd.setCursor(0, 1);
  lcd.print(sensorValue);

  delay(500); // pra estabilidade
}