#pragma once

typedef std::pair<char, double> Cmd;
typedef std::deque<Cmd> CmdList;

class Decompiler
{
	bool usingLathe = true;
	bool usingBaseCode = false;
	int lastGMove = -1;
	
	std::ifstream fileRead;
	std::ofstream fileWrite;
	
	Decompiler();
	static Decompiler& Get();
	
public:
	static void Run(std::string programName);
	static void SetUsingLathe(bool setTo);
	static void SetUsingBaseCode(bool setTo);
	
private:
	void LineToList(const std::string& line, CmdList& list);
	void ParseMLathe(CmdList& line);
	void ParseGLathe(CmdList& line);
	void NumBlock(CmdList& line);
	void Tool(CmdList& line);

	void PrintHeader(std::string programName);
	void PrintFooter();
	void SimplePrint(CmdList& line, const std::string& fnName);
	void TogglePrint(CmdList& line, const std::string& fnName, const bool& setTo);
	void Comment(std::string line);
};