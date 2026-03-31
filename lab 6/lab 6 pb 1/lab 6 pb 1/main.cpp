#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"

int main() {
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Rain);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());

	c.Race();

	c.ShowFinalRanks(); // afiseaza masinile sortate in functie de timp
	c.ShowWhoDidNotFinish(); // afiseaza Fiat-ul care nu are combustibil suficient

	return 0;
}