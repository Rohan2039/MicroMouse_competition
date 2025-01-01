#include<MicroMouse_General.h>

void CheckForWall(struct Wall *MazeWall){

    delay(1000)
    MazeWall->FWD = ~(digitalRead(Sensor_FWD));
    MazeWall->Right = ~(digitalRead(Sensor_FWD));
    MazeWall->Left = ~(digitalRead(Sensor_FWD));

}