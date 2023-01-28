#pragma once
#include "Num.h"

#define BR WriteLine("")
#define NONE Num()

enum CMP
{
	EQ = 0,
	NE,
	GT,
	GE,
	LT,
	LE
};

void Write(std::string line);		// Writes Line as Shown (no EOB)
void WriteLine(std::string line);	// Writes Line as Shown (with EOB)

void Comment(std::string msg);		// Writes Comment Line (with EOB)