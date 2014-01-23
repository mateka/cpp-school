#include <iostream>
#include <string>
#include <vector>



float m2(float x);
float oppai(float r, float l);
int piesel_akrobata(int neko);
int baka_inu(int ahou);
float sraka(float a, float b, float c, float d, float e);
float Dubga(float x, float y);
std::string The_Four_Kings(int o);
std::vector <std::string> tfk(int p);
int main() {
	
	
	float a; float b; float c; float d; float e;

		std::cin >> a;
		std::cin >> b;
		std::cin >> c;
		std::cin >> d;
		std::cin >> e;

		std::cout << sraka(a, b, c, d, e) << std::endl;
		std::cout << sraka(a, 2*b, 3*c, d, 10*e) << std::endl;
		std::cout << sraka(144.77*a, b, c,12* d, e) << std::endl;

		float x=5; float y=3;
		
		std::cout << Dubga(x, y) << std::endl;
		std::cout << Dubga(y, x) << std::endl;

		std::cout << "1 = " << The_Four_Kings(1) << std::endl;
		std::cout << "2 = " << The_Four_Kings(2) << std::endl;
		std::cout << "3 = " << The_Four_Kings(3) << std::endl;

		for (std::string e : tfk(4))
			std::cout << e << std::endl;
		
		return 0;
	


}

float m2(float x){

	return 2.0 * x;
}


float oppai(float r, float l){

	float chibi = 3*r+l;

	return chibi;
}


int piesel_akrobata(int neko){

	int r = 1;

	for (int i = 1; i <= neko; ++i) r *= i;
	return r;
} 

int baka_inu(int ahou){

	if (ahou > 1) return ahou*baka_inu(ahou - 1);
	else return 1;

}

float sraka(float a, float b, float c, float d, float e){

	return (a + b + c + d + e) / 5;
}

float Dubga(float x, float y){

	return 2*x + 3*y;

}

std::string The_Four_Kings(int o){

	if (o <= 0) return "malo";
	else if (o == 1) return "1";
	else if (o == 2) return "2";
	else return "duzo";

}

std::vector <std::string> tfk(int p){

	std::vector <std::string> r;
	for (int i = 0; i < p; i++)
		r.push_back(The_Four_Kings(i));

	
	
	
	return r;
}
