
// Pines digitales usados Arduino para encender
// los correspondientes segmentos LED del display
#define A 2 
#define B 3 
#define C 4 
#define D 5 
#define E 6 
#define F 7 
#define G 8 

// Pines para A B C D E F G, en secuencia
// se pueden usar los que más interesen 
const int segs[7] = { A, B, C, D, E, F, G}; 

int cnt=0;

// Segments that make each number
const byte numbers[10] = { 
  0b0111111,    // 0 en 7seg
  0b0000110,    // 0 en 7seg
  0b1011011, 
  0b1001111, 
  0b1100110, 
  0b1101101, 
  0b1111101, 
  0b0000111, 
  0b1111111, 
  0b1101111};

void setup() {
   pinMode(A, OUTPUT);
   pinMode(B, OUTPUT);
   pinMode(C, OUTPUT);
   pinMode(D, OUTPUT);
   pinMode(E, OUTPUT);
   pinMode(F, OUTPUT);
   pinMode(G, OUTPUT);

}

void loop() {

 lightSegments(decoBCD7seg(cnt++));
 delay(1000);
}

byte decoBCD7seg(int number){
  return numbers[number];
}

void lightSegments(byte number)
 {
  for (int i = 0; i < 7; i++) 
   {
    int bit = bitRead(number, i);
    digitalWrite(segs[i], bit);
   }
 }
