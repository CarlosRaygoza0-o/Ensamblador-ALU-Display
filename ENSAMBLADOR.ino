//DEFINICIÓN DE CADA UNO DE LOS SEGMENTOS DEL DISPLAY 1
const int D1A = 2;
const int D1B = 3;
const int D1C = 4;
const int D1D = 5;
const int D1E = 6;
const int D1F = 7;
const int D1G = 8;
//DEFINICIÓN DE CADA UNO DE LOS SEGMENTOS DEL DISPLAY 2
const int D2A = 9;
const int D2B = 10;
const int D2C = 11;
const int D2D = 12;
const int D2E = 13;
const int D2F = 14;
const int D2G = 15;
//LED QUE MARCARÁ EL NEGATIVO SI EL NÚMERO ES MAYOR A 9
const int NEG = 16;

void setup() {
  Serial.begin(9600);

  pinMode(NEG, OUTPUT);

  pinMode(D1A, OUTPUT);
  pinMode(D1B, OUTPUT);
  pinMode(D1C, OUTPUT);
  pinMode(D1D, OUTPUT);
  pinMode(D1E, OUTPUT);
  pinMode(D1F, OUTPUT);
  pinMode(D1G, OUTPUT);

  pinMode(D2A, OUTPUT);
  pinMode(D2B, OUTPUT);
  pinMode(D2C, OUTPUT);
  pinMode(D2D, OUTPUT);
  pinMode(D2E, OUTPUT);
  pinMode(D2F, OUTPUT);
  pinMode(D2G, OUTPUT);

}

void loop() {
  if (Serial.available() > 0) {
    int numero1 = Serial.parseInt();
    char operacion = Serial.read();
    int numero2 = Serial.parseInt();
    int numero3 = Serial.parseInt();
    int resultado = 0;
    int absoluto = 0;

    switch (operacion) {
      case '+':
        resultado = numero1 + numero2 + numero3;
        break;
      case '-':
        resultado = numero1 - numero2 - abs(numero3);
        break;
      case '*':
        resultado = numero1 * numero2;
        break;
      case '/':
        if (numero2 != 0) {
          resultado = numero1 / numero2;
        } else if(numero1 == 0 && numero2 == 0) {
          Serial.println("Error: Resultado Indefinido");
        } else {
          Serial.println("Error: Resultado Infinito");
          return;
        }
        break;
    }

    if (resultado <= 99 && resultado >= 0) {
      if (resultado > 9) {
        int unidades = resultado % 10;
        int decenas = resultado / 10;
        displayNumero(unidades, D2A, D2B, D2C, D2D, D2E, D2F, D2G);
        displayNumero(decenas, D1A, D1B, D1C, D1D, D1E, D1F, D1G);
      } else {
        displayNumero(resultado, D2A, D2B, D2C, D2D, D2E, D2F, D2G);
      }
      Serial.println(resultado);
    } else if (resultado < 0) {
      absoluto = abs(resultado);
      if (absoluto <= 99) {
        if (absoluto > 9) {
          int unidades = absoluto % 10;
          int decenas = absoluto / 10;
          digitalWrite(NEG, HIGH);
          displayNumero(unidades, D2A, D2B, D2C, D2D, D2E, D2F, D2G);
          displayNumero(decenas, D1A, D1B, D1C, D1D, D1E, D1F, D1G);
        } else {
          digitalWrite(D1G, HIGH);
          displayNumero(absoluto, D2A, D2B, D2C, D2D, D2E, D2F, D2G);
        }
      } 
        Serial.println(resultado);
    } else {
      Serial.println("Resultado demasiado grande para mostrarlo en el display");
    }

    delay(9000);
    clearDisplay(); 
  }
}

void displayNumero(int numero, int segA, int segB, int segC, int segD, int segE, int segF, int segG) {
  switch(numero) {
    case 0:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);
      break;
    case 1:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    case 2:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      break;
    case 3:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      break;
    case 4:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 5:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 6:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 7:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      break;
    case 8:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    case 9:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      break;
    default:
      break;
  }
}

void clearDisplay() {
  digitalWrite(NEG, LOW);

  digitalWrite(D1A, LOW);
  digitalWrite(D1B, LOW);
  digitalWrite(D1C, LOW);
  digitalWrite(D1D, LOW);
  digitalWrite(D1E, LOW);
  digitalWrite(D1F, LOW);
  digitalWrite(D1G, LOW);

  digitalWrite(D2A, LOW);
  digitalWrite(D2B, LOW);
  digitalWrite(D2C, LOW);
  digitalWrite(D2D, LOW);
  digitalWrite(D2E, LOW);
  digitalWrite(D2F, LOW);
  digitalWrite(D2G, LOW);
}