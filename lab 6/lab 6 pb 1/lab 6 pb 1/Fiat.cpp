#include "Fiat.h"

double Fiat::GetFuelCapacity() const { return 5.0; }
double Fiat::GetFuelConsumption() const { return 6.0; }
double Fiat::GetAverageSpeed(Weather w) const {
	if (w == Weather::Sunny) return 100.0;
	if (w == Weather::Rain) return 80;
	return 50.0;
}
const char* Fiat::GetName() const { return "Fiat"; }