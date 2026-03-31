#include "Volvo.h"

double Volvo::GetFuelCapacity() const { return 70.0; }
double Volvo::GetFuelConsumption() const { return 6.0; }
double Volvo::GetAverageSpeed(Weather w) const {
	if (w == Weather::Sunny) return 130.0;
	if (w == Weather::Rain) return 100.0;
	return 70.0;
}
const char* Volvo::GetName() const { return "Volvo"; }