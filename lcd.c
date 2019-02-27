
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int _auton_selector = 0;

int _get_bumper_button() {
	return SensorValue[AutonSelector];
}

int _get_lcd_input() {

	bool buttonPressed = false;
	//wait for press
	while(_get_bumper_button() == 1) {
		wait1Msec(5);
		buttonPressed = true;
	}

	if (buttonPressed) {
		_auton_selector++;
	}

	return _auton_selector % 11;
}

task lcd_control() {
	bLCDBacklight = true;                                    // Turn on LCD Backlight
	string mainBattery, backupBattery;

	int screen_position = 0;
 
	while (true) {

		clearLCDLine(0);
		clearLCDLine(1);
		 
		//if (screen_position == 0) {
			//Display the Primary Robot battery voltage
			displayLCDString(0, 0, "Primary: ");
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.00,'V'); //Build the value to be displayed
			displayNextLCDString(mainBattery);
			 
			// //Display the Backup battery voltage
			// displayLCDString(1, 0, "Backup: ");
			// sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
			// displayNextLCDString(backupBattery);
		//} else if (screen_position == 1) {
			int mode = _get_lcd_input();
			if (mode == 0) {
				displayLCDString(1, 0, "Auton Off");
			} else if (mode == 1) {
				displayLCDString(1, 0, "Blue 5pts");
			} else if (mode == 2) {
				displayLCDString(1, 0, "Red 5pts");
			} else if (mode == 3) {
				displayLCDString(1, 0, "Blue 6pts");
			} else if (mode == 4) {
				displayLCDString(1, 0, "Red 6pts");
			} else if(mode == 5){
				displayLCDString(1, 0, "Blue 8pts");
			} else if(mode == 6) {
				displayLCDString(1, 0, "Red 8pts");
			} else if (mode == 7) {
				displayLCDString(1, 0, "Blue 5pts Back");
			} else if (mode == 8) {
				displayLCDString(1, 0, "Red 5pts Back");
			} else if (mode == 9) {
				displayLCDString(1, 0, "Skills 11pt");
			} else if (mode == 10) {
				displayLCDString(1, 0, "SKills 8pts");
			} else {
				displayLCDString(1, 0, "Unknown");
			}
		//}
		 
		//Short delay for the LCD refresh rate
		wait1Msec(100);

		// int lcd_input = _get_lcd_input();

		// if (lcd_input == leftButton) {
		// 	screen_position = abs(screen_position + 1) % 2;
		// }
	}
}