#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7

int selector = 0; //Posicion en FILA (0, selector) de la flecha. 0-3

int A = 2;       //pin DT potenciometro 
int B = 4;        //pin CLK potenciometro
int boton =3;


int rele = 8;
int rele2 = 9;
int rele3 = 10;
int rele4 = 11;

bool cocacola =false;
bool fanta =false;
bool agua =false;
bool nestea =false;


void setup() {
  
    lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
    lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
    lcd.begin(20, 5);     // 16 columnas por 2 lineas para LCD 1602A
    lcd.clear();      // limpia pantalla

    pinMode (boton, INPUT_PULLUP); //inicio pulsador de potenciometro
    pinMode(A, INPUT);    // A como entrada
    pinMode(B, INPUT);    // B como entrada
    attachInterrupt(digitalPinToInterrupt(A), encoder, LOW);// interrupcion sobre pin A con

    pinMode (rele, OUTPUT);
    pinMode (rele2, OUTPUT);
    pinMode (rele3, OUTPUT);
    pinMode (rele4, OUTPUT);
    lcd.clear();
}

void loop() {

    int estado = digitalRead (boton);
    
    lcd.setCursor(0, selector+1);
    lcd.print(" ");
    lcd.setCursor(0, selector-1);
    lcd.print(" ");



    lcd.setCursor(0, selector);
    lcd.print(">");
       
    lcd.setCursor(1, 0); //cursor en columna 0 y linea 1
    lcd.print("Agua");

    lcd.setCursor(1,1);
    lcd.print("Coca Cola");

    lcd.setCursor(1,2);
    lcd.print("Fanta");

    lcd.setCursor(1,3);
    lcd.print("Nestea");

    if(selector < 0){
    selector=0;
    }
  
    if(selector >3){
    selector=3;
    }

digitalWrite (rele, HIGH);
digitalWrite (rele2, HIGH);
digitalWrite (rele3, HIGH);
digitalWrite (rele4, HIGH);
    
  if (estado==LOW){
  if (selector ==0){
 selector=0;
agua=true;
}
if (selector ==1){
selector=0;
 cocacola = true;
}
if (selector ==2){
 selector=0;
  fanta=true;
}
if (selector ==3){
selector=0;
  nestea=true;
}

 }


  if (cocacola ==true){ 
   digitalWrite (rele, LOW);
  delay (3000);
  digitalWrite (rele, HIGH);
  cocacola = false;
 lcd.clear();
 }
 if (fanta ==true){ 
   digitalWrite (rele2, LOW);
  delay (3000);
  digitalWrite (rele2, HIGH);
  fanta = false;
 lcd.clear();
}
if (nestea ==true){
   digitalWrite (rele3, LOW);
  delay (3000);
  digitalWrite (rele3, HIGH);
  nestea = false;
 lcd.clear();
 }   
  if (agua ==true){ 
 digitalWrite (rele4, LOW);
  delay (3000);
  digitalWrite (rele4, HIGH);
  agua = false;
 
 lcd.clear();
 }

 
Serial.println(selector);
  }



void encoder()  {
  static unsigned long ultimaInterrupcion = 0;  
  unsigned long tiempoInterrupcion = millis(); 

  if (tiempoInterrupcion - ultimaInterrupcion > 1) {       
    if (digitalRead(B) == HIGH)     
    {      
selector -=1; //Restamos una posicion al selector
    }
    else {               
selector +=1; //Sumamos una posicion al selector
    }
    ultimaInterrupcion = tiempoInterrupcion; 
}
}
