
int clawspeed = 75;

task claw() {
	while (true) {
		if(VexRt(Btn5U) == 1) {
			Motor(claw) = clawspeed;
		} else {
			Motor(claw) = 0;
		}

		if (VexRt(Btn5D) == 1) {
			Motor(claw) = -clawspeed;
		} else {
			Motor(claw) = 0;
		}
	}
}
