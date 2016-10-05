#include "stdafx.h"
#include "DataPointComparer.h"
#include <math.h>
#include <float.h>

using namespace std;

bool DataPointComparer::IsLessThan(double left, double right)
{
	if ((right - left) > DBL_EPSILON)
	{
		return true;
	}
	return false;
}

bool DataPointComparer::IsEqual(double left, double right)
{
	if (fabs((left - right) < DBL_EPSILON))
	{
		return true;
	}
	return false;
}

bool DataPointComparer::IsValidInput(const string& rawInput)
{
	for (size_t stringIndex = 0; stringIndex < rawInput.size(); ++stringIndex)
	{
		if (isalpha(rawInput[stringIndex]))
		{
			return false;
		}
	}

	return true;
}

bool DataPointComparer::IsValidNumber(double input)
{
	if (DataPointComparer::IsLessThan(input, 0))
	{
		return false;
	}
	return true;
}