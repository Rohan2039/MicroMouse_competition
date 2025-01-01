#include<MicroMouse_General.h>

void MoveFwd(int Dist){

    int Speed_Val_1 = 0, Speed_Val_2 = 0;
    while(1){

        Speed_Val_1 = PID_Contrologic_FWD(enVal_1, Dist);
        Speed_Val_2 = PID_Contrologic_FWD(enVal_2, Dist);
        //For wheel Right
        ledcwrite(0, Speed_Val_1);
        digitalWrite(MotorRightPin_REV, LOW);

        //For wheel Left
        ledcwrite(2, Speed_Val_2);
        digitalWrite(MotorLeftPin_REV, LOW);

        if((enVal_1<Threshold_Dist) || (enVal_2<Threshold_Dist)) {
            ledcwrite(0, 0);
            ledcwrite(2, 0);
            break;
        }
    }
}

void MoveRight(int Angle){
    int TRN_Val_1 = 0, TRN_Val_2 = 0; 

    while(1){
        TRN_Val_1 = PID_Contrologic_TRN(enVal_1, Angle);
        TRN_Val_2 = PID_Contrologic_TRN(enVal_2, Angle); 
        
        //For Wheel Right
        ledcwrite(1, TRN_Val_1);
        digitalWrite(MotorRightPin_FWD, LOW);

        //For Wheel Left
        ledcwrite(2, TRN_Val_2);
        digitalWrite(MotorLeftPin_REV, LOW);

       if((enVal_1<Threshold_Angle) || (enVal_2<Threshold_Angle)){
            ledcwrite(1, 0);
            ledcwrite(2, 0);
            break;
        }
        
    }
}

void MoveLeft(int Angle){
    
    int TRN_Val_1 = 0,TRN_Val_2=0;

    while(1){
        TRN_Val = PID_Contrologic_TRN(enVal, Angle);

        //For Wheel Right
        ledcwrite(0, TRN_Val_1);
        digitalWrite(MotorRightPin_REV, LOW);

        //For Wheel Left
        ledcwrite(3, TRN_Val_2);
        digitalWrite(MotorLeftPin_FWD, LOW);

        if((enVal_1<Threshold_Angle) || (enVal_2<Threshold_Angle)){
            ledcwrite(0, 0);
            ledcwrite(3, 0);
            break;
        }
        
    }
}