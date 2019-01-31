void auton1() {
	shoot();
	wait1Msec(2500);
	stopGun();
	pause();

	GyroTurnClockwise(90);

	forwardEncoder(12, 127);
	pause();

	GyroTurnClockwise(90);
	pause();

	chassisBackwards(127);
	wait1Msec(1000);
	stopChassis();
	pause();

	chassisForward(127);
	wait1Msec(3000);
	stopChassis();
}
