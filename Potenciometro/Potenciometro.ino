

int selector = 0; //Posicion en FILA (0, selector) de la flecha. 0-3

int A = 2;       //pin DT potenciometro 
int B = 4;        //pin CLK potenciometro
int boton =3;


void setup() {
  
    
    pinMode (boton, INPUT_PULLUP); //inicio pulsador de potenciometro
    pinMode(A, INPUT);    // A como entrada
    pinMode(B, INPUT);    // B como entrada
    attachInterrupt(digitalPinToInterrupt(A), encoder, LOW);// interrupcion sobre pin A con


}

void loop() {

    int estado = digitalRead (boton);

    

  
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
