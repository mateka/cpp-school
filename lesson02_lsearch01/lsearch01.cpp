// Od # zaczynaja sie dyrektywy preprocesora.
// include <NAZWA> oznacza: wlacz plik naglowkowy NAZWA
// Pliki bibliotek wlaczamy za pomoca <>.
// Pliki napisane przez nas i bedace czescia projektu,
// wlaczamy za pomoca "".
// Plik iostream zawiera klasy strumieni wyjscia i wejscia.
// Obiekt cout pozwala na wyswietlanie tekstu w konsoli.
#include <iostream>

/* Funkcja main jest specjalna funkcja. Wywoluje ja system
   operacyjny, gdy uruchamiamy program.
   int na poczatku oznacza zwracany typ: liczby calkowite.
   Konwencja jest taka, ze zwracamy 0 gdy program zakonczyl sie normalnie
   i wartosc rozna od 0, gdy wystapil blad.
   W nawiasach sa parametry fukncji. W przypadku funkcji main,
   sa to: ilosc argumentow i tablica argumentow z konsoli.
  Chwilowo nie bedziemy dokladnie wnikac w ich typy i znaczenie. */
int main(int argc, char* argv[])
{
	// Deklarujemy zmienna. Modyfikator const oznacza, ze nie bedziemy
	// jej modyfikowac.
	const int n = 4;	// szukana liczba

	const int a0 = 1, a1 = 3, a2 = 5, a3 = 4, a4 = 2, a5 = 7, a6 = 10, a7 = 127, a8 = 64, a9 = 256;

	// Sprawdzamy, czy istnieje jakas zmiena a<numerek>, ze a<numerek> = n.
	// Jesli istnieje, to numerek laduje w zmiennej pos.
	int pos = -1;	// -1 oznacza: nie znaleziono
	if(n == a0) pos = 0;
	else if(n == a1) pos = 1;
	else if(n == a2) pos = 2;
	else if(n == a3) pos = 3;
	else if(n == a4) pos = 4;
	else if(n == a5) pos = 5;
	else if(n == a6) pos = 6;
	else if(n == a7) pos = 7;
	else if(n == a8) pos = 8;
	else if(n == a9) pos = 9;

	// Sprawdzamy, czy znaleziono n. Jesli tak, to wswietlamy
	// odpowiedni komunikat.
	// Jesli nie, to wyswietlamy inny.
	if(-1 != pos)
		std::cout << "Znaleziono w a" << pos << std::endl;
	else
		std::cout << "Nie znaleziono!" << std::endl;
	
	// Program zakoczyl sie poprawnie.
	return 0;
}

