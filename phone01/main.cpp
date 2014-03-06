#include <iostream>
#include <string>
#include <vector>
#include <fstream>

struct Osoba {
	std::string imie;
	std::string nazwisko;
	std::string telefon;
};
std::ostream& operator<<(std::ostream& os, const Osoba& o);
std::istream& operator>>(std::istream& is, Osoba& o);

typedef std::vector<Osoba> Adresownik;
std::ostream& operator<<(std::ostream& os, const Adresownik& o);
std::istream& operator>>(std::istream& is, Adresownik& o);


void add(Adresownik& adresy, Osoba nowy);
void show(Adresownik& adresy);
void wohs(Adresownik& adresy);
std::string find(Adresownik& adresy, std::string Imie, std::string Nazwisko);

void Save(Adresownik& adresy, std::string NPC);
void Load(Adresownik& adresy, std::string NPC);

int main(){

	std::string command;

	Adresownik adresy;

	

	do
	{






		std::cout << "Select one: Add, Show, Find, Quit, Save, Load" << std::endl;

		std::cin >> command;

		if (command == "Add"){
			Osoba osobka;
			std::cout << "Napisz: [Imie] [Nazwisko] [Telefon]" << std::endl;
			std::cin >> osobka;
			 add(adresy, osobka);	
		}
		else if (command == "Show"){
				show(adresy);	
		}
		else if (command == "Wohs"){
			wohs(adresy);
		}
		else if (command == "Save"){
			std::string NPC;
			std::cout << "Podaj nazwe pliku... debilu" << std::endl;
			std::cin >> NPC;
			Save(adresy, NPC);
		}
		else if (command == "Load"){
			std::string NPC;
			std::cout << "Podaj nazwe pliku... debilu" << std::endl;
			std::cin >> NPC;
			Load(adresy, NPC);
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


std::ostream& operator<<(std::ostream& os, const Osoba& o) {
	os << o.imie << " " << o.nazwisko << " " << o.telefon;
	return os;
}
std::istream& operator>>(std::istream& is, Osoba& o){
	is >> o.imie >> o.nazwisko >> o.telefon;
	return is;
}




std::ostream& operator<<(std::ostream& os, const Adresownik& o){
	
	for (size_t i = 0; i < o.size(); ++i){
		os << o[i] << std::endl;
	}
	
	return os;
}
std::istream& operator>>(std::istream& is, Adresownik& o) {
	Osoba osobka;
	while (is >> osobka) add(o, osobka);
	return is;
}

void add(Adresownik& adresy, Osoba o){
	adresy.push_back(o);
}

void wohs(Adresownik& adresy){
	std::cout << std::endl;
	for (size_t i = adresy.size(); i > 0; i--)
	{
		std::cout << adresy[i-1] << std::endl;
	}
	std::cout << std::endl;
}
void show(Adresownik& adresy){
	std::cout << std::endl;
	std::cout << adresy;
	std::cout << std::endl;
}

void Save(Adresownik& adresy, std::string NPC){
	std::ofstream plik(NPC);
	plik << adresy;
}
void Load(Adresownik& adresy, std::string NPC){
	std::ifstream plik(NPC);
	plik >> adresy;
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





















