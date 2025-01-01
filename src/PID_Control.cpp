
#define GoalPulse_Count_FWD(int x) (x*124)
#define GoalPulse_Count_TRN(int y) (y* 12)
int Kp, Kd;

void PID_Contrologic_FWD(long enVal, int Dist){

    long Desired_Distance = GoalPulse_Count_FWD(Dist);
    static long Last_P_ErrorCount_FWD = Desired_Distance;

    long P_ErrorCount_FWD = Desired_Distance - enVal;
    int D_ErrorCount_FWD = P_ErrorCount_FWD - Last_P_ErrorCount_FWD;
    Last_P_ErrorCount_FWD = P_ErrorCount_FWD;

    int PID_OutPut_FWD = Kp * P_ErrorCount_FWD + Kd * D_ErrorCount_FWD;

    int SpeedValue = map(PID_OutPut_FWD, 0, Desired_Distance, 0, 255);

    return SpeedValue;
}

void PID_Contrologic_TRN(long enVal, int Angle){

    int Desired_Angle = GoalPulse_Count_TRN(Angle);
    static long Last_P_ErrorCount_TRN = Desired_Angle;

    long P_ErrorCount_TRN = Desired_Angle - enVal;
    int D_ErrorCount_TRN = P_ErrorCount_TRN - Last_P_ErrorCount_TRN;
    Last_P_ErrorCount_TRN = P_ErrorCount_TRN;

    int PID_OutPut_Angle = Kp * P_ErrorCount_TRN + Kd * D_ErrorCount_TRN;

    int TRN_Val = map(PID_OutPut_Angle, 0, Desired_Angle, 0, 255);

    return TRN_Val;
}