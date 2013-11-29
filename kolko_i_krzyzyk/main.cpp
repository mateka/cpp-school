#include <iostream>
#include <vector>
#include <locale>

// Okreslenie innej nazwy dla typu planszy (by krocej pisac)
typedef std::vector<std::vector<char>> typ_piesela;

// Deklaracja pomocniczych funkcji (potrzebujemy zadeklarowac ich nazwy przed uzyciem
// w funkcji main - glownej funkcji programu)
char sprawdz(const typ_piesela & p);
void wyswietl_plansze(const int x, const int y, const typ_piesela & piesel);

int main()
{
	const char puste = ' ';	// puste pole
	// przygotuj plansze i ja zainicjuj
	typ_piesela piesel; //piesel == plansza
	for (int i = 0; i < 3; ++i) {
		auto ciastko = std::vector<char>(3, puste);
		piesel.push_back(ciastko);
	}

	// Znak gracza
	char znaczek = 'o';
	// Maksymalnie 9 ruchow
	for (int banan = 0; banan < 9; ++banan)// tu byl nadmiarowy srednik! 
	{
		// wczytaj ruch gracza - wspolrzedne
		// wczytujemy je w nieskonczonosc az:
		// 1. nie sa poprawne
		// 2. trafiaja w zajete pole
		int y = 10;
		int x = 10;
		while (true) {
			std::cout << "Podaj Wspolrzedne" << std::endl;
			std::cin >> x >> y;

			if (0 <= x && x < 3 && 0 <= y && y < 3) {
				if (puste == piesel[x][y]) break;
			}
		}
		// Ustaw znak gracza i zmien na drugiego
		piesel[x][y] = znaczek;
		if ('o' == znaczek)znaczek = 'x';
		else znaczek = 'o';

		wyswietl_plansze(x, y, piesel);	// wyswietl plansze
		
		char wynik = sprawdz(piesel);	// policz, czy nie ma zwyciezcy
		if (wynik){	// sprawdz wygrana
			std::cout << "Wygral " << wynik << std::endl;
			break;
		}

	}

}


/*
 *  Funkcja sprawdz pobiera stala referencje do planszy (czyli pobiera sama plansze a nie jej kopie)
 *  i sprawdza, czy nie ma ustawionej linii.
 *  Zwracane wartosci sa typu char. Mozliwe wartosci:
 *    - 'x', 'o' - znak wygrywajacego gracza
 *    - 0 - nie ma zwyciezcy
 */
char sprawdz(const typ_piesela & p){
	// Wykluczajace sie warunki mozna sprawdzac za pomoca konstrukcji if ... else if ... else... .
	// Przykladowo, mozna myslec o:
	// if(jest linia 'x' w 0. wierszu) return 'x';
	// else if(jest linia 'x' w 1. wierszu) return 'x';
	// ...
	// else return 0; // nie ma zadnej linii
	// Na lekcji porozmawiamy, czy uprawnione jest zamienienie powyzszego na serie niezaleznych warunkow (if... if... ...).
	if (p[0][0] == 'x' && p[0][1] == 'x' && p[0][2] == 'x') return'x';
	else if (p[1][0] == 'x' && p[1][1] == 'x' && p[1][2] == 'x') return'x';
	// else { /* co w pozostalych przypadkach */}

	// Podpowiedzi, jak mozna skrocic kod:
	// 1. Zamiast sprawdzac, czy w wierszu 1 jest linia 'x'
	//    i potem czy w wierszu 1. jest linia 'o', mozna sprawdzic
	//    czy w wierszu 1. jest linia i zwrocic wartosc jednego
	//    z pol tego wiersza. Oszczedzi to duplikowania warunkow dla 'o'.
	// 2. Slowo kluczowe "return" wychodzi z funkcji i zwraca wartosc.
	//    Zatem, przerwie wszystkie zagniezdzone petle, w ktorych jest umieszczone
	//    (break przerywa tylko jedna).
	//    Mozna zatem sprawdzac, czy jest linia w i. wierszu za pomoca petli...
	//    Analogicznie dla kolumn.

	return 0;

}


/*
 *  Wyswietlanie planszy
*/
void wyswietl_plansze(const int x, const int y, const typ_piesela& piesel){


	for (int i = 0; i < 3; ++i) {

		for (int j = 0; j < 3; ++j) {

			if (i == x && j == y){

				std::cout << "("
					<< static_cast<char>(toupper(piesel[i][j]))
					<< ")";



			}
			else{
				std::cout << "("
					<< piesel[i][j]
					<< ")";

				/*
				// Te polecenia robia dokladnie to samo, co powyzsze i niezakomentowane
				std::cout <<"(" << piesel[i][j] << ")" ;

							std::cout <<"(";
							std::cout <<piesel[i][j];
							std::cout  << ")" ;*/
			}
		}

		std::cout << std::endl;
	}




}