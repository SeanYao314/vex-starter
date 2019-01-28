void autonSkills2() {
	shoot();
	wait1msec(3000);
	stopGun();

	turn(90);

	chassisBackwards(50);
	wait1Msec(1500);
	turnCounterClock(90);
	stopChassis();

	chassisForward(90);
	wait1Msec(800);
	stopChassis();

	wait1Msec(800);
	chassisBackwards(127);
	intakeIn();
	wait1Msec(4500);
	stopall(500);
}