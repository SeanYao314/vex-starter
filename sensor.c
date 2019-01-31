int get_auton_mode() {
	int potentiometer = SensorValue[AutonSelector];
	int mode = potentiometer;
	return mode;
}

void resetGyroSensor() {
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[Gyro] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Analog Port 8 as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[Gyro] = sensorGyro;
	wait1Msec(2000);
	//SensorFullCount[Gyro] = 00;
}

int getOrientation() {
	return SensorValue[Gyro];
}

int getWheelEncoder() {
	return SensorValue[WheelEncoder];
}

void resetWheelEncoder() {
	SensorValue[WheelEncoder] = 0;
}

int getPotentiometer() {
	return SensorValue[potentiometer];
}