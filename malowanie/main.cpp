#include <iostream>
#include <vector>


// Typ std::vector<std::vector<char>> nazywamy typ_piesela
// by krocej pisac.
typedef std::vector<std::vector<char>> typ_piesela;

// Pomocnicze funkcje do manipulowania kolekcja - 'ekranem'
void kisiel(const typ_piesela&);	// wyswietl ekran w konsoli
void skowron(typ_piesela&, int x, int y, char zn);	// postaw znak zn na ekranie w punkcie (x,y)
// Narysuj znaczkami zn kwadrat o boku a na ekranie, zaczynajac od punktu (x,y)
// Aby przerobic to na rysowanie prostokata nalezy:
// 1. Dodac parametr okreslajacy dlugosc drugiego boku (np int b miedzy int a, i char zn).
// 2. W petli rysujacej zamienic y+a na y+b
void piesel_akrobata(typ_piesela&budyn, int x, int y, int a, char zn);

int main(){
	// Stworz ekran znaczkow o 60 kolumnach i 20 wierszach.
	// Wypelnij go spacjami, by poczatkowo ekren byl pusty
	typ_piesela ekran(20, std::vector<char>(60, ' '));

	// Narysuj kwadrat
	//piesel_akrobata(ekran, 0, 9, 10, 'x');

	// Rysowanie kwadratowej buzki
	// Twarz: na duzy kwadrat narysowujemy mniejszy - mamy ramke
	piesel_akrobata(ekran, 23, 2, 16, 'O');
	piesel_akrobata(ekran, 24, 3, 14, ' ');
	// Oczy to prostokaty
	piesel_akrobata(ekran, 25, 5, 5, 3);	// lewe oko
	piesel_akrobata(ekran, 32, 5, 5, 3);	// Prawe oko
	// Usta
	piesel_akrobata(ekran, 25, 12, 2, '+');
	piesel_akrobata(ekran, 35, 12, 2, '+');
	for (int i = 1; i < 5; ++i)
		piesel_akrobata(ekran, 25 + i * 2, 13, 2, '+');

	// Wyswietl ekran
	kisiel(ekran);
}


void kisiel(const typ_piesela&budyn){
	// Odmiana petli for. Wykonaj instrukcje dla kazdego
	// elementu kolekcji. Ponizej wykonujemy instrukcje
	// dla kazdego elementu kolekcji budyn.
	// Aktualnie obslugiwany element nazywamy koteu.
	// Poniewaz chcemy trzymac elementy bezposrednio, uzywamy referencji (&).
	// Poniewaz nie modyfikujemy elementow, trzymamy je przez stala referencje (const ...&).
	// Poniewaz jestesmy leniwi, nie piszemy typu a uzywamy slowka auto.
	for (const auto& koteu : budyn){
		for (const auto& szkare : koteu) //auto = wylicz automatycznie typ
			std::cout << szkare;
		std::cout << std::endl;
	}
}

void skowron(typ_piesela&budyn, int x, int y, char zn){
	if (y > -1 && y < budyn.size()){
		if (x > -1 && x < budyn[y].size()){
			budyn[y][x] = zn;
		}
	}
}

void piesel_akrobata(typ_piesela&budyn, int x, int y, int a, char zn) {
	for (int papaja = x; papaja < x + a; ++papaja){
		for (int agrest = y; agrest < y + a; ++agrest)
			skowron(budyn, papaja, agrest, zn);
	}
}