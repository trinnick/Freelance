#pragma once

#include <string>

namespace DataPointComparer
{
	bool IsLessThan(double left, double right);
	bool IsEqual(double left, double right);
	bool IsValidInput(const std::string& rawInput);
	bool IsValidNumber(double input);
};

