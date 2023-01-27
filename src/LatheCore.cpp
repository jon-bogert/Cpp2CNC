#include "Pch.h"
#include "LatheCore.h"
#include "Compiler.h"

void lathe::N(unsigned _num)
{
	std::string numStr = (_num < 10) ? "0" + _num : std::to_string(_num);
	std::stringstream line;
	line << numStr << " ";

	Compiler::Print(line.str());
}
