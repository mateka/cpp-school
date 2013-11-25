#include <iostream>
#include <vector>

int znajdz(const std::vector<int>& v, const int n);

int main(int argc, char* argv[])
{
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

	const int pos = znajdz(liczby, szukana);
	if(-1 != pos)
		std::cout << "Znaleziono w a" << pos << std::endl;
	else
		std::cout << "Nie znaleziono!" << std::endl;

	return 0;
}


int znajdz(const std::vector<int>& v, const int n)
{
	for(int i=0; i<v.size(); ++i)
		if(n == v[i]) return i;

	return -1;
}
