#pragma once
#include "Num.h"

#define BR WriteLine("")
#define LAST Num();

void Write(std::string line);		// Writes Line as Shown (no EOB)
void WriteLine(std::string line);	// Writes Line as Shown (with EOB)

void Comment(std::string msg);		// Writes Comment Line (with EOB)