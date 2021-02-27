int M_A1 = 2; //motor a = +; in1
int M_A2 = 3; //motor a = -; in2
int S_A = 10;  //speed motor a; enA

int M_B1 = 4; //motor b = -; in3
int M_B2 = 5; //motor b = +; in4
int S_B = 9;  //speed motor b; enB

float S_0 = A0; //sensor 0 
float S_1 = A1; //sensor 1
float S_2 = A2; //sensor 2 
float S_3 = A3; //sensor 3 
float S_4 = A4; //sensor 4 

void setup(){
  
  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT);
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(S_B, OUTPUT);
  pinMode(S_A, OUTPUT);
  
  analogWrite(S_A, 150);
  analogWrite(S_B, 150); 

}

void loop(){  
  
  float sen0 = map(analogRead(S_0), 0, 1023, 0, 255);
  float sen1 = map(analogRead(S_1), 0, 1023, 0, 255);
  float sen2 = map(analogRead(S_2), 0, 1023, 0, 255);
  float sen3 = map(analogRead(S_3), 0, 1023, 0, 255);
  float sen4 = map(analogRead(S_4), 0, 1023, 0, 255);

  // fwd conditions
  if ((isBlack(sen0) == 0) && (isBlack(sen1) == 0) && (isBlack(sen2) == 1) && (isBlack(sen3) == 0) && (isBlack(sen4) == 0)) // forward  
    fwd();

  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 1) && (isBlack(sen2) == 1) && (isBlack(sen3) == 1) && (isBlack(sen4) == 0)) // forward intersection
    fwd();
    
  // left turns
  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 0) && (isBlack(sen2) == 1) && (isBlack(sen3) == 1) && (isBlack(sen4) == 0))  // turn left
    turnLeft();
  
  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 0) && (isBlack(sen2) == 0) && (isBlack(sen3) == 1) && (isBlack(sen4) == 0))  // turn left
    turnLeft();
  
  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 0) && (isBlack(sen2) == 0) && (isBlack(sen3) == 0) && (isBlack(sen4) == 1))  // hard left
    hardLeft();

  // right turns
  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 1) && (isBlack(sen2) == 1) && (isBlack(sen3) == 0) && (isBlack(sen4) == 0))  // turn right
    turnRight();
 
  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 1) && (isBlack(sen2) == 0) && (isBlack(sen3) == 0) && (isBlack(sen4) == 0)) // turn right
    turnRight();
    
  else if ((isBlack(sen0) == 1) && (isBlack(sen1) == 0) && (isBlack(sen2) == 0) && (isBlack(sen3) == 0) && (isBlack(sen4) == 0)) // hard right
    hardRight();

 // acute turn conditions
  else if ((isBlack(sen0) == 0) && (isBlack(sen1) == 0) && (isBlack(sen2) == 1) && (isBlack(sen3) == 1) && (isBlack(sen4) == 1)) // acute left
    acuteLeft();

  else if ((isBlack(sen0) == 1) && (isBlack(sen1) == 1) && (isBlack(sen2) == 1) && (isBlack(sen3) == 0) && (isBlack(sen4) == 0)) // acute right
    acuteRight();

  else
    Stop();
  
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
bool isBlack(int sen){
  if (sen > 100)
    return true;
  else 
    return false;
}

void fwd(){
  analogWrite(S_A, 150);
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW); 
  delay(20); 
}
 
void turnLeft(){
  analogWrite(S_A, 200); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void turnRight(){
  analogWrite(S_B, 200);
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void hardLeft(){
  analogWrite(S_A, 255); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void hardRight(){
  analogWrite(S_B, 255);
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void acuteLeft(){
  analogWrite(S_A, 150); 
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
  delay(20);
}

void acuteRight(){
  analogWrite(S_B, 150);
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void Stop(){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  delay(20);