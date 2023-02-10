#include "Pch.h"
#include "Script.h"
#include "Standard.h"

// "USE_CORE" Reveals Raw Codes
#define USE_CORE

// Use only one "USE_LATHE" or "USE_MILL"
#define USE_LATHE
//#define USE_MILL

#ifdef USE_LATHE
#include "Lathe.h"
using namespace lathe;
#ifdef USE_CORE
#include "LatheCore.h"
#endif
#endif

#ifdef USE_MILL
#include "Mill.h"
using namespace mill;
#ifdef USE_CORE
#include "MillCore.h"
#endif
#endif

using namespace std;

Script::Script()
{
	fileName = "O11480";
	exportPath = "output/";
}

void Script::Main(int argc, char* argv[])
{
    Comment("This is a program about that does something");
    SetSpindleBreak(false);
    EndSubprogram();
    BR;

    SetProbeArm(true);
    EndAndReset();
    return 0;
}
