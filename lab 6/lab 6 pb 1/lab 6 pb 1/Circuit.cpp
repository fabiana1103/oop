#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
	nr_concurenti = 0;
	lung_circuit = 0;
	vreme = Weather::Sunny;
	nr_final = 0;
	nr_nufinal = 0;
}

Circuit::~Circuit() {
	for (int i = 0; i < nr_concurenti; i++)
		delete concurenti[i];
}

void Circuit::SetLength(double length) {
	lung_circuit = length;
}

void Circuit::SetWeather(Weather weather)
{
	vreme = weather;
}

void Circuit::AddCar(Car* car) {
	if (nr_concurenti < 100) concurenti[nr_concurenti++] = car;
}

void Circuit::Race() {
	nr_final = 0;
	nr_nufinal = 0;
	for (int i = 0; i < nr_concurenti; i++) {
		Car* masina_curenta = concurenti[i];
		double necesar_combust = masina_curenta->GetFuelConsumption() * lung_circuit / 100.0;
		if (necesar_combust <= masina_curenta->GetFuelCapacity()) {
			final[nr_final] = masina_curenta;
			timpi[nr_final] = lung_circuit / masina_curenta->GetAverageSpeed(vreme);
			nr_final++;
		}
		else {
			nufinal[nr_nufinal++] = masina_curenta;
		}
	}
	for (int i = 0; i < nr_final - 1; i++) {
		for (int j = i + 1; j < nr_final; j++) {
			if (timpi[i] > timpi[j]) {
				double tempTimp = timpi[i];
				timpi[i] = timpi[j];
				timpi[j] = tempTimp;
				Car* tempMasina = final[i];
				final[i] = final[j];
				final[j] = tempMasina;
			}
		}
	}
}

void Circuit::ShowFinalRanks() {
	std::cout << "clasament final" << std::endl;
	for (int i = 0; i < nr_final; i++) {
		std::cout << i + 1 << ". " << final[i]->GetName()
			<< " timp: " << timpi[i] << " ore" << std::endl;
	}
}

void Circuit::ShowWhoDidNotFinish() {
	std::cout << "au ramas fara combustibil " << std::endl;
	if (nr_nufinal == 0) {
		std::cout << "toate masinile au terminat" << std::endl;
		return;
	}

	for (int i = 0; i < nr_nufinal; i++) {
		std::cout << " " << nufinal[i]->GetName() << std::endl;
	}
	std::cout << std::endl;
}