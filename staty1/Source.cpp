#include <iostream>
#include <vector>


int main(){

	int ile;

	std::cin >> ile;

	std::vector<float> liczby;



	for (int dupa = 0; dupa < ile; ++dupa){

		float l;

		std::cin >> l;
		liczby.push_back(l);

	}

	float  lump = 99999;

	float slice = -99999;

	float dice = 0;

	for (int zupa = 0; zupa < ile; ++zupa){
	
	
	
		if (lump>liczby[zupa])

			lump = liczby[zupa];
	
	
	
	}


	for (int pupa = 0; pupa < ile; ++pupa){

	dice = dice + liczby[pupa];

	}

	dice = dice / ile;



	for (int podwieczorek = 0; podwieczorek < ile; ++podwieczorek){

		if (slice<liczby[podwieczorek]){

			slice = liczby[podwieczorek];

		}


	}





	std::cout << "minimum to " << lump << std::endl;
	std::cout << "maximum to " << slice << std::endl;
	std::cout << "srednia to " << dice << std::endl;

}