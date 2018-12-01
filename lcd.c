
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;

int _get_lcd_input() {
	//wait for press
	while(nLCDButtons == 0) {
		wait1Msec(5);
	}

	while(nLCDButtons != 0) {
		wait1Msec(5);
	}

	return nLCDButtons;
}

task lcd_control() {
	bLCDBacklight = true;                                    // Turn on LCD Backlight
	string mainBattery, backupBattery;

	int screen_position = 0;
 
	while (true) {

		clearLCDLine(0);
		clearLCDLine(1);
		 
		if (screen_position == 0) {
			//Display the Primary Robot battery voltage
			displayLCDString(0, 0, "Primary: ");
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
			displayNextLCDString(mainBattery);
			 
			//Display the Backup battery voltage
			displayLCDString(1, 0, "Backup: ");
			sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
			displayNextLCDString(backupBattery);
		} else if (screen_position == 1) {
			int mode = get_auton_mode();
			if (mode == 0) {
				displayLCDString(0, 0, "Autonamous Off");
			} else if (mode == 1) {
				displayLCDString(0, 0, "Autonamous Blue 1");
			} else if (mode == 2) {
				displayLCDString(0, 0, "Autonamous Red 1");
			} else if (mode == 3) {
				displayLCDString(0, 0, "Autonamous Blue 2");
			} else if (mode == 4) {
				displayLCDString(0, 0, "Autonamous Red 2");
			} else if (mode == 5) {
				displayLCDString(0, 0, "Autonamous Blue Skill");
			} else if (mode == 6) {
				displayLCDString(0, 0, "Autonamous Red Skill");
			}
		}
		 
		//Short delay for the LCD refresh rate
		wait1Msec(100);

		int lcd_input = _get_lcd_input();

		if (lcd_input == leftButton && screen_position > 0) {
			--screen_position;
		} else if (lcd_input == rightButton && screen_position < 1) {
			++screen_position;
		}
	}
}