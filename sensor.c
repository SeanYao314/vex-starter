int get_auton_mode() {
	int potentiometer = SensorValue[AutonSelector];
	int mode = potentiometer / 585;
	return mode;
}