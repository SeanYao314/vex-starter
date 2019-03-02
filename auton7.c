void auton7() {
	backwardEncoder(1, 1);
	pause();
	shoot();
	wait1Msec(2900);
	pause();
	stopGun();

	gyroTurnCounterClockwise(90);
	pause();

	forwardEncoder(7.8, 127);
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