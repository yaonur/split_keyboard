#include <Arduino.h>
#include <Keyboard.h>
#include "Definitions.h"
// #include "Globals.h"
class Modifiers
{
public:
	int Primary;
	bool isPressed = false;
	Modifiers(int primary);
	void process(int pin_number);
};

class FnKeys
{
public:
	bool isPressed = false;
	bool Alt_key;
	FnKeys(bool &alt_key);
	void process(int pin_number);
};