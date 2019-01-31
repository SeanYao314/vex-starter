void auton3() {
	//shoot
	shoot();
	wait1Msec(2250);
	stopGun();

	forwardEncoder(1, 127);
	gyroTurnCounterClockwise(90);
	wait1Msec(100);

	//push flag
	intakeIn();
	forwardEncoder(20, 127);
	stopall(200);

	// chassisForward(75);
	// wait1Msec(1000);
	// stopChassis();

	// turnCounterClock(45);
	// clawDown();
	// wait1Msec(2000);
	// stopClaw();

	// chassisForward(50);
	// wait1Msec(500);
	// stopChassis();
	// clawUp(1000);
	// wait1Msec(3000);

	// chassisBackwards(50);
	// wait1Msec(500);

	// turnCounterClock(45);

	backwardEncoder(32, 127);
	pause();

	gyroTurnCounterClockwise(90);

	chassisBackwards(127);
	wait1Msec(250);
	stopChassis();

	chassisBackwards(127)
	intakeIn();
	wait1Msec(3000);
	stopall(500);
}
	