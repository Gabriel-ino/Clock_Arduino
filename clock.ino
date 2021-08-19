#define sega 0
#define segb 1
#define segc 2
#define segd 3
#define sege 4
#define segf 5
#define segg 6

#define display1 13
#define display2 12
#define display3 11
#define display4 10
#define display5 9
#define display6 8

#define tempovarredura 10

const short display7seg[6] = {13, 12, 11, 10, 9, 8};

const short conversor[13] = {
 0b00111111,
 0b00000110,
 0b01011011,
 0b01001111,
 0b01100110,
 0b01101101,
 0b01111101,
 0b00000111,
 0b01111111,
 0b01101111,
};

byte dh=1, uh=2, dm=3, um=4, ds=5, us=6;
int time_;

void printdisplay(byte num){
  num = conversor[num];
  
  digitalWrite(sega, bitRead(num,0));
  digitalWrite(segb, bitRead(num,1));
  digitalWrite(segc, bitRead(num,2));
  digitalWrite(segd, bitRead(num,3));
  digitalWrite(sege, bitRead(num,4));
  digitalWrite(segf, bitRead(num,5));
  digitalWrite(segg, bitRead(num,6));


}

void varredura(short time){
  digitalWrite(display1, LOW);
  digitalWrite(display2, LOW);
  digitalWrite(display3, LOW);
  digitalWrite(display4, LOW);
  digitalWrite(display5, LOW);
  digitalWrite(display6, LOW);
  
  printdisplay(dh);
  
  digitalWrite(display1, HIGH);
  delay(time_);
  digitalWrite(display1, LOW);
  
  printdisplay(uh);
  
  digitalWrite(display2, HIGH);
  delay(time_);
  digitalWrite(display2, LOW);
  
  printdisplay(dm);
  
  digitalWrite(display3, HIGH);
  delay(time_);
  digitalWrite(display3, LOW);
  
  printdisplay(um);
  
  digitalWrite(display4, HIGH);
  delay(time_);
  digitalWrite(display4, LOW);
  
  printdisplay(ds);
  
  digitalWrite(display5, HIGH);
  delay(time_);
  digitalWrite(display5, LOW);
  
  printdisplay(us);
  
  digitalWrite(display6, HIGH);
  delay(time_);
  digitalWrite(display6, LOW);
  
}

void atualizarelogio(void){
  if (++us >= 10){
    us = 0;
    if (++ds >= 6){
      ds = 0;
      if (++um >= 10){
        um = 0;
        if (++dm >= 6){
          dm = 0;
          if (++uh >= 10){
            uh = 0;
            if (++dh >= 3){
              dh = 0;
            }
          }
        }
      }
    }
    if (dh == 2 && uh == 4){
      dh = 0;
      uh = 0;}
  }
}


void setup(){
  pinMode(sega, OUTPUT);
  pinMode(segb, OUTPUT);
  pinMode(segc, OUTPUT);
  pinMode(segd, OUTPUT);
  pinMode(sege, OUTPUT);
  pinMode(segf, OUTPUT);
  pinMode(segg, OUTPUT);
  
  pinMode(display1, OUTPUT);
  pinMode(display2, OUTPUT);
  pinMode(display3, OUTPUT);
  pinMode(display4, OUTPUT);
  pinMode(display5, OUTPUT);
  pinMode(display6, OUTPUT);
  time_ = tempovarredura;
  
  dh=1;
  uh=2;
  dm=3;
  um=4;
  ds=5;
  us=6;
  
}

void loop(){
  int i;
  for (i = 0; i < 10; i++){
    varredura(10);
    delay(40);
  }
  
  atualizarelogio();
  
}
