//Timer #define s

//Enumeration
typedef enum ThreeLEDStates {initLEDs, LEDone, LEDtwo, LEDthree } ThreeLEDStates;

//Gloval Variables
unsigned char threeLEDs = 0x00;


//Tick Function
//Change the name of the function according to assignment
int ThreeLEDsSM(int state) {
	// Get input (HAL)
	
	//Variables
	const unsigned char ledOne = 0x01;
	const unsigned char ledTwo = 0x02;
	const unsigned char ledThree = 0x04;

	//State switches
	//Computation
	switch (state) {
		case initLEDs:
			state = LEDone;
			break;
		case LEDone:
			state = LEDtwo;
			break;
		case LEDtwo:
			state = LEDthree;
			break;
		case LEDthree:
			state = LEDone;
			break;
		default:
			state = initLEDs;
			break;
	}
	//Action
	switch (state) {
		case initLEDs:
			break;
		case LEDone:
			threeLEDs = ledOne;
			break;
		case LEDtwo:
			threeLEDs = ledTwo;
			break;
		case LEDthree:
			threeLEDs = ledThree;
			break;
	}

	// Output (HAL)
	
	return state;
}
