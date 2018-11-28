void stopChassis(int time) {
	Motor(leftRear) = 0;
	Motor(rightRear) = 0;
	Motor(leftFront) = 0;
	Motor(rightFront) = 0;
	wait1msec(time);
}
void stopTower(int time) {
	Motor(towerUp) = 0;
	Motor(towerdown) = 0;
	wait1msec(time);
}
void stopIntake(int time) {
	Motor(Intake) = 0;
	wait1msec(time);
}
void stopClaw(int time) {
	Motor(Claw) = 0;
	wait1msec(time);
}
void stopGun(int time) {
	Motor(Gun) = 0;
	wait1msec(time);
}
void stopall(int time) {
	Motor(leftRear) = 0;
	Motor(rightRear) = 0;
	Motor(leftFront) = 0;
	Motor(rightFront) = 0;
	Motor(towerUp) = 0;
	Motor(towerDown) = 0;
	Motor(Intake) = 0;
	Motor(Claw) = 0;
	Motor(Gun) = 0;
	wait1msec(time);
}
void chassisForward(int time, int speed) {
	Motor(leftRear) = speed;
	Motor(rightRear) = speed;
	Motor(leftFront) = speed;
	Motor(rightFront) = speed;
	wait1msec(time);
}
void chassisBackward(int time, int speed) {
	Motor(leftRear) = -speed;
	Motor(rightRear) = -speed;
	Motor(leftFront) = -speed;
	Motor(rightFront) = -speed;
	wait1msec(time);
}
void chassisRight(int time, int speed) {
	Motor(leftRear) = speed;
	Motor(rightRear) = -speed;
	Motor(leftFront) = speed;
	Motor(rightFront) = -speed;
	wait1msec(time);
}
void chassisLeft(int time, int speed) {
	Motor(leftRear) = -speed;
	Motor(rightRear) = speed;
	Motor(leftFront) = -speed;
	Motor(rightFront) = speed;
	wait1msec(time);
}
void TowerUp(int time, int speed) {
	Motor(towerUp) = speed;
	Motor(towerDown) = speed;
	wait1msec(time);
}
void TowerDown(int time, int speed) {
	Motor(towerUp) = -speed;
	Motor(towerDown) = -speed;
	wait1msec(time);
}
void clawUp
