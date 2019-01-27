void auton1() {
	clawDown();
	shoot();
	wait1Msec(2000);
	stopClaw();
	wait1Msec(500);
	stopGun();

	turn(55);

	chassisForward(100);
	wait1Msec(700);
	stopChassis();

	clawUp();
	wait1Msec(2000);
	stopChassis();
	stopClaw();

	chassisForward(127);
	wait1Msec(1500)
	turn(100);
	wait1Msec(500);
	chassisBackwards(127)
	wait1Msec(50)
	stopChassis();

	chassisBackwards(127);
	wait1Msec(3000);
	stopChassis();
}
	