#include <Arduino.h>

#define PPR 7
#define GearRatio 150
#define Pi 3.14
#define Diameter 34

int Calculate_Dist(long enVal){

    float  Circumference = Pi * Diameter;
    float Pulse1_Rotation = PPR * GearRatio;
    float  RotationNumber = (enVal / Pulse1_Rotation);
    float Distance = Circumference * RotationNumber;

    Serial.println(RotationNumber);

    return Distance;
}