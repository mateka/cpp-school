#include <iostream>
#include <vector>
#include <algorithm>

int znajdz(const std::vector<int>& v, const int n);

int main(int argc, char* argv[])
{
	// const std::vector<int> liczby {1, 3, 5, 4, 2, 7, 10, 127, 64, 256};
	std::vector<int> liczby;
	liczby.push_back(1);
	liczby.push_back(3);
	liczby.push_back(5);
	liczby.push_back(4);
	liczby.push_back(2);
	liczby.push_back(7);
	liczby.push_back(10);
	liczby.push_back(127);
	liczby.push_back(64);
	liczby.push_back(256);
	const int szukana = 4;

	auto pos = std::find(liczby.begin(), liczby.end(), szukana);
	if(liczby.end() != pos)
		std::cout << "Znaleziono w a" << (pos-liczby.begin()) << std::endl;
	else
		std::cout << "Nie znaleziono!" << std::endl;

	return 0;
}
