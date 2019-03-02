void auton8() {
	pause();

	shoot();
	wait1msec(2900);
	stopGun();

	gyroTurnCounterClockwise(90);
	pause();

	forwardEncoder(10.5, 127);
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