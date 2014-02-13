#include <iostream>
#include <string>
#include <vector>

struct Osoba {
	std::string imie;
	std::string nazwisko;
	std::string telefon;
};
typedef std::vector<Osoba> Adresownik;


void add(Adresownik& adresy, Osoba nowy);
void show(Adresownik& adresy);
void wohs(Adresownik& adresy);
std::string find(Adresownik& adresy, std::string Imie, std::string Nazwisko);

int main(){

	std::string command;

	Adresownik adresy;

	

	do
	{






		std::cout << "Select one: Add, Show, Find, Quit" << std::endl;

		std::cin >> command;

		if (command == "Add"){
			Osoba osobka;
			std::cout << "Napisz: [Imie] [Nazwisko] [Telefon]" << std::endl;
			std::cin >> osobka.imie >> osobka.nazwisko >> osobka.telefon;
			 add(adresy, osobka);	
		}
		else if (command == "Show"){
				show(adresy);	
		}
		else if (command == "Wohs"){
			wohs(adresy);
		}
		else if (command == "Find"){
			std::string Imie, Nazwisko;
			std::cout << "Napisz: [Imie] [Nazwisko]" << std::endl;
			std::cin >> Imie >> Nazwisko;
			std::cout << "Telefon: " << find(adresy, Imie, Nazwisko) << std::endl;
		}
		else if (command != "Quit"){
			std::cout << "Nie ma takiej opcji debilu" << std::endl;
		}
	} while (command != "Quit");
	

	






	

}



void add(Adresownik& adresy, Osoba o){
	adresy.push_back(o);
}

void wohs(Adresownik& adresy){
	std::cout << std::endl;
	for (size_t i = adresy.size(); i > 0; i--)
	{
		std::cout << adresy[i-1].imie << " " << adresy[i-1].nazwisko << " " << adresy[i-1].telefon << std::endl;
	}
	std::cout << std::endl;
}
void show(Adresownik& adresy){
	std::cout << std::endl;
	for (size_t i = 0; i < adresy.size(); i++)
	{
		std::cout << adresy[i].imie << " " << adresy[i].nazwisko << " " << adresy[i].telefon << std::endl;
	}
	std::cout << std::endl;
}

std::string find(Adresownik& adresy, std::string Imie, std::string Nazwisko){

	std::string res = "Nie znaleziono";
	for (size_t i = 0; i < adresy.size(); i++){
		if (Imie == adresy[i].imie && Nazwisko == adresy[i].nazwisko){
			res = adresy[i].telefon;
			break;
		}
	}
	return res;
}





















