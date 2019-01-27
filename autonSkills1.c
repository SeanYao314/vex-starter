void autonSkills1() {
	//shoot
	shoot();
	wait1Msec(3000);
	stopGun();

	turnCounterClock(90);

	//push flag
	chassisBackwards(127);
	wait1Msec(2500);
	stopChassis();

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

	chassisForward(127);
	wait1Msec(4000);
	stopChassis();

	turn(90);

	chassisForward(100);
	wait1Msec(500);
	stopChassis();

	chassisBackwards(127)
	wait1Msec(5000);
	stopall(500);
}