#include "Pch.h"
#include "Lathe.h"
#include "LatheCore.h"
#include "Compiler.h"

void lathe::NumBlock(unsigned _num)
{
	N(_num);
}

void lathe::Tool(unsigned _tool, int offset, bool newLine)
{
	T(_tool, offset, newLine);
}

void lathe::If(unsigned varNum, Num compVal, CMP cmp)
{
	IF(varNum, compVal, cmp);
}

void lathe::GoTo(unsigned numBlock)
{
	GOTO(numBlock);
}

void lathe::While(unsigned varNum, Num compVal, unsigned index, CMP cmp)
{
	WHILE(varNum, compVal, index, cmp);
}

void lathe::EndWhile(unsigned index)
{
	END(index);
}

void lathe::Var(unsigned _num, Num value)
{
	HASH(_num, value);
}

void lathe::BlockDelete()
{
	Compiler::Print("/");
}

void lathe::Stop()
{
	M00();
}

void lathe::OptionalStop()
{
	M01();
}

void lathe::End()
{
	M02();
}

void lathe::SetSpindleFwrd()
{
	M03();
}

void lathe::SetSpindleRev()
{
	M04();
}

void lathe::SpindleStop()
{
	M05();
}

void lathe::SetCoolant(bool isOn, Num pressure)
{
	if (isOn)
		M08(pressure);
	else
		M09();
}

void lathe::SetChuckClamp(bool isOn)
{
	if (isOn)
		M10();
	else
		M11();
}

void lathe::AutoAirJetBlastOn(unsigned rpm, unsigned msTime)
{
	M12(rpm, msTime);
}

void lathe::AutoAirJetBlastOff()
{
	M13();
}

void lathe::SetSpindleBrake(bool isOn)
{
	if (isOn)
		M14();
	else
		M15();
}

void lathe::TurretFwrd()
{
	M17();
}

void lathe::TurretRev()
{
	M18();
}

void lathe::OrientSpindle(Num r)
{
	M19(r);
}

void lathe::AdvanceTailstock()
{
	M21();
}

void lathe::RetractTailstock()
{
	M22();
}

void lathe::SetChamferOutOfThread(bool isOn)
{
	if (isOn)
		M23();
	else
		M24();
}

void lathe::EndAndReset()
{
	M30();
}

void lathe::SetMoveChipConveyor(bool isOn)
{
	if (isOn)
		M31();
	else
		M33();
}

void lathe::PartsCatcherToPartOffPos()
{
	M35();
}

void lathe::SetPartsCatcher(bool isOn)
{
	if (isOn)
		M36();
	else
		M37();
}

void lathe::SetSSV(bool isOn)
{
	if (isOn)
		M38();
	else
		M39();
}

void lathe::LowGear()
{
	M41();
}

void lathe::HighGear()
{
	M42();
}

void lathe::SetTurretLock(bool isOn)
{
	if (isOn)
		M44();
	else
		M43();
}

void lathe::SetMCodeRelay(unsigned _num, bool isOn)
{
	switch (_num)
	{
	case 1:
		(isOn) ? M51() : M61();
		break;
	case 2:
		(isOn) ? M52() : M62();
		break;
	case 3:
		(isOn) ? M53() : M63();
		break;
	case 4:
		(isOn) ? M54() : M64();
		break;
	case 5:
		(isOn) ? M55() : M65();
		break;
	case 6:
		(isOn) ? M56() : M66();
		break;
	default:
		Compiler::Assert("MCodeRelay index out of range");
	}
}

void lathe::SetOutputRelay(bool isOn, unsigned relayBank)
{
	if (isOn)
		M59(relayBank);
	else
		M69(relayBank);
}

void lathe::AlarmIfSkipSignal()
{
	M78();
}

void lathe::AlarmIfNoSkipSignal()
{
	M79();
}

void lathe::SetAutoDoor(bool isOpen)
{
	if (isOpen)
		M85();
	else
		M86();
}

void lathe::SetHighPressureCoolant(bool isOn)
{
	if (isOn)
		M88();
	else
		M89();
}

void lathe::SetFixtureClampInput(bool isOn)
{
	if (isOn)
		M90();
	else
		M91();
}

void lathe::SleepMode()
{
	M95();
}

void lathe::JumpIfNoSignal(unsigned lineNum, unsigned varNum)
{
	M96(lineNum, varNum);
}

void lathe::LocalSubprogram(unsigned lineNum, unsigned times)
{
	M97(lineNum, times);
}

void lathe::Subprogram(unsigned progNum, unsigned times)
{
	M98(progNum, times);
}

void lathe::Subprogram(std::string progPath, unsigned times)
{
	M98(progPath, times);
}

void lathe::EndSubprogram()
{
	M99();
}

void lathe::SetProbeArm(bool isExtended)
{
	if (isExtended)
		M104();
	else
		M105();
}

void lathe::UserInput(unsigned varNum)
{
	M109(varNum);
}

void lathe::SetSecondaryChuckClamp(bool isClamped)
{
	if (isClamped)
		M110();
	else
		M111();
}

void lathe::SecondarySpindleAirBlastOn(unsigned rpm, unsigned msTime)
{
	M112(rpm, msTime);
}

void lathe::SecondarySpindleAirBlastOff()
{
	M113();
}

void lathe::SetSecondarySpindleBrake(bool isOn)
{
	if (isOn)
		M114();
	else
		M115();
}

void lathe::OrientSecondarySpindle(Num r)
{
	M119(r);
}

void lathe::SetMCodeRelayMFin(unsigned _num)
{
	switch (_num)
	{
	case 1:
		M121();
		break;
	case 2:
		M122();
		break;
	case 3:
		M123();
		break;
	case 4:
		M124();
		break;
	case 5:
		M125();
		break;
	case 6:
		M126();
		break;
	default:
		Compiler::Assert("MCodeRelay with M-Fin index out of range");
	}
}

void lathe::MCodeRelayMFinOn(unsigned relayBank)
{
	M129(relayBank);
}

void lathe::SetShowDisplayMedia(bool isOn, std::string file)
{
	if (isOn)
		M130(file);
	else
		M131();
}

void lathe::LiveToolFrwd(unsigned rpm)
{
	M133(rpm);
}

void lathe::LiveToolRev(unsigned rpm)
{
	M134(rpm);
}

void lathe::LiveToolStop()
{
	M135();
}

void lathe::SSVCustomStart(Num amt, Num rate)
{
	M138(amt, rate);
}

void lathe::SSVCustomStop()
{
	M139();
}

void lathe::SecondarySpindleFrwd(unsigned rpm)
{
	M143(rpm);
}

void lathe::SecondarySpindleRev(unsigned rpm)
{
	M144(rpm);
}

void lathe::SecondarySpindleStop()
{
	M145();
}

void lathe::SetSteadyRest(bool isClamped)
{
	if (isClamped)
		M146();
	else
		M147();
}

void lathe::SetMistCondenser(bool isOn)
{
	if (isOn)
		M158();
	else
		M159();
}

void lathe::Set4thAxisBrake(bool isOn)
{
	if (isOn)
		M170();
	else
		M171();
}

void lathe::SetLiveToolBrake(bool isOn)
{
	if (isOn)
		M214();
	else
		M215();
}

void lathe::OrientLiveTool(Num r)
{
	M219(r);
}

void lathe::EndAndResetAPL()
{
	M299();
}

void lathe::CustomSequenceAPL(unsigned progNum, bool reverse)
{
	M300(progNum, reverse);
}

void lathe::PCoolAdd(int amt)
{
	if (amt > 0)
		M334(amt);
	else if (amt < 0)
		M335(-amt);
	else
		Compiler::Assert("P-Cool Increment/Decrement called amount 0");
}

void lathe::SetToolAirBlash(bool isOn)
{
	if (isOn)
		M373();
	else
		M374();
}

void lathe::ThroughSpindleCoolant(bool isOn)
{
	if (isOn)
		M388();
	else
		M389();
}
