#pragma once

class Compiler
{
	Compiler();
	static Compiler& Get();

	std::ofstream file;

public:
	~Compiler();
	static void Init(std::string fileName, std::string path);
	static void Print(std::string line);
	static void Assert(std::string msg);
};
