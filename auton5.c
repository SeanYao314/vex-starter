void auton5() {
	shoot();
	wait1Msec(2900);
	stopGun();

	gyroTurnCounterClockwise(180);
	pause();

	chassisBackwards(127);
	wait1Msec(250);
	stopChassis();

	pause();
	intakeIn();
	forwardEncoderAdaptiveSpeed(18.5, 127, false);
	shoot();
	forwardEncoder(0.5, 127);
	pause();
	wait1Msec(2400);
	stopIntake();

	gyroTurnClockwise(175);
	pause();

	wait1Msec(1750);
	stopGun();

	pause();
	chassisBackwards(127);
	wait1Msec(750);
	stopall(100);
}