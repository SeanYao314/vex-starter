void auton4() {
	chassisForward(127);
	wait1Msec(2500);
	stopChassis();
	pause();

	backwardEncoderAdaptiveSpeed(7, 127, false);
	shoot();
	backwardEncoder(16, 127);
	pause();

	gyroTurnClockwise(90);
	wait1Msec(1500);
	stopGun();

	chassisBackwards(127);
	wait1Msec(750);

	intakeIn();
	forwardEncoderAdaptiveSpeed(14, 127, false);
	shoot();
	forwardEncoder(5, 127);
	wait1Msec(2400);
	stopIntake();
	wait1Msec(1750);
	stopGun();
	pause();

	chassisBackwards(127);
	wait1Msec(750)

	stopall(200);
}
