#pragma once
#include "Car.h"

class BMW : public Car {
	double GetFuelCapacity() const override;
	double GetFuelConsumption() const override;
	double GetAverageSpeed(Weather w) const override;
	const char* GetName() const override;
};