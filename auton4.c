void auton4() {
	chassisBackwards(50);
	wait1Msec(1500);
	turnCounterClock(90);
	stopChassis();

	chassisForward(90);
	wait1Msec(800);
	stopChassis();

	wait1Msec(800);
	chassisBackwards(127);
	wait1Msec(3000);
	stopChassis();
}