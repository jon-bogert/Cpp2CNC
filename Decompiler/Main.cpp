#include "Pch.h"

#include "Decompiler.h"

std::string fileName = "O11480";
bool useLathe = true;
bool useBaseCode = false;

void GetUserInput();

int main(int argc, char* argv[])
{
	//GetUserInput();

	Decompiler::SetUsingLathe(useLathe);
	Decompiler::SetUsingBaseCode(useBaseCode);

	std::cout << "\nDecompiling...\n\n";

	Decompiler::Run(fileName);
	system("pause");
	return 0;
}

void GetUserInput()
{
	std::cout << "  ==== Cpp2CNC Decompiler ====\n\n";

	std::cout << "Enter program number to decompile > ";
	std::string input;
	std::getline(std::cin, input);
	if (input[0] == 'o') input.erase(input.begin());
	if (input[0] != 'O') input.insert(input.begin(), 'O');
	fileName = input;
	std::cout << "\nIs this a mill or lathe program? > ";
	std::getline(std::cin, input);

	if (input == "MILL" || input == "Mill" || input == "mill" || input == "m" || input == "M")
		useLathe = false;
	else
		useLathe = true;

	std::cout << "Using " << ((useLathe) ? "lathe" : "mill") << " codes." << std::endl;
	
	std::cout << "\nWould you like to decompile with named functions [y/n] > ";
	std::getline(std::cin, input);
	if (input == "n" || input == "N" || input == "no" || input == "No" || input == "NO")
		useBaseCode = true;
	else
		useBaseCode = false;

	std::cout << "Using " << ((useBaseCode) ? "base code" : "named") << " functions." << std::endl;
}