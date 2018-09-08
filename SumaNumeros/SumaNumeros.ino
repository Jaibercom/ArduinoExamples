

 
int num = 0;
int num1 = 0;
int num2 = 0;
bool pos = false;
int cnt = 0;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  Serial.println("Mensaje de bienvenida");

}

int readInt(){

  int numLocal;
  //Serial.print("Escriba un entero:");
  
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    numLocal = Serial.read() - '0';

    Serial.printf("He recibido: %d", numLocal);
    //Serial.println("");
    //Serial.println(numLocal, DEC);
    //Serial.println(numLocal, BIN);
    cnt++;

     if(cnt == 1){
        num1 = numLocal;
     }

     if(cnt == 2){
        num2 = numLocal;
     }

    
  }
  return numLocal;
}
  
int sum(int a, int b){
    return a+b;
}

void loop() {

  readInt();

  if(cnt == 2){
    
    Serial.print("La suma es: ");
    Serial.println(sum(num1, num2));
    cnt=0;
  }

  delay(500);
}
