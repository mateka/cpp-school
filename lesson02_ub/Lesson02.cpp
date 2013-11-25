#include <iostream>

#include "myfunc.h"

// Entry point
int main(int argc, char argv[])
{
	std::cout << "myfunc(10) = " << myfunc(10) << std::endl;
	return 0;
}

// One definition
int myfunc(int param) {
	return param*10;
}
