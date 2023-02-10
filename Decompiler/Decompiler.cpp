#include "Pch.h"
#include "Decompiler.h"

#define TAB fileWrite << "    "

Decompiler::Decompiler()
{
}

Decompiler& Decompiler::Get()
{
	static Decompiler inst;
	return inst;
}
	
void Decompiler::Run(std::string programName)
{
	std::string path = "programs/" + programName;
	Get().fileRead.open(path);
	if(!Get().fileRead.is_open())
	{
		std::cout << "Could not open Read File at " << path << std::endl;
		return;
	}
	
	Get().fileWrite.open("scripting/Script.cpp");
	if(!Get().fileWrite.is_open())
	{
		std::cout << "Could not open Write File" << std::endl;
		Get().fileRead.close();
		return;
	}
	
	std::string lineStr;
	CmdList line;

	Get().PrintHeader(programName);
	bool firstLine = true;
	
	while(std::getline(Get().fileRead, lineStr))
	{
		if (firstLine)
		{
			while (!lineStr.empty() && lineStr[0] != ' ' && lineStr[0] != '(')
			{
				lineStr.erase(lineStr.begin());
			}
			if (!lineStr.empty() && lineStr[0] == ' ')
			{
				lineStr.erase(lineStr.begin());
			}
			firstLine = false;
		}

		if(lineStr == "")
		{
			Get().TAB;
			Get().fileWrite << "BR;" << std::endl << std::endl;
			continue;
		}
		
		if(lineStr.front() == '(')
			Get().Comment(lineStr);
		else
		{
			try
			{
				Get().LineToList(lineStr, line);
			}
			catch (std::exception execpt)
			{
				std::cout << "Unrecognized format: " << lineStr << " -> Using WriteLine();" << std::endl;
				Get().TAB;
				Get().fileWrite << "WriteLine(\"" << lineStr << "\");" << std::endl;
			}
		}
		while(!line.empty())
		{
			switch(line.front().first)
			{
			case 'M':
				Get().ParseMLathe(line);
				break;
			case 'X':
			case 'Z':
			case 'U':
			case 'G':
				Get().ParseGLathe(line);
				break;
			}
		}
	}
	Get().PrintFooter();
	std::cout << "Decompile Success!\nFile located at: \"/scripting/Script.cpp\"" << std::endl;
}

void Decompiler::SetUsingLathe(bool setTo)
{
	Get().usingLathe = setTo;
}
void Decompiler::SetUsingBaseCode(bool setTo)
{
	Get().usingBaseCode = setTo;
}

void Decompiler::LineToList(const std::string& line, CmdList& list)
{
	if(!list.empty())
		assert("list not empty");

	if (line == "")
		return;
	
	std::stringstream stream;
	stream << line;
	std::string cmdStr;
	
	while (std::getline(stream, cmdStr, ' '))
	{
		Cmd cmd;
		cmd.first = cmdStr.front();
		cmdStr.erase(cmdStr.begin());
		cmd.second = std::stod(cmdStr);
		list.push_back(cmd);
	}
}

void Decompiler::ParseMLathe(CmdList& line)
{
	unsigned codeNum = static_cast<unsigned>(line.front().second);
	switch(codeNum)
	{
	case 0:
		SimplePrint(line, "Stop");
		break;
	case 1:
		SimplePrint(line, "OptionalStop");
		break;
	case 2:
		SimplePrint(line, "End");
		break;
	case 3:
		SimplePrint(line, "SetSpindleFwrd");
		break;
	case 4:
		SimplePrint(line, "SetSpindleRev");
		break;
	case 5:
		SimplePrint(line, "SpindleStop");
		break;
	case 8:
		TAB;
		line.pop_front();
		if (usingBaseCode)
			fileWrite << "M08(";
		else
			fileWrite << "SetCoolant(true";
		if (line.size() > 0 && line.front().first == 'P')
		{
			if (!usingBaseCode)
				fileWrite << ", ";
			fileWrite << line.front().second;
			line.pop_front();
		}
		fileWrite << ");" << std::endl;
		break;
	case 9:
		TogglePrint(line, "SetCoolant", false);
		break;
	case 10:
		TogglePrint(line, "SetChuckClamp", true);
		break;
	case 11:
		TogglePrint(line, "SetChuckClamp", false);
		break;
	case 12:
		// TODO
		break;
	case 13:
		SimplePrint(line, "AutoAirJetBlastOff");
		break;
	case 14:
		TogglePrint(line, "SetSpindleBreak", true);
		break;
	case 15:
		TogglePrint(line, "SetSpindleBreak", false);
		break;
	case 17:
		SimplePrint(line, "TurretFwrd");
		break;
	case 18:
		SimplePrint(line, "TurretRev");
		break;
	case 19:
		// TODO
		break;
	case 21:
		SimplePrint(line, "AdvanceTailstock");
		break;
	case 22:
		SimplePrint(line, "RetractTailstock");
		break;
	case 23:
		TogglePrint(line, "SetChamferOutOfTread", true);
		break;
	case 24:
		TogglePrint(line, "SetChamferOutOfTread", false);
		break;
	case 30:
		SimplePrint(line, "EndAndReset");
		break;
	case 31:
		TogglePrint(line, "SetMoveChipConveyor", true);
		break;
	case 33:
		TogglePrint(line, "SetMoveChipConveyor", false);
		break;
	case 35:
		SimplePrint(line, "PartsCatcherToPartOffPos");
		break;
	case 36:
		TogglePrint(line, "SetPartsCatcher", true);
		break;
	case 37:
		TogglePrint(line, "SetPartsCatcher", false);
		break;
	case 38:
		TogglePrint(line, "SetSSV", true);
		break;
	case 39:
		TogglePrint(line, "SetSSV", false);
		break;
	case 41:
		SimplePrint(line, "LowGear");
		break;
	case 42:
		SimplePrint(line, "HighGear");
		break;
	case 43:
		TogglePrint(line, "SetTurretLock", false);
		break;
	case 44:
		TogglePrint(line, "SetTurretLock", true);
		break;
	//TODO 51-56, 59, 61-66, 69
	case 78:
		SimplePrint(line, "AlarmIfSkipSignal");
		break;
	case 79:
		SimplePrint(line, "AlarmIfNoSkipSignal");
		break;
	case 85:
		TogglePrint(line, "SetAutoDoor", true);
		break;
	case 86:
		TogglePrint(line, "SetAutoDoor", false);
		break;
	case 88:
		TogglePrint(line, "SetHighPressureCoolant", true);
		break;
	case 89:
		TogglePrint(line, "SetHighPressureCoolant", false);
		break;
	case 90:
		TogglePrint(line, "SetFixtureClampInput", true);
		break;
	case 91:
		TogglePrint(line, "SetFixtureClampInput", false);
		break;
	case 95:
		SimplePrint(line, "SleepMode");
		break;
	// TODO 96-98
	case 99:
		SimplePrint(line, "EndSubprogram");
		break;
	case 104:
		TogglePrint(line, "SetProbeArm", true);
		break;
	case 105:
		TogglePrint(line, "SetProbeArm", false);
		break;
	case 109:
		// TODO
		break;
	case 110:
		TogglePrint(line, "SetSecondaryChuckClamp", true);
		break;
	case 111:
		TogglePrint(line, "SetSecondaryChuckClamp", false);
		break;
	case 112:
		// TODO
		break;
	case 113:
		SimplePrint(line, "SecondarySpindleAirBlastOff");
		break;
	case 114:
		TogglePrint(line, "SetSecondarySpindleBrake", true);
		break;
	case 115:
		TogglePrint(line, "SetSecondarySpindleBrake", false);
		break;
	default:
		std::cout << "Unrecognized M Code: " << line.front().first << line.front().second << std::endl;
		TAB;
		fileWrite << "Write";
		if (line.size() == 1)
			fileWrite << "Line";
		fileWrite << "(\"" << line.front().first << line.front().second << "\");" << std::endl;
		line.pop_front();
		break;
	}
}
	
void Decompiler::ParseGLathe(CmdList& line)
{
	unsigned codeNum = static_cast<unsigned>(line.front().second);
	switch (codeNum)
	{
	default:
		std::cout << "Unrecognized G Code: " << line.front().first << line.front().second << std::endl;
		TAB;
		fileWrite << "Write";
		if (line.size() == 1)
			fileWrite << "Line";
		fileWrite << "(\"" << line.front().first << line.front().second << "\");" << std::endl;
		line.pop_front();
		break;
	}
}
	
void Decompiler::NumBlock(CmdList& line)
{
	Cmd cmd = line.front();
	line.pop_front();
	
	TAB;
	
	if (usingBaseCode)
		fileWrite << "N";
	else
		fileWrite << "NumBlock";
	
	fileWrite << "(" << cmd.second << ");" << std::endl;
}
	
void Decompiler::Tool(CmdList& line)
{
	Cmd cmd = line.front();
	line.pop_front();
	
	unsigned asUInt = static_cast<unsigned>(cmd.second);
	unsigned tool = asUInt / 100;
	unsigned offset = asUInt % 100;
	
	TAB;
	
	if(usingBaseCode)
		fileWrite << "T";
	else
		fileWrite << "Tool";
	
	fileWrite << "(" << tool;
	if (tool != 0 || !line.empty())
		fileWrite << ", " << offset;
	if (!line.empty())
		fileWrite << ", false";
	
	fileWrite << ");" << std::endl;
}

void Decompiler::PrintHeader(std::string programName)
{
	fileWrite <<
		R"(#include "Pch.h"
#include "Script.h"
#include "Standard.h"

// "USE_CORE" Reveals Raw Codes
#define USE_CORE

// Use only one "USE_LATHE" or "USE_MILL"
#define USE_LATHE
//#define USE_MILL

#ifdef USE_LATHE
#include "Lathe.h"
using namespace lathe;
#ifdef USE_CORE
#include "LatheCore.h"
#endif
#endif

#ifdef USE_MILL
#include "Mill.h"
using namespace mill;
#ifdef USE_CORE
#include "MillCore.h"
#endif
#endif

using namespace std;

Script::Script()
{
	fileName = ")" << programName << R"(";
	exportPath = "output/";
}

void Script::Main(int argc, char* argv[])
{
)";
}

void Decompiler::PrintFooter()
{
	fileWrite << "    return 0;\n}" << std::endl;
}

void Decompiler::SimplePrint(CmdList& line, const std::string& fnName)
{
	Cmd cmd = line.front();
	line.pop_front();
	
	TAB;
	
	if(usingBaseCode)
		fileWrite << cmd.first << cmd.second;
	else
		fileWrite << fnName;
	
	fileWrite << "();" << std::endl;
}

void Decompiler::TogglePrint(CmdList& line, const std::string& fnName, const bool& setTo)
{
	Cmd cmd = line.front();
	line.pop_front();
	
	TAB;
	
	if(usingBaseCode)
		fileWrite << cmd.first << cmd.second;
	else
		fileWrite << fnName;
	
	std::string boolStr = (setTo) ? "true" : "false";
	
	fileWrite << "(";
	if (!usingBaseCode)
		fileWrite << boolStr;
	fileWrite << ");" << std::endl;
}

void Decompiler::Comment(std::string line)
{
	TAB;
	while(line.back() != ')')
		line.pop_back();
	
	std::string comment;
	for (size_t i = 2; i < line.length() - 2; ++i)
	{
		comment.push_back(line[i]);
	}
	
	fileWrite << "Comment(\"" << comment << "\");" << std::endl;
}
