//Deklarasi PIN
int trig = 6;
int echo = 7;
long durasi, jarak;
int merah = 4;
int kuning = 3;
int hijau = 2;
int buzzer = 5;

void setup(){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(merah, OUTPUT);
  pinMode(kuning, OUTPUT);
  pinMode(hijau, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  digitalWrite(trig, HIGH);
  delayMicroseconds(8);
  digitalWrite(trig, LOW);
  delayMicroseconds(8);
  durasi = pulseIn(echo, HIGH);
  jarak = (durasi / 2) / 29.1;
  if(jarak >= 16){
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, LOW);
    digitalWrite(kuning, LOW);
    digitalWrite(buzzer, LOW);
  }else if((jarak > 8)&&(jarak < 16)){
    digitalWrite(hijau, LOW);  
    digitalWrite(merah, LOW);
    digitalWrite(kuning, HIGH);
    digitalWrite(buzzer, LOW);
  }else{
    digitalWrite(hijau, LOW);
    digitalWrite(merah, HIGH);
    digitalWrite(kuning, LOW);
    digitalWrite(buzzer, HIGH);
  }
}
