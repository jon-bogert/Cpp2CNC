#include "Pch.h"
#include "Compiler.h"

Compiler& Compiler::Get()
{
	static Compiler inst;
	return inst;
}

Compiler::~Compiler()
{
	if (file.is_open())
	{
		file.close();
	}
}

void Compiler::Init(std::string fileName, std::string path)
{
	std::ofstream& file = Get().file;
	if (path[path.length() - 1] != '\\' && path[path.length() - 1] != '/')
		path.push_back('\\');

	std::string fullPath = path + fileName + ".txt";

	file.open(fullPath);
	if (!file.is_open())
	{
		std::cout << "ERROR: Could not open or create " << fullPath << std::endl;
		return;
	}

	file << fileName << " ";

	if (Get().debugPrint)
		std::cout << fileName << " ";
}

void Compiler::Print(std::string line)
{
	Get().file << line;

	if (Get().debugPrint)
		std::cout << line;
}

void Compiler::Assert(std::string msg)
{
	std::cout << "Error is Compilation:\n    " + msg << std::endl;
	system("pause");
	if (Get().file.is_open())
	{
		Get().file.close();
	}
	assert(NULL);
}

bool Compiler::CompLastGCmd(unsigned cmd)
{
	return cmd == Get().lastGCmd;
}

void Compiler::SetLastGCmd(const unsigned cmd)
{
	Get().lastGCmd = cmd;
}
