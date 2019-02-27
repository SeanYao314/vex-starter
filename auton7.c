void auton7() {
	backwardEncoder(1, 1);
	pause();
	shoot();
	wait1Msec(2250);
	pause();
	stopGun();

	gyroTurnCounterClockwise(90);
	pause();

	forwardEncoder(6.5, 127);
	pause();

	gyroTurnCounterClockwise(90);

	chassisBackwards(100);
	wait1Msec(900);
	stopChassis();

	pause();

	chassisForward(127);
	wait1Msec(3000);
	stopChassis();


}