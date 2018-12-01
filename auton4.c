void auton4() {
	chassisForward(50);
	wait1Msec(750);
	turnCounterClock(90);
	stopChassis();

	chassisForward(127);
	wait1Msec(2250);
	stopChassis();
}