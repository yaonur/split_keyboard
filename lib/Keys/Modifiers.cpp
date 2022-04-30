
#include "Modifiers.h"



Modifiers::Modifiers(int primary)
{
	Primary = primary;
}

void Modifiers::process(int pin_num)
{
	if (digitalRead(pin_num) == LOW && isPressed == false)
	{
		isPressed = true;
		Keyboard.press(Primary);
	}
	else if (digitalRead(pin_num) == HIGH && isPressed == true)
	{
		isPressed = false;
		Keyboard.release(Primary);
	}
}

FnKeys::FnKeys(bool &alt_key)
{
	Alt_key = alt_key;
}


