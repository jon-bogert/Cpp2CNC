#pragma once

namespace lathe
{
	void NumBlock(unsigned _num);				// N#
	void Tool(unsigned _tool, int offset);		// T####
												// Offset will default to same as tool number if not provided
	
	//Lathe M-Codes;
	//Documentation: https://www.haascnc.com/service/service-content/guide-procedures/lathe---m-codes.html

	void Stop(); //M00
	void OptionalStop(); //M01
	void End(); // M02
	void SetSpindleFwrd(); //M03
	void SetSpindleRev(); //M04
	void SpindleStop(); // M05
	void SetCoolant(bool isOn); // true -> M08 | false -> M09
	void SetChuckClamp(bool isOn); // true -> M10 | false -> M11
	void SetAutoAirJetBlast(bool isOn); // true -> M12 | flase -> M13
	void SetSpindleBrake(bool isOn); // true -> M14 | false ->M15
	void TurretFwrd(); // M17
	void TurretRev(); // M18
	void OrientSpindle(Num r); // M19
	void AdvanceTailstock(); // M21
	void RetractTailstock(); // M22
	void SetChamferOutOfThread(bool isOn); // true -> M23 | false ->M24
	void EndAndReset(); // M30
	void SetMoveChipConveyor(bool isOn); // true -> M31 | false -> M33
	void PartsCatcherToPartOffPos(); // M35
	void SetPartsCatcher(bool isOn); // true -> M36 | false -> M37
	void SetSSV(bool isOn); // true -> M38 | false -> M39
	void LowGear(); // M41
	void HighGear(); // M42
	void SetTurretLock(bool isOn); // true ->M44 | false -> M43
	void SetMCodeRelay(unsigned _num, bool isOn);
		// num = 1: true -> M51 | false -> M61
		// num = 2: true -> M52 | false -> M62
		// num = 3: true -> M53 | false -> M63
		// num = 4: true -> M54 | false -> M64
		// num = 5: true -> M55 | false -> M65
		// num = 6: true -> M56 | false -> M66
	void SetOutputRelay(bool isOn); // true -> M59 | false -> M69
	void AlarmIfSkipSignal(); // M78
	void AlarmIfNoSkipSignal(); // M79
	void SetAutoDoor(bool isOpen); // true -> M85 | false -> M86
	void SetHighPressureCoolant(bool isOn); // true -> M88 | false -> M89


}
