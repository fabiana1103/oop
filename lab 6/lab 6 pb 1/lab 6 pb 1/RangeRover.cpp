#include "RangeRover.h"

double RangeRover::GetFuelCapacity() const { return 45.0; }
double RangeRover::GetFuelConsumption() const { return 5.5; }
double RangeRover::GetAverageSpeed(Weather w) const {
	if (w == Weather::Sunny) { return 110.0; }
	if (w == Weather::Rain) { return 90.0; }
	return 60.0;
}
const char* RangeRover::GetName() const { return "RangeRover"; }