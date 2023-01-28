#pragma once
#include "Standard.h"


namespace lathe
{

	// MISC Codes:
	void N(unsigned _num);
	void T(unsigned _tool, int offset = -1, bool newLine = true); // default will offset will be same as tool number if not provided (-1)
	void IF(unsigned varNum, Num compVal, CMP cmp = EQ);
	void GOTO(unsigned numBlock);
	void WHILE(unsigned varNum, Num compVal, unsigned index, CMP cmp = EQ);
	void END(unsigned index);
	void HASH(unsigned _num, Num value = 0.);
	void VAR(unsigned _num, Num value = 0.);

	//Lathe M-Codes;
	//Documentation: https://www.haascnc.com/service/service-content/guide-procedures/lathe---m-codes.html
	void M00();
	void M01();
	void M02();
	void M03();
	void M04();
	void M05();
	void M08(Num pressure = NONE);
	void M09();
	void M10();
	void M11();
	void M12(unsigned rpm, unsigned msTime);
	void M13();
	void M14();
	void M15();
	void M17();
	void M18();
	void M19(Num r);
	void M21();
	void M22();
	void M23();
	void M24();
	void M30();
	void M31();
	void M33();
	void M35();
	void M36();
	void M37();
	void M38();
	void M39();
	void M41();
	void M42();
	void M43();
	void M44();
	void M51();
	void M52();
	void M53();
	void M54();
	void M55();
	void M56();
	void M59(unsigned relayBank);
	void M61();
	void M62();
	void M63();
	void M64();
	void M65();
	void M66();
	void M69(unsigned relayBank);
	void M78();
	void M79();
	void M85();
	void M86();
	void M88();
	void M89();
	void M90();
	void M91();
	void M95();
	void M96(unsigned lineNum, unsigned varNum);
	void M97(unsigned lineNum, unsigned times = 1);
	void M98(unsigned progNum, unsigned times = 1);
	void M98(std::string progPath, unsigned times = 1);
	void M99();
	void M104();
	void M105();
	void M109(unsigned varNum);
	void M110();
	void M111();
	void M112(unsigned rpm, unsigned msTime);
	void M113();
	void M114();
	void M115();
	void M119(Num r);
	void M121();
	void M122();
	void M123();
	void M124();
	void M125();
	void M126();
	void M129(unsigned relayBank);
	void M130(std::string file);
	void M131();
	void M133(unsigned rpm);
	void M134(unsigned rpm);
	void M135();
	void M138(Num amt, Num rate = NONE);
	void M139();
	void M143(unsigned rpm);
	void M144(unsigned rpm);
	void M145();
	void M146();
	void M147();
	void M158();
	void M159();
	void M170();
	void M171();
	void M214();
	void M215();
	void M219(Num r);
	void M299();
	void M300(unsigned progNum, bool reverse = false);
	void M334(unsigned amt);
	void M335(unsigned amt);
	void M373();
	void M374();
	void M388();
	void M389();
}