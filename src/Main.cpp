#include "Pch.h"
#include "Compiler.h"
#include "Script.h"

int main(int argc, char* argv[])
{
	Script script;
	Compiler::Init(script.fileName, script.exportPath);
	return script.Main(argc, argv);
}