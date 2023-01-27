#include "Pch.h"
#include "Lathe.h"
#include "LatheCore.h"
#include "Compiler.h"

void lathe::NumBlock(unsigned _num)
{
	N(_num);
}

void lathe::Tool(unsigned _tool, int offset)
{
	T(_tool, offset);
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

void lathe::SetCoolant(bool isOn)
{
	if (isOn)
		M08();
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

void lathe::SetAutoAirJetBlast(bool isOn)
{
	if (isOn)
		M12();
	else
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
		Compiler::Assert("MCodeReay index out of range");
	}
}

void lathe::SetOutputRelay(bool isOn)
{
	if (isOn)
		M59();
	else
		M69();
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
