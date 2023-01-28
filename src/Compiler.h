#pragma once

class Compiler
{
	Compiler() {};
	static Compiler& Get();

	std::ofstream file;
	bool debugPrint = true; // if true, Prints will also print to Console
	unsigned lastGCmd = 999;

public:
	~Compiler();
	static void Init(std::string fileName, std::string path);
	static void Print(std::string line);
	static void Assert(std::string msg);
	static bool CompLastGCmd(unsigned cmd);
	static void SetLastGCmd(const unsigned cmd);
};
