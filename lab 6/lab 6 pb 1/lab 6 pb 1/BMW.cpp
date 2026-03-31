#include "BMW.h"

double BMW::GetFuelCapacity() const { return 65.5; }
double BMW::GetFuelConsumption() const { return 8.5; }
double BMW::GetAverageSpeed(Weather w) const { 
	if (w == Weather::Sunny) return 160.0;
	if (w == Weather::Rain) return 120.0;
	return 80;
}
const char* BMW::GetName() const { return "BMW"; }