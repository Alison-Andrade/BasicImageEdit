#include <iostream>

#include "Image.h"
#include "PPMImage.h"
#include "BMPImage.h"

void show_help(){

}

int main(int argc, char const *argv[]){
	
	if(argc < 5) {
		show_help();
		exit(1);
	}

	std::string magicNumbers[3] = {"P6", "P3", "BM"};

	int iFlag(0), oFlag(0), eFlag(0), dFlag(0);

	std::string inName(""), outName("");

	for(auto i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg == "-i"){
			iFlag = 1;
			if(i+1 < argc) {
				inName = argv[++i];
			}
		}else if(arg == "-o") {
			oFlag = 1;
			if(i+1 < argc) {
				outName = argv[++i];
			}
		}else if(arg == "-e") {
			eFlag = 1;
		}else if(arg == "-d") {
			dFlag = 1;
		}else{
			std::cerr << "São esperados obrigatoriamente os parametros \'-i \"arquivo de entrada\"\'' e \'-o \"arquivo de saida\"\'" << std::endl;
			exit(1);
		}
	}

	std::ifstream in(inName, std::ios::binary);
	char magicNumber[2];
	in.read(reinterpret_cast<char*>(&magicNumber), sizeof(magicNumber));
	std::cout << magicNumber << std::endl;
	in.close();

	if(magicNumber == magicNumbers[0] || magicNumber == magicNumbers[1]) {
		adrd::PPMImage inImage(inName);
		in >> inImage;
	}else if(magicNumber == magicNumbers[2]) {
		adrd::BMPImage inImage(inName);
		in >> inImage;
	}else {
		std::cerr << "Formato desconhecido." << std::endl;
		exit(1);
	}

	return 0;
}