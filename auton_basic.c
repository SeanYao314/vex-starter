void stopChassis() {
	motor(LeftRear) = 0;
	motor(RightRear) = 0;
	motor(LeftFront) = 0;
	motor(RightFront) = 0;
	wait1Msec(100);
}

// void stopTower() {
// 	motor(towerUp) = 0;
// 	motor(towerDown) = 0;
// }
// void stopIntake() {
// 	motor(Intake) = 0;
// }

void stopClaw() {
	motor(Claw) = 0;
}

void stopGun() {
	motor(Gun) = 0;
}

void stopall(int time) {
	motor(LeftRear) = 0;
	motor(RightRear) = 0;
	motor(LeftFront) = 0;
	motor(RightFront) = 0;
	motor(towerUp) = 0;
	motor(towerDown) = 0;
	motor(Intake) = 0;
	motor(Claw) = 0;
	motor(Gun) = 0;
	wait1Msec(time);
}

void chassisForward(int speed) {
	motor(LeftRear) = speed;
	motor(RightRear) = speed;
	motor(LeftFront) = speed;
	motor(RightFront) = speed;
}

void chassisBackwards(int speed) {
	motor(LeftRear) = -speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = -speed;
}

void clawUp() {
	motor(Claw) = 80;
}

void clawDown() {
	motor(Claw) = -80;
}

void intakeIn() {
	motor(Intake) = 120;
}

void intakeFlip() {
	motor(Intake) = -120;
}

void shoot() {
	motor(Gun) = 127;
}

void turn(int degrees) {
	int speed = 50;
	int fullRotationTime = 4450;
	int time = fullRotationTime/360*degrees;
	motor(LeftRear) = speed;
	motor(RightRear) = -speed;
	motor(LeftFront) = speed;
	motor(RightFront) = -speed;
	wait1Msec(time);
	stopChassis();
}

void rotateSpeed(int speed) {
	motor(LeftRear) = -speed;
	motor(RightRear) = speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = speed;
}

void turnCounterClock(int degrees) {
	int speed = 50;
	int fullRotationTime = 4450;
	int time = fullRotationTime/360*degrees;
	motor(LeftRear) = -speed;
	motor(RightRear) = speed;
	motor(LeftFront) = -speed;
	motor(RightFront) = speed;
	wait1Msec(time);
	stopChassis();
}

void gyroTurnClockwise(int degrees) {
	writeDebugStreamLine("turning clockwise.");
	int currentSetting = SensorValue[Gyro];
	//writeDebugStreamLine("currentSetting => %d", currentSetting);
	int targetSetting = (currentSetting - 10* degrees) % 3600;
	//writeDebugStreamLine("targetSetting => %d", targetSetting);
	int delta = abs(targetSetting - SensorValue[Gyro]);

	while(true) {
		int newDelta = abs(targetSetting - SensorValue[Gyro]);

		if (newDelta <= delta) {
			rotateSpeed(-50);
			delta = newDelta;
			wait1Msec(10);
		} else {
			rotateSpeed(0);
			writeDebugStreamLine("stop turning");
			break;
		}
	}
}

void gyroTurnCounterClockwise(int degrees) {
	writeDebugStreamLine("turning counter clockwise.");
	int currentSetting = SensorValue[Gyro];
	//writeDebugStreamLine("currentSetting => %d", currentSetting);
	int targetSetting = (currentSetting + 10* degrees) % 3600;
	//writeDebugStreamLine("targetSetting => %d", targetSetting);

	int delta = abs(targetSetting - SensorValue[Gyro]);
	while (true) {
		int newDelta = abs(targetSetting - SensorValue[Gyro]);

		if (newDelta <= delta) {
			rotateSpeed(50);
			delta = newDelta;
			wait1Msec(10);
		} else {
			rotateSpeed(0);
			writeDebugStreamLine("stop turning");
			break;
		}
	}
}

int adaptiveSpeed(int speed, int matDistance) {
	if (matDistance < 5) {
		return 20;
	} else if (matDistance < 3) {
		return 10;
	}

	return speed;
}

void forwardEncoder(int matDistance, int speed) {
	writeDebugStreamLine("move forward for %d mat distance.", matDistance);
	resetWheelEncoder();
	const int matEncoderRatio = 112;
	int currentSetting = getWheelEncoder();
	int targetSetting = matDistance * matEncoderRatio;
	writeDebugStreamLine("currentSetting = %d, targetSetting = %d", currentSetting, targetSetting);

	int delta = abs(targetSetting - getWheelEncoder());
	while (true) {
		int newDelta = abs(targetSetting - getWheelEncoder());

		if (newDelta <= delta) {
			writeDebugStreamLine("delta = %d, newDelta = %d", delta, newDelta);
			chassisForward(adaptiveSpeed(speed, newDelta / matEncoderRatio));
			delta = newDelta;
			wait1Msec(10);
		} else {
			writeDebugStreamLine("delta = %d, newDelta = %d, stopping the chassis.", delta, newDelta);
			writeDebugStreamLine("final encoder value is %d before stopping.", getWheelEncoder());
			stopChassis();
			break;
		}
	}
}

void backwardEncoder(int matDistance, int speed) {
	writeDebugStreamLine("move backwards for %d mat distance.", matDistance);
	resetWheelEncoder();
	const int matEncoderRatio = -112;
	int currentSetting = getWheelEncoder();
	int targetSetting = matDistance * matEncoderRatio;
	writeDebugStreamLine("currentSetting = %d, targetSetting = %d", currentSetting, targetSetting);

	int delta = abs(targetSetting - getWheelEncoder());
	while (true) {
		int newDelta = abs(targetSetting - getWheelEncoder());

		if (newDelta <= delta) {
			writeDebugStreamLine("delta = %d, newDelta = %d", delta, newDelta);
			chassisBackwards(adaptiveSpeed(speed, abs(newDelta / matEncoderRatio));
			delta = newDelta;
			wait1Msec(10);
		} else {
			writeDebugStreamLine("delta = %d, newDelta = %d, stopping the chassis.", delta, newDelta);
			writeDebugStreamLine("final encoder value is %d before stopping.", getWheelEncoder());
			stopChassis();
			break;
		}
	}
}

