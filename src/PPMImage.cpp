#include "PPMImage.h"

namespace adrd {

	PPMImage::PPMImage(): Image()
	{}

	PPMImage::PPMImage(std::string name_): Image(name_)
	{}

	PPMImage::~PPMImage()
	{}

	void
	PPMImage::read(std::istream& in){
		
		in >> this->type;
		in >> this->largura;
		in >> this->altura;
		in >> this->max;

		while(!in.eof()){

			Pixel p;

			in >> p;

			this->data.push_back(p);
		}

	}

	void
	PPMImage::print(std::ostream& out){
		out << this->type << std:: endl;
		out << this->largura << " " << this->altura << std::endl;
		out << this->max;

		for (auto i = this->data.begin(); i < this->data.end(); i++){
			out << *i;
		}
	}

} // adrd