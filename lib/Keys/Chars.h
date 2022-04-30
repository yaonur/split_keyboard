#include <Arduino.h>
#include <Keyboard.h>
#include "Definitions.h"
#include "Globals.h"
class Chars
{
public:
	int Primary;
	int Alt1;
	int Alt2;
	bool isPressed = false;
	Chars(int primary, int alt1, int alt2);

	void process(int pin_num);
};

// tab and `


