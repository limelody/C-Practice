task main()
{
	SensorType[S1] = sensorEV3_Touch;
	displayString (0, "Tues evening 23");
	wait1Msec(3000);
	eraseDisplay();


		for (int button_press = 0; button_press < 3;)
		{
			if (getButtonPress (buttonRight))
			{
				while (getButtonPress(buttonRight))
				{}
				
				motor[motorA] = 75;
				motor[motorC] = -75;
				wait1Msec(400);
				motor[motorA] = 0;
				motor[motorC] = 0;
				wait1Msec(1500);
				button_press++;
			}


			else if (getButtonPress(buttonLeft))
			{
				while (getButtonPress (buttonLeft))
				{}
				motor[motorA] = -75;
				motor[motorC] = 75;
				wait1Msec(400);
				motor[motorA] = 0;
				motor[motorC] = 0;
				wait1Msec(1500);
				button_press++;
			}

			else if (getButtonPress(buttonEnter))
			{
				while (getButtonPress (buttonEnter))
				{}
				displayString(0,"Vamanos");
				motor[motorA] = 100;
				motor[motorC] = 100;
				wait1Msec(2000);
				motor[motorA] = 0;
				motor[motorC] = 0;
				button_press++;
			}
		}

		while (SensorValue [S1] == 0)
		{
			motor[motorA] = 75;
			motor[motorC] = 20;
		}

	motor[motorA] = 0;
	motor[motorC] = 0;
}
