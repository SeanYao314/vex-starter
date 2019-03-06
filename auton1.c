void auton1() {
	pause();
	shoot();
	wait1Msec(2750);
	stopGun();
	pause();

	GyroTurnClockwise(90);

	forwardEncoder(11.5, 127);
	pause();

	GyroTurnClockwise(90);
	pause();

	chassisBackwards(127);
	wait1Msec(900);
	stopChassis();
	pause();

	chassisForward(127);
	wait1Msec(3000);
	stopChassis();
}
