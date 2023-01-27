#pragma once

class Script
{
public:
	std::string fileName;
	std::string exportPath;

	Script();

	void Main(int argc, char* argv[]);
};