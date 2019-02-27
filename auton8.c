void auton8() {
	forwardEncoder(1, 1);
	pause();

	shoot();
	wait1msec(2250);

	gyroTurnCounterClockwise(90);
	pause();

	forwardEncoder(9.5, 127);
	pause();

	gyroTurnClockwise(90);
	pause();

	chassisBackwards(127);
	wait1msec(900);
	stopChassis();
	pause();

	chassisForward(127);
	wait1msec(3000);
	stopChassis();
}