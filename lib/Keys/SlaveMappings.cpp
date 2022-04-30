class SlaveMappings
{
public:
	int Alt1;
	int Alt2;
	bool isPressed = false;
	SlaveMappings(int alt1 = 0, int alt2 = 0);

	int process(int char_num, bool alt_one_status, bool alt_two_status);
};

int SlaveMappings::process(int char_num, bool alt_one_status, bool alt_two_status)
{
	if (Alt1 && alt_one_status)
	{
		return Alt1;
	}
	else if (Alt2 && alt_two_status)
	{
		return Alt2;
	}
	else
	{
		return char_num;
	}
}
SlaveMappings::SlaveMappings(int alt1, int alt2)
{
	Alt1 = alt1;
	Alt2 = alt2;
}

SlaveMappings s91(8, 204);//[ back space f11
SlaveMappings s112(48, 203);//p 0 f10
SlaveMappings s111(57, 202);//o 9 f9
SlaveMappings s105(56, 201);//i 8 f8
SlaveMappings s117(55, 200);//u 7 f7
SlaveMappings s121(54, 199);//y 6 f6

SlaveMappings s39(95);// ' _
SlaveMappings s59(126, 49);//; ~ 1 
SlaveMappings s108(215, 213);//l right end
SlaveMappings s107(218, 211);//k up page_up
SlaveMappings s106(217, 214);//j down page_down
SlaveMappings s104(216, 210);//h left home

SlaveMappings s93(212);//] delete
SlaveMappings s47(61,50);/// = % 2 
SlaveMappings s46(37);// .
SlaveMappings s44(42);// ,
SlaveMappings s109(43);//m
SlaveMappings s110(45);//n
SlaveMappings s176();

int process_slave(int char_num, bool alt_one_status, bool alt_two_status)
{
	if (char_num == 91)
		return s91.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 112)
		return s112.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 111)
		return s111.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 105)
		return s105.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 117)
		return s117.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 121)
		return s121.process(char_num, alt_one_status, alt_two_status);
	//
	else if (char_num == 39)
		return s39.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 59)
		return s59.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 108)
		return s108.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 107)
		return s107.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 106)
		return s106.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 104)
		return s104.process(char_num, alt_one_status, alt_two_status);
	//
	else if (char_num == 93)
		return s93.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 47)
		return s47.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 46)
		return s46.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 44)
		return s44.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 109)
		return s109.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 110)
		return s110.process(char_num, alt_one_status, alt_two_status);
	else if (char_num == 176)
		return s91.process(char_num, alt_one_status, alt_two_status);
	else
		return 169;
}