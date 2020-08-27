#ifndef LOCKSM_H
#define LOCKSM_H
//timer #define s
const unsigned long LOCKSM_PERIOD = 100;

//Global Variables
unsigned char bolt = 0;
//Enumeration
typedef enum LockStates {LockSM_start, lock, hashReleaseUnlock, waitUnlock, waitReleaseUnlock , buttonInUnlock,
					unlock, hashReleaseLock, waitLock, waitReleaseLock, buttonInLock,
					} LockState;

//Tick Function
//Change the name of the function according to assignment

int LockSM(int state) {
	// Get input (HAL)
	unsigned char buttonIn = ~PINB & 0x80;
	//Variables
	static unsigned char SIZE = 5;
	static unsigned char countPass = 0;
	static unsigned char password[5] = {0x01,0x02,0x03,0x04,0x05};	
	//State switches
	//Computation
	switch (state) {
		case LockSM_start:
			state = lock;
			break;
		case lock:
			state = (button_H == 0x0F ) ? hashReleaseUnlock :
			       	(buttonIn)? buttonInUnlock : lock;
			break;
		case hashReleaseUnlock:
			state = (button_H == 0x0F ) ? hashReleaseUnlock : waitUnlock;
			break;
		case waitUnlock:
			if ( buttonIn ) {
				state = buttonInUnlock;
			}
			else if (button_1 != 0x1F || button_2 != 0x1F
							|| button_3 != 0x1F || button_4 != 0x1F
							|| button_5 != 0x1F || button_6 != 0x1F
							|| button_7 != 0x1F || button_8 != 0x1F
							|| button_9 != 0x1F || button_A != 0x1F
							|| button_B != 0x1F || button_C != 0x1F
					 		|| button_D != 0x1F || button_0 != 0x1F
							|| button_S != 0x1F ) {
				if(countPass<SIZE) {
					if(password[countPass] == button_1) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
			 		else if(password[countPass] == button_2) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_3) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_4) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_5) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_6) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_7) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_8) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_9) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_A) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_B) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_C) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_D) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}	
					else if(password[countPass] == button_0) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_S) {
					        if(countPass == (SIZE - 1)){
							state = unlock;
						} 
						else {
							state = waitReleaseUnlock;
						}
						countPass = countPass + 1;
					}	
					else {
						state = lock;
					}		
				}
				else {
					state = lock;
				}
			}
			else if (button_H == 0x0F) {
				state = hashReleaseUnlock;
			}
			else {
				state = waitUnlock;
			}
	 		break;
		case waitReleaseUnlock:
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
					button_S == 0x1F ) ? waitUnlock : waitReleaseUnlock;
			break;	
		case buttonInUnlock:
			state = (buttonIn) ? buttonInUnlock : unlock;
			break;
		case unlock:
			state =(buttonIn) ? buttonInLock :
			       	(button_H == 0x0F) ? hashReleaseLock : unlock;
			break;	
		case hashReleaseLock:
			state = (button_H == 0x0F ) ? hashReleaseLock : waitLock;
			break;		
		case waitLock:
			if ( buttonIn ) {
				state = buttonInLock;
			}
			else if (button_1 != 0x1F || button_2 != 0x1F
							|| button_3 != 0x1F || button_4 != 0x1F
							|| button_5 != 0x1F || button_6 != 0x1F
							|| button_7 != 0x1F || button_8 != 0x1F
							|| button_9 != 0x1F || button_A != 0x1F
							|| button_B != 0x1F || button_C != 0x1F
					 		|| button_D != 0x1F || button_0 != 0x1F
							|| button_S != 0x1F ) {
				if(countPass<SIZE) {
					if(password[countPass] == button_1) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_2) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_3) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_4) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}		
					else if(password[countPass] == button_5) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_6) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_7) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_8) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_9) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_A) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_B) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_C) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_D) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_0) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else if(password[countPass] == button_S) {
					        if(countPass == SIZE-1){
							state = lock;
						} 
						else {
							state = waitReleaseLock;
						}
						countPass = countPass + 1;
					}
					else {
						state = unlock;
					}		
				}
				else {
					state = unlock;
				}
			}
			else if (button_H == 0x0F) {
				state = hashReleaseLock;
			}
			else {
				state = waitLock;
			}
			break;
		case waitReleaseLock:
			state =  (button_0 == 0x1F &&
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
					button_S == 0x1F ) ? waitLock : waitReleaseLock;
			break;
		case buttonInLock:
			state = (buttonIn) ? buttonInLock : lock;
			break;
		default:
			state = LockSM_start;
			break;	}
	//Action
	//lock, hashReleaseUnlock, waitUnlock, waitReleaseUnlock , buttonInUnlock,
	//				unlock, hashReleaseLock, waitLock, waitReleaseLock, buttonInLock,
	//				passChange, HSRelease, passChangeRelease	
	switch (state) {
		case LockSM_start:
			break;
		case lock:
			countPass = 0;
			bolt = 0;
			break;
		case hashReleaseUnlock:
			countPass = 0;
			break;
		case waitUnlock:
			break;
		case waitReleaseUnlock:
			break;
		case buttonInUnlock:
			break;
		case unlock:
			countPass = 0;
			bolt = 1;
			break;
		case hashReleaseLock:
			countPass = 0;
			break;
		case waitLock:
			break;
		case waitReleaseLock:
			break;
		case buttonInLock:
			break;
	}
	// Output (HAL)

	//PORTD = state;
	
	return state;
}
#endif
