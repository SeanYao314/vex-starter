void auton5() {
	forwardEncoder(1, 127);
	shoot();
	wait1Msec(2250);
	pause();
	stopGun();

	pause();

	intakeIn();
	forwardEncoder(14, 127);
	pause();
	forwardEncoder(1, 127);

	gyroTurnClockwise(15);

	pause();

	shoot();
	wait1Msec(2500);
	stopall(100);	
	// gyroTurnClockwise(180);
	// pause();

	// intakeIn();
	// forwardEncoder(14, 127);
	// stopGun();
	// pause();

	// forwardEncoder(1, 127);
	// wait1Msec(3000);

	// gyroTurnCounterClockwise(10);
	// pause();

	// shoot();
	// wait1Msec(2250);
	// stopGun();
	// pause

	// backwardEncoder(6, 127);
	// pause();

	// gyroTurnClockwise(90);
	// pause();

	// chassisBackwards(127);
	// wait1Msec(2000);
	// stopChassis();

	// chassisForward(127);
	// wait1Msec(3000);
	// stopall(100);
}