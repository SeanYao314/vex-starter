void auton6() {
	// forwardEncoder(1, 127);
	// shoot();
	// wait1Msec(2250);
	// pause();

	// intakeIn();
	// forwardEncoderAdaptiveSpeed(8, 127, false);
	// stopGun();
	// forwardEncoder(8, 127);
	// pause();

	// forwardEncoder(1, 127);
	// wait1Msec(1200);

	// backwardEncoder(3, 127);

	// gyroTurnClockwise(4);
	// pause();

	// shoot();
	// wait1Msec(3500);
	// stopGun();
	// pause();

	// gyroTurnCounterClockwise(4);
	// pause();

	// backwardEncoder(1, 127);
	// pause();

	// gyroTurnCounterClockwise(90);
	// pause();

	// chassisBackwards(127);
	// wait1Msec(1500);
	// stopChassis();

	// chassisForward(127);
	// wait1Msec(3200);
	// stopall(100);

	gyroTurnCounterClockwise(47);
	pause();

	shoot();
	wait1Msec(2400);

	stopall(100);
}