// EscapeVelocity.cpp : main project file.

#include "stdafx.h"
#include <string>
#include "DataPointComparer.h"
#include "PhysicsCalculator.h"
#include <sstream>
#include <iostream>

using namespace System;
using namespace std;

int main(int argc, char* argv[])
{
	string userInput;

	do
	{
		cout << "Enter launch velocity in mph (or c to exit)=>";
		cin >> userInput;
		if (DataPointComparer::IsValidInput(userInput))
		{
			double inputConvertedToDouble = atof(userInput.c_str());
			if (DataPointComparer::IsValidNumber(inputConvertedToDouble))
			{
				double escapeVelocity = PhysicsCalculator::GetEscapeVelocity();
				if (DataPointComparer::IsLessThan(inputConvertedToDouble, escapeVelocity))
				{
					Console::WriteLine(L"Jumper will return");
					continue;
				}
				else
				{
					double newStellerMassForReturn = PhysicsCalculator::GetStellarMassForMinimumReturn(inputConvertedToDouble);
					ostringstream StringStream;
					StringStream << newStellerMassForReturn;
					std::string output = "Jumper will return if the mass was at least ";
					output += StringStream.str() + "\n";
					cout << output;
					continue;
				}
			}
			else
			{
				Console::WriteLine(L"Invalid Value");
				continue;
			}

		}
		else
		{
			Console::WriteLine(L"Invalid Value");
			continue;
		}
	} while (strcmp(userInput.c_str(), "c") != 0);

    return 0;
}
