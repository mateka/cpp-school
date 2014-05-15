#include <iostream>
#include <map>
#include <string>


int main() {
	std::map<float, std::string> ok = {
		{ 0.0f, "Zero" },
		{ 1.0f, "Jeden" },
		{ 2.0f,  "Dwa" }
	};

    float n;

	while (std::cin >> n)
	{
		auto pos = ok.find(n);
		if (std::end(ok)==pos ){
			std::cout << "nie kce mi sie" << std::endl;
		}
		else {
			std::cout << n << " Czyta Sie " << ok[n] << std::endl;
		}
	}
}