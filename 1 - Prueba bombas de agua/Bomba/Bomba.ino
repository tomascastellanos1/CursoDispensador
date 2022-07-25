int rele = 10;
int rele2 = 9;

void setup() {
  // put your setup code here, to run once:

pinMode (rele,OUTPUT);
pinMode (rele2,OUTPUT);
 
}

void loop() {

 
  digitalWrite(rele, LOW);
  digitalWrite(rele2, HIGH);
  delay (4000);
  digitalWrite(rele, HIGH);
  digitalWrite(rele2, HIGH);
  delay (1000);
  digitalWrite(rele, HIGH);
  digitalWrite(rele2, LOW);
  delay (4000);
  digitalWrite(rele, HIGH);
  digitalWrite(rele2, HIGH);
  delay (4000);
  
}
