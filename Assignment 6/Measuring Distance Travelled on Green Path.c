//Robot C
void measure_green(int power, int time, int & count_green, int & count_notgreen)
{
	clearTimer(T1);
	nMotorEncoder[motorA] = 0;
	while (time1[T1] < time)
	{
		motor[motorA] = motor[motorC] = power;
		if (nMotorEncoder[motorA]*2*PI*2.75/360 >= 1)
		{
			int colorValue = SensorValue[S2];
			if (colorValue == (int)colorGreen)
			{
				count_green++;
			}

			else
			{
				count_notgreen++;
			}
			nMotorEncoder[motorA] = 0;
		}
	}
	motor[motorA]=motor[motorC]=0;
}

task main()
{
	SensorType[S2] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S2] = modeEV3Color_Color;
	wait1Msec(50);
	int count_green = 0;
	int count_notgreen = 0;

	while (!getButtonPress(buttonDown))
	{

		if(getButtonPress(buttonLeft))
		{
			while(getButtonPress(buttonLeft))
			{}
			measure_green(75, 2000, count_green, count_notgreen);
		}

		else if(getButtonPress(buttonRight))
		{
			while(getButtonPress(buttonRight))
			{}
			measure_green(50, 3000, count_green, count_notgreen);
		}

		else if(getButtonPress(buttonEnter))
		{
			while(getButtonPress(buttonEnter))
			{}
			measure_green(25, 4000, count_green, count_notgreen);
		}

		displayString(0, "count green is %d", count_green);
		displayString(1, "count not green is %d", count_notgreen);
	}

	while (getButtonPress(buttonDown))
	{}
}
