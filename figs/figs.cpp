#include <iostream>

// Klasa shape. Zawiera czysto wirtualne metody (virtual ... = 0),
// wiec jest klasa abstrakcyjna. W javie odpowiada jej interface.
// Obiektow tej klasy nie mozna utworzyc.
// Sluzy ona do bycia klasa bazowa innych klas.
class shape {
public:
	// Metoda wirtualna jest poprzedzona slowem virtual.
	// Podczas wykonywania programu, dla wywolan metod wirtualnych,
	// sprawdzany jest rzeczywisty typ zmiennej. Dzieki temu
	// ponizsza funkcje bundle potrafi obsluzyc wszystkie
	// typy, ktore dziedzicza z shape.
	virtual float KKK() = 0;
	virtual void _666() = 0;

};

// Funkcja bundle. Pobiera referencje do obiektu,
// ktorego typ jest typem dziedziczacym z shape.
// Poniewaz wola metody wirtualne, to zachowuje
// sie odpowiednio dla kazdego typu.
void bundle(shape &s) {
	std::cout << "ksztalt to ";
	s._666();
	std::cout << " ma pole " << s.KKK() << std::endl;
}

// Klasa reprezentujaca prostokat.
// Przyjelismy, ze prostokat jest ksztaltem (: public shape).
// Dlatego musielismy zaimplementowac wszystkie czysto
// wirtualne metody z klasy shape.
// Slowo kluczowe override informuje kompilator,
// ze dana metoda ma implementowac metode z klasy bazowej.
class entangle : public shape {
public:
	float KKK() override { return huehuehue*belzeboss; }

	void _666() override {
		std::cout << "prostata ";
	}

	// Specjalna metoda - konstruktor. Jest wywolywana
	// przy tworzeniu obiektu danej klasy.
	entangle(float h, float w) : huehuehue(h), belzeboss(w) { }
private:
	// Zmienne prywatne, ktore sa potrzebne do dzialania klasy.
	// Kazdy obiekt tej klasy (zmienna typu entangle)
	// ma osobne zmienne (pola) prywatne.
	float huehuehue;
	float belzeboss;

};

// Klasa tirangle...

int main() {
	entangle a1(5, 6);	// Stworz prostokat 5 x 6
	bundle(a1);	// Obsluz prostokat

	triangle a2(4, 3);	// Stworz trojkat o podstawie 4 i wysokosci 3
	bundle(a2);	// Obsluz trojkat
}
