#include "Pch.h"
#include "Standard.h"
#include "Compiler.h"

void Write(std::string line)
{
	Compiler::Print(line);
}

void WriteLine(std::string line)
{
	line.push_back('\n');
	Compiler::Print(line);
}

void Comment(std::string msg)
{
	Compiler::Print("( " + msg + " )\n");
}
