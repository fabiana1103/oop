#include "Seat.h"

double Seat::GetFuelCapacity() const { return 45.0; }
double Seat::GetFuelConsumption() const { return 5.5; }
double Seat::GetAverageSpeed(Weather w) const {
	if (w == Weather::Sunny) { return 110.0; }
	if (w == Weather::Rain) { return 90.0; }
	return 60.0;
}
const char* Seat::GetName() const { return "Seat"; }