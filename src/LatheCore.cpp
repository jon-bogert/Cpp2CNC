#include "Pch.h"
#include "LatheCore.h"
#include "Compiler.h"

void lathe::N(unsigned _num)
{
	std::stringstream lineStream;
	lineStream << "N" << _num << " ";
	Compiler::Print(lineStream.str());
}

void lathe::T(unsigned _tool, int offset)
{
	if (_tool < 12 || offset > 12 || offset < -1)
	{
		Compiler::Assert("Tool or Offset out of range");
	}

	if (offset == -1)
		offset = _tool;

	std::stringstream line;
	std::string offStr = (offset < 0) ? "0" + offset : std::to_string(offset) ;
	line << "T" << _tool << offset << std::endl;
	Compiler::Print(line.str());
}

void lathe::M00()
{
	Compiler::Print("M00\n");
}

void lathe::M01()
{
	Compiler::Print("M01\n");
}

void lathe::M02()
{
	Compiler::Print("M02\n");
}

void lathe::M03()
{
	Compiler::Print("M03\n");
}

void lathe::M04()
{
	Compiler::Print("M04\n");
}

void lathe::M05()
{
	Compiler::Print("M05\n");
}

void lathe::M08()
{
	Compiler::Print("M08\n");
}

void lathe::M09()
{
	Compiler::Print("M09\n");
}

void lathe::M10()
{
	Compiler::Print("M10\n");
}

void lathe::M11()
{
	Compiler::Print("M11\n");
}

void lathe::M12()
{
	Compiler::Print("M12\n");
}

void lathe::M13()
{
	Compiler::Print("M13\n");
}

void lathe::M14()
{
	Compiler::Print("M14\n");
}

void lathe::M15()
{
	Compiler::Print("M15\n");
}

void lathe::M17()
{
	Compiler::Print("M17\n");
}

void lathe::M18()
{
	Compiler::Print("M18\n");
}

void lathe::M19(Num r)
{
	if (r < 0 || r > 360)
		Compiler::Assert("M19 Rotation out of Range");

	std::string param1 = (r.IsWhole()) ? "P" + r.FormatInt() : "R" + r.FormatDec2();
	Compiler::Print("M19 " + param1 + "\n");
}

void lathe::M21()
{
	Compiler::Print("M21\n");
}

void lathe::M22()
{
	Compiler::Print("M22\n");
}

void lathe::M23()
{
	Compiler::Print("M23\n");
}

void lathe::M24()
{
	Compiler::Print("M24\n");
}

void lathe::M30()
{
	Compiler::Print("M30\n");
}

void lathe::M31()
{
	Compiler::Print("M31\n");
}

void lathe::M33()
{
	Compiler::Print("M33\n");
}

void lathe::M35()
{
	Compiler::Print("M35\n");
}

void lathe::M36()
{
	Compiler::Print("M36\n");
}

void lathe::M37()
{
	Compiler::Print("M37\n");
}

void lathe::M38()
{
	Compiler::Print("M38\n");
}

void lathe::M39()
{
	Compiler::Print("M39\n");
}

void lathe::M41()
{
	Compiler::Print("M41\n");
}

void lathe::M42()
{
	Compiler::Print("M42\n");
}

void lathe::M43()
{
	Compiler::Print("M43\n");
}

void lathe::M44()
{
	Compiler::Print("M44\n");
}

void lathe::M51()
{
	Compiler::Print("M51\n");
}

void lathe::M52()
{
	Compiler::Print("M52\n");
}

void lathe::M53()
{
	Compiler::Print("M53\n");
}

void lathe::M54()
{
	Compiler::Print("M54\n");
}

void lathe::M55()
{
	Compiler::Print("M55\n");
}

void lathe::M56()
{
	Compiler::Print("M56\n");
}

void lathe::M59()
{
	Compiler::Print("M59\n");
}

void lathe::M61()
{
	Compiler::Print("M61\n");
}

void lathe::M62()
{
	Compiler::Print("M62\n");
}

void lathe::M63()
{
	Compiler::Print("M63\n");
}

void lathe::M64()
{
	Compiler::Print("M64\n");
}

void lathe::M65()
{
	Compiler::Print("M65\n");
}

void lathe::M66()
{
	Compiler::Print("M66\n");
}

void lathe::M69()
{
	Compiler::Print("M69\n");
}

void lathe::M78()
{
	Compiler::Print("M78\n");
}

void lathe::M79()
{
	Compiler::Print("M79\n");
}

void lathe::M85()
{
	Compiler::Print("M85\n");
}

void lathe::M86()
{
	Compiler::Print("M86\n");
}

void lathe::M88()
{
	Compiler::Print("M88\n");
}

void lathe::M89()
{
	Compiler::Print("M89\n");
}

void lathe::M90()
{
	Compiler::Print("M90\n");
}

void lathe::M91()
{
	Compiler::Print("M91\n");
}

void lathe::M95()
{
	Compiler::Print("M95\n");
}

void lathe::M96()
{
	Compiler::Print("M96\n");
}

void lathe::M97()
{
	Compiler::Print("M97\n");
}

void lathe::M98()
{
	Compiler::Print("M98\n");
}

void lathe::M99()
{
	Compiler::Print("M99\n");
}

void lathe::M104()
{
	Compiler::Print("M104\n");
}

void lathe::M105()
{
	Compiler::Print("M105\n");
}

void lathe::M109()
{
	Compiler::Print("M109\n");
}

void lathe::M110()
{
	Compiler::Print("M110\n");
}

void lathe::M111()
{
	Compiler::Print("M111\n");
}

void lathe::M112()
{
	Compiler::Print("M112\n");
}

void lathe::M113()
{
	Compiler::Print("M113\n");
}

void lathe::M114()
{
	Compiler::Print("M114\n");
}

void lathe::M115()
{
	Compiler::Print("M115\n");
}

void lathe::M119()
{
	Compiler::Print("M119\n");
}

void lathe::M121()
{
	Compiler::Print("M121\n");
}

void lathe::M122()
{
	Compiler::Print("M122\n");
}

void lathe::M123()
{
	Compiler::Print("M123\n");
}

void lathe::M124()
{
	Compiler::Print("M124\n");
}

void lathe::M125()
{
	Compiler::Print("M125\n");
}

void lathe::M126()
{
	Compiler::Print("M126\n");
}

void lathe::M129()
{
	Compiler::Print("M129\n");
}

void lathe::M130()
{
	Compiler::Print("M130\n");
}

void lathe::M131()
{
	Compiler::Print("M131\n");
}

void lathe::M133()
{
	Compiler::Print("M133\n");
}

void lathe::M134()
{
	Compiler::Print("M134\n");
}

void lathe::M135()
{
	Compiler::Print("M135\n");
}

void lathe::M138()
{
	Compiler::Print("M138\n");
}

void lathe::M139()
{
	Compiler::Print("M139\n");
}

void lathe::M143()
{
	Compiler::Print("M143\n");
}

void lathe::M144()
{
	Compiler::Print("M144\n");
}

void lathe::M145()
{
	Compiler::Print("M145\n");
}

void lathe::M146()
{
	Compiler::Print("M146\n");
}

void lathe::M147()
{
	Compiler::Print("M147\n");
}

void lathe::M158()
{
	Compiler::Print("M158\n");
}

void lathe::M159()
{
	Compiler::Print("M159\n");
}

void lathe::M170()
{
	Compiler::Print("M170\n");
}

void lathe::M171()
{
	Compiler::Print("M171\n");
}

void lathe::M214()
{
	Compiler::Print("M214\n");
}

void lathe::M215()
{
	Compiler::Print("M215\n");
}

void lathe::M219()
{
	Compiler::Print("M219\n");
}

void lathe::M299()
{
	Compiler::Print("M299\n");
}

void lathe::M300()
{
	Compiler::Print("M300\n");
}

void lathe::M334()
{
	Compiler::Print("M334\n");
}

void lathe::M335()
{
	Compiler::Print("M335\n");
}

void lathe::M373()
{
	Compiler::Print("M373\n");
}

void lathe::M374()
{
	Compiler::Print("M374\n");
}

void lathe::M388()
{
	Compiler::Print("M388\n");
}

void lathe::M389()
{
	Compiler::Print("M389\n");
}
