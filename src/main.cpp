#include<MicroMouse_General.h>

int enLeft_1 = 32;
int enLeft_2 = 33;
int enRight_1 = 18;
int enRight_2 = 19;

struct Wall{
  bool Left;
  bool Right;
  bool Fwd;
} Maze_Wall;

void Encoder_Check_1();
void Encoder_Check_2();

void setup(){
  Serial.begin(9600);

  pinMode(enLeft_1, INPUT_PULLUP);
  pinMode(enLeft_2, INPUT_PULLUP);
  pinMode(enRight_1, INPUT_PULLUP);
  pinMode(enRight_2, INPUT_PULLUP);

  pinMode(Sensor_FWD, INPUT_PULLUP);
  pinMode(Sensor_Left, INPUT_PULLUP);
  pinMode(Sensor_Right, INPUT_PULLUP);

  pinMode(MotorRightPin_FWD, OUTPUT);
  pinMode(MotorRightPin_REV, OUTPUT);
  pinMode(MotorLeftPin_FWD, OUTPUT);
  pinMode(MotorLeftPin_REV, OUTPUT);

  ledcAttachPin(MotorRightPin_FWD, 0);
  ledcAttachPin(MotorRightPin_REV, 1);
  ledcAttachPin(MotorLeftPin_FWD, 2);
  ledcAttachPin(MotorLeftPin_REV, 3);

  attachInterrupt(enLeft_1, Encoder_Check_1, CHANGE);
  attachInterrupt(enLeft_2, Encoder_Check_1, CHANGE);
  attachInterrupt(enRight_1, Encoder_Check_2, CHANGE);
  attachInterrupt(enRight_2, Encoder_Check_2, CHANGE);

  Serial.println("Setup is done");
}

void Encoder_Check_1(){

  int MSB = digitalRead(enLeft_1); //MSB = most significant bit
  int LSB = digitalRead(enLeft_2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (last_enVal << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) enVal_1 ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) enVal_1 ++;

  last_enVal = encoded; //store this value for next time
  
}

void Encoder_Check_2(){

  int MSB = digitalRead(enRight_1); //MSB = most significant bit
  int LSB = digitalRead(enRight_2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (last_enVal << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) enVal_2 ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) enVal_2 ++;

  last_enVal = encoded; //store this value for next time
  
}

void loop(){
  
  CheckForWall(&Maze_Wall);
  FindPathAlgo(Maze_Wall);
}
