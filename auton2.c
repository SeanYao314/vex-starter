void auton2() {
	forwardEncoder(1, 1);
	pause();
	//shoot
	shoot();
	wait1msec(2500);
	stopGun();
	pause();

	gyroTurnClockwise(90);

	forwardEncoder(11, 127);
	wait1Msec(100);
	gyroTurnCounterClockwise(90);
	stopChassis();

	chassisBackwards(90);
	wait1Msec(800);
	stopChassis();

	wait1Msec(800);
	chassisForward(127);
	wait1Msec(3000);
	stopChassis();
}
