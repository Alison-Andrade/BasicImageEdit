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

			//int red_, green_, blue_;

			Pixel p;

			in >> p;

			this->data.push_back(p);
		}

		in.close();

	}

	void
	PPMImage::print(){
		std::ofstream out;

		out.open("out.ppm");

		if(!out.is_open()) {
			std::cerr << "Erro: arquivo não pode ser aberto." << std::endl;
			exit(1);
		}

		out << this->type << std:: endl;
		out << this->largura << " " << this->altura << std::endl;
		out << this->max << std::endl;

		for (auto i = this->data.begin(); i < this->data.end(); i++){
			out << *i << std::endl;
		}
	}

} // adrd