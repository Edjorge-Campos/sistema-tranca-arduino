#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

 static const int ledVermelho = 12;
 static const int ledVerde = 11;
 Servo motorFisico;
 LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

 static const char password[4] = {'1', '2', '3', '4'};
 static char inputUser[4];
 static int tamanhoPI = 0;

 static const char keyPad[4][4] = {
   { '1', '2', '3', 'A'},
   { '4', '5', '6' ,'B'},
   { '7', '8', '9' ,'C'},
   { '*', '0', '#' ,'D'}
  };

  byte linhas[4] = {2,3,4,5};
  byte colunas[4] = {6,7,8,9};
  Keypad teclado = Keypad(makeKeymap(keyPad), linhas, colunas, 4, 4);



void funcionamentoMotor(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tranca aberta");
  digitalWrite(ledVerde, HIGH);
  motorFisico.write(90);
  delay(2000);
  motorFisico.write(0);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tranca fechada");
}

void escreverEcra(const char msg[]){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(msg);
  delay(2000);
  lcd.clear();
  lcd.print("Tranca fechada");
}

void ligarLed(int led){
  digitalWrite(led, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
}
 
void setup(){
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
  reiniciarInput();
  motorFisico.attach(10);
  motorFisico.write(0);
  lcd.begin(16,2);
  lcd.print("Tranca fechada");
}

void reiniciarInput(){
  tamanhoPI = 0;
      for(int j = 0; j < 4; j++){
        inputUser[j] = '-';
      }  
}


void loop(){
  char inputTecla = teclado.getKey();
  int i;

  if(inputTecla != NO_KEY){
    Serial.println(inputTecla);
    if(inputTecla == '#'){
      digitalWrite(ledVermelho, LOW);
      for(i = 0; i < 4; i++){
        if(inputUser[i] != password[i]){
          digitalWrite(ledVermelho, HIGH);
          escreverEcra("Pass errada");
          digitalWrite(ledVermelho, LOW);
          reiniciarInput();
          break;
        } 
      }

      if(i == 4){
        escreverEcra("Pass certa");
        reiniciarInput();
        funcionamentoMotor();
        return;
      }
    } else {
      if(tamanhoPI < 4) {
        inputUser[tamanhoPI] = inputTecla;
        if(tamanhoPI == 0) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Introduza: ");
          digitalWrite(ledVermelho, LOW);
        }
        lcd.setCursor(tamanhoPI, 1);
        lcd.print("*");
        tamanhoPI++;
      }else{
        escreverEcra("Pass invalida");
        ligarLed(ledVermelho);
        reiniciarInput();
      }
    }
  } 
}

