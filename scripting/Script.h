#pragma once

class Script
{
public:
	std::string fileName;
	std::string exportPath;

	Script();

	int Main(int argc, char* argv[]);
};