#include "stdafx.h"
#include "PhysicsCalculator.h"
#include "PhysicalConstants.h"
#include <math.h>

double PhysicsCalculator::GetConvertedMetersPerSecondToMPH(double originalValue)
{
	double mPerMi = METERS_PER_MILE();
	double convertedValue = (originalValue / mPerMi)*SECONDS_PER_HOUR;
	return convertedValue;
}

double PhysicsCalculator::GetConvertedMPHToMetersPerSecond(double originalValue)
{
	double mPerMi = METERS_PER_MILE();
	double convertedValue = (originalValue * mPerMi)/SECONDS_PER_HOUR;
	return convertedValue;
}

double PhysicsCalculator::GetEscapeVelocity()
{
	double G = GRAVITATIONAL_CONSTANT();
	double M = HALLEYS_COMET_MASS();
	double R = HALLEYS_COMET_RADIUS();
	double escapeVelocity = sqrt((2 * G*M) / R);
	escapeVelocity = GetConvertedMetersPerSecondToMPH(escapeVelocity);
	return escapeVelocity;
}

double PhysicsCalculator::GetStellarMassForMinimumReturn(double minimumEscapeVelocity)
{
	double G = GRAVITATIONAL_CONSTANT();
	double R = HALLEYS_COMET_RADIUS();
	double minimumEscapeVelocityConverted = GetConvertedMPHToMetersPerSecond(minimumEscapeVelocity);
	double newStellarMass = (R*(pow(minimumEscapeVelocityConverted, 2))) / (2 * G);
	return newStellarMass;
}
