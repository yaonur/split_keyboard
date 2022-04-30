#include "Modifiers.cpp"
#include "Chars.cpp"
#include "SlaveMappings.cpp"
int key_recieved;
bool isPressedMaster=false;

void process_master_fn_key(int pin_num)
{
	if (digitalRead(pin_num) == LOW && isPressedMaster == false)
	{
		// debugln(alt_one_status);
		isPressedMaster = true;

		alt_one_status = true;
	}
	else if (digitalRead(pin_num) == HIGH && isPressedMaster == true)
	{
		// debugln(alt_one_status);
		isPressedMaster = false;
		alt_one_status = false;
	}
}
void process_serial()
{
	key_recieved = Serial1.read();
	if (key_recieved == 254)
	{
		alt_two_status = true;
	}
	else if (key_recieved == 255)
	{
		alt_two_status = false;
	}
	else if (key_recieved == 134)
	{
		Keyboard.press(134);
	}
	else if (key_recieved == 130)
	{
		Keyboard.release(134);
	}
	else if (key_recieved == 129)
	{
		Keyboard.press(129);
	}
	else if (key_recieved == 133)
	{
		Keyboard.release(129);
	}
	else
	{

		if (!alt_one_status && !alt_two_status)
		{
			Keyboard.write(key_recieved);
		}
		else
		{

			Keyboard.write(process_slave(key_recieved, alt_one_status, alt_two_status));
		}
	}
}

	Chars r1c1(179, 96, 205);//tab ` f12
	Chars r1c2(113, 49,194); // q and 1 fq1	Chars r1c3(119, 50,195); // w and 2
	Chars r1c3(119, 50,195); // q and 1 f2	Chars r1c3(119, 50,195); // w and 2
	Chars r1c4(101, 51,196); // e and 3 f3
	Chars r1c5(114, 52,197); // r and 4 f4
	Chars r1c6(116, 53,198); // t and 5 f5

	Chars r2c1(177, 126); // esc and ~
	Chars r2c2(97, 92);	  // a and
	Chars r2c3(115, 124); // s and |
	Chars r2c4(100, 40);  // d and (
	Chars r2c5(102, 41);  // f and )
	Chars r2c6(103, 38);  // g and &

	Modifiers r3c1(131); // key left gui
	Chars r3c2(122, 33); // z and !
	Chars r3c3(120, 64); // x and @
	Chars r3c4(115, 35); // c and#
	Chars r3c5(100, 36); // v and $
	Chars r3c6(102, 94); // b and ^

	Modifiers r4c3(132); // right ctrl
	Modifiers r4c4(129); // shift
	FnKeys r4c5(alt_one_status);
	Chars r4c6(32); // space
