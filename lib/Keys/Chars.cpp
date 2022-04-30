#include "Chars.h"

Chars::Chars(int primary, int alt1 = 0, int alt2 = 0)
{
	Primary = primary;
	Alt1 = alt1;
	Alt2 = alt2;
}

void Chars::process(int pin_num)
{
	if (digitalRead(pin_num) == LOW && isPressed == false)
	{
		isPressed = true;
		debugln("key is down ");
		if (alt_one_status && !Alt1 == 0)
		{
			Keyboard.write(Alt1);
		}
		else if (alt_two_status && !Alt2 == 0)
		{
			Keyboard.write(Alt2);
		}
		else
		{
			debug("writing primary:");
			debugln(Primary);
			debugln("alt_one and alt_two status");
			debug(alt_one_status);
			debug("::::::");
			debugln(alt_two_status);
			Keyboard.write(Primary);
		}
	}
	else if (digitalRead(pin_num) == HIGH && isPressed == true)
	{
		isPressed = false;
		debugln("key is up");
	}
}
