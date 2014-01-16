#include <iostream>


float m2(float x);
float oppai(float r, float l);
int piesel_akrobata(int neko);
int baka_inu(int ahou);
int main() {
	float x = 1;
	float y = 2;
	
	{

		float x = 0.2;
		float z = oppai(1, m2(x + y));
		std::cout << z << std::endl;
		z += 0.5;
		x += z;


	}

	std::cout << x << std::endl;
	std::cout << piesel_akrobata(6) << std::endl;
	std::cout << baka_inu(6) << std::endl;
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









