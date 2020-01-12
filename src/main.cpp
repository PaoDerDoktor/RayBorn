#include <iostream>

#include "../include/Vector.hpp"

int main(int argc, char *argv[]) {
	Vector t(1, 2, 3);
	Vector u(3, 2, 1);

	Vector v = t+u;

	std::cout << t << std::endl;
	std::cout << t[0] << std::endl;
	std::cout << v << std::endl;

	std::cin.get();
}