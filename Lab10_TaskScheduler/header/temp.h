passChange, HSRelease, passChangeRelease


static unsigned char newPassSize = 0;
(button_H == 0x0F && button_S == 0x0F) ? passChange:
				

/*case passChange:
			if ( !(button_H == 0x0F && button_S == 0x0F) ) {
				if( newPassSize >= 4) {
					SIZE = newPassSize;
				}
				state = HSRelease;
			} else if (button_1 != 0x1F || button_2 != 0x1F
							|| button_3 != 0x1F || button_4 != 0x1F
							|| button_5 != 0x1F || button_6 != 0x1F
							|| button_7 != 0x1F || button_8 != 0x1F
							|| button_9 != 0x1F || button_A != 0x1F
							|| button_B != 0x1F || button_C != 0x1F
					 		|| button_D != 0x1F || button_0 != 0x1F
							|| button_S != 0x1F ) {
				if(newPassSize <=SIZE){
					if (button_1 == 0x01) {
						password[newPassSize] = button_1;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_2 == 0x02) {
						password[newPassSize] = button_2;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_3 == 0x03) {
						password[newPassSize] = button_3;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_4 == 0x04) {
						password[newPassSize] = button_4;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_5 == 0x05) {
						password[newPassSize] = button_5;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_6 == 0x06) {
						password[newPassSize] = button_6;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_7 == 0x07) {
						password[newPassSize] = button_7;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_8 == 0x08) {
						password[newPassSize] = button_8;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_9 == 0x09) {
						password[newPassSize] = button_9;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_A == 0x0A) {
						password[newPassSize] = button_A;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_B == 0x0B) {
						password[newPassSize] = button_B;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_C == 0x0C) {
						password[newPassSize] = button_C;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_D == 0x0D) {
						password[newPassSize] = button_D;
						++newPassSize;
						state = passChangeRelease;
					}
					else if (button_0 == 0x00) {
						password[newPassSize] = button_0;
						++newPassSize;
						state = passChangeRelease;
					}
					else {
						state = unlock;
					}
				}
				else {
					state = unlock;
				}	
			} 
			else {
				state = passChange;
			}		
			break;
		case HSRelease:
			state = !(button_H == 0x0F && button_S == 0x0E) ? HSRelease : unlock;
			break;
		case passChangeRelease:
			state = (button_0 == 0x1F &&
					button_1 == 0x1F &&
					button_2 == 0x1F &&
					button_3 == 0x1F &&
					button_4 == 0x1F &&
					button_5 == 0x1F &&
					button_6 == 0x1F &&
					button_7 == 0x1F &&
					button_8 == 0x1F &&
					button_9 == 0x1F &&
					button_A == 0x1F &&
					button_B == 0x1F &&
					button_C == 0x1F &&
					button_D == 0x1F &&
					button_S == 0x1F ) ? passChange :
			       	!(button_H == 0x0F && button_S == 0x0E) ? HSRelease : passChangeRelease;
			break;*/
