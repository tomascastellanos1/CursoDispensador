#include <Wire.h>      // libreria de comunicacion por I2C
#include <LCD.h>      // libreria para funciones de LCD
#include <LiquidCrystal_I2C.h>    // libreria para LCD por I2C

LiquidCrystal_I2C lcd (0x27, 2, 1, 0, 4, 5, 6, 7); // DIR, E, RW, RS, D4, D5, D6, D7

int selector = 0; //Posicion en FILA (0, selector) de la flecha. 0-3

int A = 2;       //pin DT potenciometro 
int B = 4;        //pin CLK potenciometro
int boton =3;


void setup() {
  
    lcd.setBacklightPin(3,POSITIVE);  // puerto P3 de PCF8574 como positivo
    lcd.setBacklight(HIGH);   // habilita iluminacion posterior de LCD
    lcd.begin(20, 5);     // 16 columnas por 2 lineas para LCD 1602A
    lcd.clear();      // limpia pantalla

    pinMode (boton, INPUT_PULLUP); //inicio pulsador de potenciometro
    pinMode(A, INPUT);    // A como entrada
    pinMode(B, INPUT);    // B como entrada
    attachInterrupt(digitalPinToInterrupt(A), encoder, LOW);// interrupcion sobre pin A con


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
