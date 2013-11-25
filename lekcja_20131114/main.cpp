#include <iostream>
#include <string>



int main()

{
	std::cout << "Podaj Imie" << std::endl;
	std::string imie;
   
	std::cin >> imie;
	
	
	std::cout << "Podaj Jaki Mamy Teraz Rok" << std::endl;

	int rok2;
	std::cin >> rok2;

	std::cout << "Podaj Rok Urodzenia" << std::endl;

	int rok;
    std::cin >> rok; 
	
	
	
	std::cout << "Twoje Imie I Wiek To" << std::endl;
	std::cout << imie <<" "<< rok2-rok << std::endl;
	










}




