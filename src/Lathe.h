#pragma once

namespace lathe
{

	

	void NumBlock(unsigned _num);										// N#
	void Tool(unsigned _tool, int offset = -1, bool newLine = true);	// T####
																		// Offset will default to same as tool number if not provided
	void If(unsigned varNum, Num compVal, CMP cmp = EQ);				// IF [ #varNum CMP valCheck ] // For more complex AND and OR, use WriteLine()
	void GoTo(unsigned numBlock);										// GOTO##
	void While(unsigned varNum, Num compVal, unsigned index, CMP cmp = EQ);
	void EndWhile(unsigned index);
	void Var(unsigned _num, Num value = 0.);							// For more complex Math other than #XXX = X. Use WriteLine()
	void BlockDelete();													// '/'
	
	//Lathe M-Codes;
	//Documentation: https://www.haascnc.com/service/service-content/guide-procedures/lathe---m-codes.html

	void Stop();														// M00
	void OptionalStop();												// M01
	void End();															// M02

	void SetSpindleFwrd();												// M03
	void SetSpindleRev();												// M04
	void SpindleStop();													// M05

	void SetCoolant(bool isOn, Num pressure = NONE);					// true -> M08 | false -> M09 (pressure only for ON command)
	void SetChuckClamp(bool isOn);										// true -> M10 | false -> M11
	void AutoAirJetBlastOn(unsigned rpm, unsigned msTime);				// M12
	void AutoAirJetBlastOff();											// M13
	void SetSpindleBrake(bool isOn);									// true -> M14 | false ->M15

	void TurretFwrd();													// M17
	void TurretRev();													// M18

	void OrientSpindle(Num r);											// M19

	void AdvanceTailstock();											// M21

	void RetractTailstock();											// M22
	void SetChamferOutOfThread(bool isOn);								// true -> M23 | false ->M24

	void EndAndReset();													// M30

	void SetMoveChipConveyor(bool isOn);								// true -> M31 | false -> M33

	void PartsCatcherToPartOffPos();									// M35
	void SetPartsCatcher(bool isOn);									// true -> M36 | false -> M37

	void SetSSV(bool isOn);												// true -> M38 | false -> M39

	void LowGear();														// M41
	void HighGear();													// M42

	void SetTurretLock(bool isOn);										// true ->M44 | false -> M43

	void SetMCodeRelay(unsigned _num, bool isOn);						//M51-56 & M61-66
																		//		num = 1: true -> M51 | false -> M61
																		//		num = 2: true -> M52 | false -> M62
																		//		num = 3: true -> M53 | false -> M63
																		//		num = 4: true -> M54 | false -> M64
																		//		num = 5: true -> M55 | false -> M65
																		//		num = 6: true -> M56 | false -> M66

	void SetOutputRelay(bool isOn, unsigned relayBank);					// true -> M59 | false -> M69

	void AlarmIfSkipSignal();											// M78
	void AlarmIfNoSkipSignal();											// M79

	void SetAutoDoor(bool isOpen);										// true -> M85 | false -> M86
	void SetHighPressureCoolant(bool isOn);								// true -> M88 | false -> M89
	void SetFixtureClampInput(bool isOn);								// true -> M90 | false -> M91

	void SleepMode();													// M95

	void JumpIfNoSignal(unsigned lineNum, unsigned varNum);				// M96

	void LocalSubprogram(unsigned lineNum, unsigned times = 1);			// M97
	void Subprogram(unsigned progNum, unsigned times = 1);				// M98 (Number Version)
	void Subprogram(std::string progPath, unsigned times = 1);			// M98 (Path Version)
	void EndSubprogram();												// M99

	void SetProbeArm(bool isExtended);									// true -> M104 | false -> M105
	void UserInput(unsigned varNum);									// M109

	void SetSecondaryChuckClamp(bool isClamped);						// true -> M110 | false -> M111
	void SecondarySpindleAirBlastOn(unsigned rpm, unsigned msTime);		// M112
	void SecondarySpindleAirBlastOff();									// M113
	void SetSecondarySpindleBrake(bool isOn);							// true -> M114 | false -> M115
	void OrientSecondarySpindle(Num r);									// M119

	void SetMCodeRelayMFin(unsigned _num);								//M121-126
																		//		num = 1: M121
																		//		num = 2: M122
																		//		num = 3: M123
																		//		num = 4: M124
																		//		num = 5: M125
																		//		num = 6: M126
	void MCodeRelayMFinOn(unsigned relayBank);							// M129

	void SetShowDisplayMedia(bool isOn, std::string file = "");			// true -> M130 | false M131 (file only for ON command)

	void LiveToolFrwd(unsigned rpm);									// M133
	void LiveToolRev(unsigned rpm);										// M134
	void LiveToolStop();												// M135
	void SSVCustomStart(Num amt, Num rate = NONE);						// M138
	void SSVCustomStop();												// M139

	void SecondarySpindleFrwd(unsigned rpm);							// M143
	void SecondarySpindleRev(unsigned rpm);								// M144
	void SecondarySpindleStop();										// M145

	void SetSteadyRest(bool isClamped);									// true -> M146 | false -> M147
	void SetMistCondenser(bool isOn);									// true -> M158 | false -> M159
	void Set4thAxisBrake(bool isOn);									// true -> M170 | false -> M171

	void SetLiveToolBrake(bool isOn);									// true -> M214 | false -> M215
	void OrientLiveTool(Num r);											// M219

	void EndAndResetAPL();												// M299
	void CustomSequenceAPL(unsigned progNum, bool reverse = false);		// M300

	void PCoolAdd(int amt);												// +'ve -> M334 | -'ve  -> M335
	void SetToolAirBlash(bool isOn);									// true -> M373 | false -> M374
	void ThroughSpindleCoolant(bool isOn);								// true -> M388 | false -> M389

}
