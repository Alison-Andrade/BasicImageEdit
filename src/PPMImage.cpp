#include "PPMImage.h"

namespace adrd {

	PPMImage::PPMImage(): Image()
	{}

	PPMImage::PPMImage(std::string name_): Image(name_)
	{}

	PPMImage::~PPMImage()
	{}

	void
	PPMImage::read(){
		std::ifstream in;

		if(!in.open(this->name)) {
			std::cerr << "Erro: arquivo não pode ser aberto." << std::endl;
			exit(1);
		}

		in >> this->type;
		in >> this->largura;
		in >> this->altura;
		in >> this->max;

		while(!in.eof()){

			int* buffer = new int;

			Pixel* p = new Pixel(in.read(buffer, sizeof(int)), in.read(buffer, sizeof(int)), in.read(buffer, sizeof(int)));

			this->data.push_back(p);
		}

	}

	void
	PPMImage::print(){

	}

} // adrd