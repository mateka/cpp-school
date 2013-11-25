#include <iostream>
#include <string> 
#include <tuple>

std::tuple<int,int> wczytaj_liczby();

int main ()
{
	std::string opcja;
	do {
		int a,b;
		std::cout << "wybierz opcje przeliczania" << std::endl;
		std::cout << "dodawanie, odejmowanie, mnozenie czy dzielenie?" << std::endl;
		std::cin >> opcja;
	
		if (opcja=="dodawanie"){
			std::tie(a,b)=wczytaj_liczby();
			std::cout << "wynik dodawania " << a+b << std::endl;

		}
		else if (opcja=="odejmowanie"){
			std::tie(a,b)=wczytaj_liczby();
			std::cout << "wynik odejmowania " << a-b << std::endl;
		}
		else if (opcja=="mnozenie"){
			std::tie(a,b)=wczytaj_liczby();
			std::cout << "wynik mnozenia " << a*b << std::endl;

		}
		else if (opcja=="dzielenie"){
			std::tie(a,b)=wczytaj_liczby();
			std::cout << "wynik dzielenia " << a/b << std::endl;

		}	
		else std::cout << "nieznana opcja" << std::endl;
	} while(opcja!="koniec");



}


std::tuple<int,int> wczytaj_liczby() {
	int a,b;
	std::cout << "podaj pierwsza liczbe" << std::endl;
		std::cin >> a;
		std::cout << "podaj druga liczbe" << std::endl;
		std::cin >> b;
		return std::make_tuple(a,b);
}

