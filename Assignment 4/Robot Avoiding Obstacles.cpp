task main() 
{
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic; 
	nMotorEncoder[motorA] = 0;
	const int ENC_LIMIT_VERTICAL = 5900 * 360 / (2 * PI * 2.75);
	const int ENC_LIMIT_RIGHT = 100 * 360 / (2 * PI * 2.75); 
	int duckCounter = 0; 

	if (getButtonPress(buttonEnter))
	{
		while (getButtonPress(buttonEnter)) 
		{}
		
		for (int turnCounter = 0;  turnCounter < 100;) 
		{
			while (SensorValue[S1] == 0  && nMotorEncoder[motorA] < ENC_LIMIT_VERTICAL) 
			{ 
				motor[motorA] = motor[motorC] = 75; 
			}

			while (SensorValue[S1] == 0) 
			{ 
if (nMotorEncoder[motorA] == ENC_LIMIT_VERTICAL) 
/*assume robot doesn't go over and will immediately execute command after travelling 59m*/
				{
					nMotorEncoder[motorA] = 0;
					if (turnCounter%2 == 0) //turnRight
					{
						motor[motorA] = 75;
						motor[motorC] = -75; 
						wait1Msec(400);
//assume turning distance isn't calculated into the encoder
		
						while (nMotorEncoder[motorA] < ENC_LIMIT_RIGHT)
						{
							motor[motorA] = motor[motorC] = 75;
						}
		
						motor[motorA] = 75;
						motor[motorC] = -75;
						wait1Msec(400); 
						turnCounter ++; 
					}
		
					else if (turnCounter%2 != 0) //turnLeft
					{
					motor[motorA] = -75;
					motor[motorC] = 75; 
					wait1Msec(400);
		
					while (nMotorEncoder[motorA] < ENC_LIMIT_RIGHT) 
					{
						motor[motorA] = motor[motorC] = 75;
					}
					
					motor[motorA] = -75;
					motor[motorC] = 75;
					wait1Msec(400); 
					turnCounter++;
					}
				}
				nMotorEncoder[motorA] = 0;
			}
	
			if (SensorValue[S1] == 1 && SensorValue[S2] == 255) 
			{
				motor[motorA] = motor[motorC] = 0; 
				motor[motorD] = 25; 
				wait1Msec(3000); 
				motor[motorD] = -15; 
				wait1Msec(1000); 
				motor[motorD] = 0; 
				motor[motorA] = motor[motorC] = 75;
				duckCounter++;
			} 
			
			else if (SensorValue[S1] == 1 && SensorValue[S2]  < 255)
			{
				motor[motorA] = motor[motorC] = 0; 
				wait1Msec(3000);
				motor[motorA] = motor[motorC] = 75; 
			}
		}
	displayString(0,  “%d ducks “, duckCounter);
	}
}
/*Assumption: 
We are assuming that the ducks do not move around, but stay stationary during the entire duration so they are not double-counted.

If we encounter objects that are heavier and/or larger than the robot is capable of, then the object will not be able to be moved in the predicted time, therefore causing the robot to run into the object and fail to travel the entire field. 
*/
