#pragma once
#include "Car.h"
#include "Weather.h"

class Circuit {
private:
	Car* concurenti[100];
	int nr_concurenti;
	double lung_circuit;
	Weather vreme;
	Car* final[100];
	double timpi[100];
	int nr_final;
	Car* nufinal[100];
	int nr_nufinal;
public:
	Circuit();
	~Circuit();
	void SetLength(double length);
	void SetWeather(Weather weather);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};