//#defines 
#define on 0x01
#define off 0x00

//Timing
unsigned char out = 0x00;
//Enumeration
typedef enum States {start, release, press } OnOffStates;



//Tick Function
//Change the name of the function according to assignment
int onOffTick(int state) {
	// Get input (HAL)
	unsigned char button = ~PINA & 0x01;
	//Variables
	
	//State switches
	//Computation
	switch (state) {
		case start:
			state = release;
			break;
		case release:
			state = (button) ? press : release;
			break;
		case press:
			if(button) {
				state = press;
			} 
			else {
				state = release;
				out = (out == on) ? off : on;
			}
			break;
		default:
			state = start;
			break;

	}
	//Action
	switch (state) {
		case start:
			break;
		case release:
			break;
		case press:
			break;
	}

	// Output (HAL)
	return state;
}
