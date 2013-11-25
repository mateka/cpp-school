#include <iostream>
#include <vector>

// TODO: Zadeklarowac funkcje do wyswietlania planszy.
// Przyjmijmy, ze nie bedzie ona nic zwracac (typ void).
// Jaki typ wybrac by przekazac plansze do funkcji?

int main()
{
	const char puste = ' ';	// puste pole
	// przygotuj plansze i ja zainicjuj
	std::vector<std::vector<char>> piesel; //piesel == plansza
	for (int i = 0; i<3; ++i) {
		piesel.push_back(std::vector<char>(3, puste));
	}

	// Znak gracza
	char znaczek='o';
	// Maksymalnie 9 ruchow
	for(int banan=0;banan<9;++banan)// tu byl nadmiarowy srednik! 
	{
		// wczytaj ruch gracza - wspolrzedne
		// wczytujemy je w nieskonczonosc az:
		// 1. nie sa poprawne
		// 2. trafiaja w zajete pole
		int y = 10;
		int x = 10;
		while(true) {     
			std::cout << "Podaj Wspolrzedne" << std::endl;
			std::cin >> x >> y;

			if (0 <= x && x < 3 && 0 <= y && y < 3) {
				if (puste == piesel[x][y]) break;
			}
		}
		// Ustaw znak gracza i zmien na drugiego
		piesel[x][y] = znaczek;
		if('o'==znaczek)znaczek='x';
		else znaczek='o'; 
		
		// wyswietl plansze
		for(int i=0; i<3; ++i) {
			// Petla po wierszach. Kod jest wykonywany dla kazdego wiersza.
			
			// TODO: Czynnosci wykonywane przed wyswietleniem pol i-tego wiersza

			for (int j = 0; j < 3; ++j) {
				// Petla po kolumnach. Wykonywana dla kazdej kolumny (w kazdym wierszu).

				// TODO: Instrukcje do wykonania przed wyswietlaniem j-tego pola w i-tym wierszu
				
				std::cout << piesel[i][j];	// Wyswietlenie j-tego pola w i-tym wierszu

				// TODO: Instrukcje do wykonania po wyswietleniu j-tego pola w i-tym wierszu

				// Oczywiscie, jesli chcemy kazde pole opakowac znaczkami (np +pole+),
				// to mozemy zrobic to w jednej linijce:
				// std::cout << '+' << piesel[i][j] << '+';
			}

			// TODO: Czynnosci wykonywane po wyswietleniu pol i-tego wiersza.
			// Jedyne, co bylo robione, to przejscie do nowej linii w konsoli.
			std::cout << std::endl;
		}
		// Koniec kodu wyswietlajacego plansze
	}

}

// TODO: Definicja funkcji do wyswietlania planszy.
// Krok 1: Do ciala funkcji (miedzy { i }) wkleic odpowiedni kod z funkcji main
// Krok 2: Zmodyfikowac kod, by wyswietlal ciekawsza plansze