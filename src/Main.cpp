#include "Pch.h"
#include "Compiler.h"
#include "Script.h"

int main(int argc, char* argv[])
{
	Script script;
	Compiler::Init(script.fileName, script.exportPath);
	script.Main(argc, argv);
	return 0;
}