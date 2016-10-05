#pragma once

class Body;

namespace PhysicsCalculator
{
	double GetEscapeVelocity();
	double GetStellarMassForMinimumReturn(double minimumEscapeVelocity);
	double GetConvertedMetersPerSecondToMPH(double originalValue);
	double GetConvertedMPHToMetersPerSecond(double originalValue);
};

