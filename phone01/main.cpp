#include <iostream>
#include <string>
#include <vector>


 
int main(){

	std::string command;

	std::vector <std::string> Imiona;

	std::vector <std::string> Nazwiska;

	std::vector <std::string> Telefony;



	do
	{






		std::cout << "Select one: Add, Show, Quit" << std::endl;

		std::cin >> command;

		if (command == "Add"){
			// add(Imiona, Nazwiska, Telefony);

			std::string Imie, Nazwisko, Telefon;
			std::cout << "Napisz: [Imie] [Nazwisko] [Telefon]" << std::endl;
			std::cin >> Imie >> Nazwisko >> Telefon;
			Imiona.push_back(Imie);
			Nazwiska.push_back(Nazwisko);
			Telefony.push_back(Telefon);
	
		}
		else if (command == "Show"){
			// show(Imiona, Nazwiska, Telefony);
			std::cout << std::endl;
			for (size_t i = 0; i < Imiona.size(); i++)
			{

				std::cout << Imiona[i] << " " << Nazwiska[i] << " " << Telefony[i] << std::endl;
			}
			
			std::cout << std::endl;




		}
		else if (command != "Quit"){
			std::cout << "Nie ma takiej opcji debilu" << std::endl;
		}


	} while (command != "Quit");
	

	






	

}
































