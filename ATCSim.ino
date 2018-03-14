
const float pi = 3.14;

int PPR = 249;
int tempo = 200;
double D1 = 40.0;
double D2 = 40.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

int i;


for(int i=1;i<80;i++){
  setVelocidade(i);
  delay(tempo);
  }
 for(int i=80;i>2;i--){
  setVelocidade(i);
  delay(tempo);
  }
}

void setVelocidade(int v){
  noTone(6);
  noTone(7);
  int Freq = FreqParaVelocidadePPR(v,PPR,D1);
  
  int def = (1000/(Freq*4.0))*1000;
  Serial.print(Freq);
   Serial.print(" - ");
    Serial.print(v);
     Serial.print(" - ");
      Serial.println(def);
      
    tone(6, Freq);
    delayMicroseconds(def);  
    tone(7, Freq);
  
  }

int FreqParaVelocidadePPR(int v , int ppr, double d){

  return (ppr*v)/(3.6*pi*(0.0254*d));
  
  }






  
