#include <iostream>

#include "Image.h"
#include "PPMImage.h"

int main(int argc, char const *argv[]){
	
	std::string nome = argv[1];

	adrd::PPMImage test(nome);

	std::cin >> test;

	return 0;
}