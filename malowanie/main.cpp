#include <iostream>
#include <vector>


typedef std::vector<std::vector<char>> typ_piesela;
void skowron(typ_piesela&, int x, int y, char zn);
void kisiel(const typ_piesela&);
void piesel_akrobata(typ_piesela&budyn, int x, int y, int a, char zn);
int main()

{






	typ_piesela ekran(20, std::vector<char>(60, ' '));


	piesel_akrobata(ekran, 0, 9, 10, 'x');

	kisiel(ekran);

















}




void kisiel(const typ_piesela&budyn){

	for (const auto& koteu : budyn){
		for (const auto& szkare : koteu) //auto = wylicz automatycznie typ
			std::cout << szkare;
		std::cout << std::endl;
	}

	
}

void skowron(typ_piesela&budyn, int x, int y, char zn){

	if (y > -1 && y < budyn.size()){
	
		if (x > -1 && x < budyn[y].size()){

			budyn[y][x] = zn;
		}
	
	}

}

void piesel_akrobata(typ_piesela&budyn, int x, int y, int a, char zn){


	for (int papaja = x; papaja < x + a; ++papaja){
		for (int agrest = y; agrest < y + a; ++agrest)
			skowron(budyn, papaja, agrest, zn);
	}




}