int clawThreshold = 20;
int clawspeed = 0;

task claw1_control() {
	while (true) {
		if(abs(vexRt(Ch3Xmtr2)) > clawThreshold) {
			motor(claw) = vexRt(Ch3Xmtr2)
		} else if(abs(vexRt(Btn7UXmtr2)) == 1) {
			motor(claw) = clawspeed;
			if(getPotentiometer() < 2000) {
				clawspeed += 3;
			} else if(getPotentiometer() > 2000) {
				clawspeed -= 2;
				if(clawspeed < 15) {
					clawspeed += 2;
				}
			} else if(getPotentiometer() > 2200 && getPotentiometer() < 2300) {
				motor(claw) = 0;
			}

		} else {
			motor(claw) = 0;
		}
		wait1msec(100);
	}
}
