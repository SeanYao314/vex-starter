void auton6() {
	shoot();
	wait1Msec(2850);
	stopGun();

	intakeIn();
	forwardEncoderAdaptiveSpeed(18, 127, false);
	pause();
	forwardEncoder(1, 127);
	wait1Msec(1200);
	shoot();
	wait1Msec(1500);
	gyroTurnClockwise(3);
	stopGun();

	pause();
	chassisBackwards(127);
	wait1Msec(750);
	stopall(200);
}