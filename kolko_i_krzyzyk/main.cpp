#include <iostream>
#include <vector>
#include <locale>

// Okreslenie innej nazwy dla typu planszy (by krocej pisac)
typedef std::vector<std::vector<char>> typ_piesela;
const int rozmiar = 20;
const int dl = 5;

// Deklaracja pomocniczych funkcji (potrzebujemy zadeklarowac ich nazwy przed uzyciem
// w funkcji main - glownej funkcji programu)
char sprawdz(const typ_piesela & p);
void wyswietl_plansze(const int x, const int y, const typ_piesela & piesel);

int main()
{
	const char puste = ' ';	// puste pole
	// przygotuj plansze i ja zainicjuj
	typ_piesela piesel; //piesel == plansza
	for (int i = 0; i < rozmiar; ++i) {
		auto ciastko = std::vector<char>(rozmiar, puste);
		piesel.push_back(ciastko);
	}

	// Znak gracza
	char znaczek = 'o';
	int y = rozmiar + 100;
	int x = rozmiar + 100;
	// Maksymalnie 9 ruchow
	for (int banan = 0; banan < rozmiar*rozmiar; ++banan)// tu byl nadmiarowy srednik! 
	{
		// wczytaj ruch gracza - wspolrzedne
		// wczytujemy je w nieskonczonosc az:
		// 1. nie sa poprawne
		// 2. trafiaja w zajete pole

		wyswietl_plansze(x, y, piesel);	// wyswietl plansze

		while (true) {
			char znx;
			std::cout << std::endl << "Podaj Wspolrzedne" << std::endl;
			std::cin >> znx >> y;
			x = znx - 'a';

			if (0 <= x && x < rozmiar && 0 <= y && y < rozmiar) {
				if (puste == piesel[x][y]) break;
			}
		}
		// Ustaw znak gracza i zmien na drugiego
		piesel[x][y] = znaczek;
		if ('o' == znaczek)znaczek = 'x';
		else znaczek = 'o';

		
		
		char wynik = sprawdz(piesel);	// policz, czy nie ma zwyciezcy
		if (0 < wynik) {
			wyswietl_plansze(x, y, piesel);	// wyswietl plansze

			if (wynik == 'x'){	// sprawdz wygrana
				std::cout << std::endl << "Wygral " << wynik << std::endl;
			}
			else if (wynik == 'o'){	// sprawdz wygrana
				std::cout << std::endl << "Wygralo " << wynik << std::endl;
			}
			else if (wynik == 5){	// sprawdz wygrana
				std::cout << "Remis " << wynik << std::endl;
			}

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
	/*if (p[0][0] == 'x' && p[0][1] == 'x' && p[0][2] == 'x') return'x';
	else if (p[1][0] == 'x' && p[1][1] == 'x' && p[1][2] == 'x') return'x';
	else if (p[2][0] == 'x' && p[2][1] == 'x' && p[2][2] == 'x') return 'x';
	else if (p[0][0] == 'x' && p[1][0] == 'x' && p[2][0] == 'x') return 'x';
	else if (p[0][1] == 'x' && p[1][1] == 'x' && p[2][1] == 'x') return 'x';
	else if (p[0][2] == 'x' && p[1][2] == 'x' && p[2][2] == 'x') return 'x';
	else if (p[0][0] == 'x' && p[1][1] == 'x' && p[2][2] == 'x') return 'x';
	else if (p[0][2] == 'x' && p[1][1] == 'x' && p[2][0] == 'x') return 'x';
	else if (p[0][0] == 'o' && p[0][1] == 'o' && p[0][2] == 'o') return 'o';
	else if (p[1][0] == 'o' && p[1][1] == 'o' && p[1][2] == 'o') return 'o';
	else if (p[2][0] == 'o' && p[2][1] == 'o' && p[2][2] == 'o') return 'o';
	else if (p[0][0] == 'o' && p[1][0] == 'o' && p[2][0] == 'o') return 'o';
	else if (p[0][1] == 'o' && p[1][1] == 'o' && p[2][1] == 'o') return 'o';
	else if (p[0][2] == 'o' && p[1][2] == 'o' && p[2][2] == 'o') return 'o';
	else if (p[0][0] == 'o' && p[1][1] == 'o' && p[2][2] == 'o') return 'o';
	else if (p[0][2] == 'o' && p[1][1] == 'o' && p[2][0] == 'o') return 'o';
	else if (p[0][0] != ' ' && p[0][1] != ' ' && p[0][2] != ' ' && p[1][0] != ' ' && p[1][1] != ' ' && p[1][2] != ' ' && p[2][0] != ' ' && p[2][1] != ' ' && p[2][2] != ' ') return 5;
	*/
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
	std::cout << "  ";
	for (int i = 0; i < rozmiar; i++) {
		std::cout << '(';
		if (i < 10){
			std::cout << " ";
		}
		std::cout << i << ')';
	}
	std::cout << std::endl;
	for (int i = 0; i < rozmiar; ++i) {
		std::cout << static_cast<char>(i + 'a') << " ";
		for (int j = 0; j < rozmiar; ++j) {

			if (i == x && j == y){

				std::cout << "( "
					<< static_cast<char>(toupper(piesel[i][j]))
					<< ")";

	                                                                                                                                                                                                                         

			}
			else{
				std::cout << "( "
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