void printDebug() {
	writeDebugStreamLine("Gyro => %d", getOrientation());
	writeDebugStreamLine("WheelEncoder => %d", getWheelEncoder());
	writeDebugStreamLine("petentiometer => %d", sensorValue[potentiometer])
	writeDebugStreamLine("------------------");
}
	