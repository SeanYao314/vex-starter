void auton1() {
	shoot();
	wait1msec(4000);
	stopGun();
	
	turn(90);

	chassisBackwards(50);
	wait1Msec(1500);
	turn(90);
	stopChassis();

	chassisForward(90);
	wait1Msec(800);
	stopChassis();

	wait1Msec(800);
	chassisBackwards(127);
	wait1Msec(3000);
	stopChassis();
}