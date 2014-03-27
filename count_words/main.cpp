#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

typedef std::map<std::string, int> slownik;


std::istream& operator>>(std::istream& is, slownik& slowa);
std::vector<std::string> podziel(std::string slowo);

std::ostream&operator  << (std::ostream&o, const slownik&s);

int main(int argc, char* argv[]) {
	slownik slowole;
	if (2 <= argc) {
		std::ifstream plik(argv[1]);
		plik >> slowole;
		if (3 <= argc){
			std::ofstream wyplik(argv[2]);
			wyplik << slowole;
		}
	}
	else {
		std::cin >> slowole;
	}

	// cdn
	//for (auto& p : slowole)
	//	std::cout << p.first << " : " << p.second << std::endl;
	
	std::string command;

	do
	{

		std::cout << "Select one: Find, Quit" << std::endl;

		std::cin >> command;

		if (command == "Find"){
			std::string slowo;
			std::cout << "Napisz: [slowo]" << std::endl;
			std::cin >> slowo;

			auto it = slowole.find(slowo);
			if (it != std::end(slowole)) {
				int ile = it->second;
				if (ile < 2){
					std::cout << slowo << " bylo raz" << std::endl;
				}
				else
				{
					std::cout << slowo << " bylo " << ile << " razy" << std::endl;
				}
			}
			else {
				std::cout << "Nie bylo takiego wyrazu ;(" << std::endl;
			}
		}
		else if (command != "Quit"){
			std::cout << "Nie ma takiej opcji debilu" << std::endl;
		}
	} while (command != "Quit");
}

std::istream& operator>>(std::istream& is, slownik& slowa) {
	std::string word;
	while (is >> word) {
		for (auto& w : podziel(word))
			++slowa[w];
	}
	return is;
}

std::vector<std::string> podziel(std::string slowo) {
	std::vector<std::string> result;
	for (std::string::size_type i = 0; i != std::string::npos;) {
		std::string::size_type j = slowo.find_first_of("`~!@#$%^&*()_+=-0987654321|\\,./?><;'\\|\":[]{}", i);

		if (std::string::npos != j) {
			std::string::size_type ile = j - i;

			result.push_back(slowo.substr(i, ile));
			i = j + 1;
		}
		else {
			if (!slowo.substr(i).empty()) result.push_back(slowo.substr(i));
			break;
		}
	}
	return result;
}

std::ostream&operator  << (std::ostream&o, const slownik&s) {
	for (auto e : s) o << e.first << " " << e.second << std::endl;
	return o;
}




















