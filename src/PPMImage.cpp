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

		in.open(this->name);

		if(!in.is_open()) {
			std::cerr << "Erro: arquivo não pode ser aberto." << std::endl;
			exit(1);
		}

		in >> this->type;
		in >> this->largura;
		in >> this->altura;
		in >> this->max;

		while(!in.eof()){

			int red_, green_, blue_;

			in >> red_;
			in >> green_;
			in >> blue_;

			Pixel p(red_, green_, blue_);

			this->data.push_back(p);
		}

		for (auto i = this->data.begin(); i < this->data.end(); i++){
			std::cout << i->red << std::endl;
			std::cout << i->green << std::endl;
			std::cout << i->blue << std::endl;
		}

		in.close();

	}

	void
	PPMImage::print(){

	}

} // adrd