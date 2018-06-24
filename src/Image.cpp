#include "Image.h"

namespace adrd {

	Pixel::Pixel()
	{}

	Pixel::Pixel(int red_, int green_, int blue_): red(red_), green(green_), blue(blue_)
	{}

	Pixel::~Pixel()
	{}

	void 
	Pixel::setRed(int red_){
		this->red = red_;
	}

	void
	Pixel::setGreen(int green_){
		this->green = green_;
	}

	void 
	Pixel::setBlue(int blue_){
		this->blue =blue_;
	}

	int
	Pixel::getRed(){
		return red;
	}

	int
	Pixel::getGreen(){
		return green;
	}

	int
	Pixel::getBlue(){
		return blue;
	}

	istream& operator>>(istream& in, Pixel& p){
		
		in >> p.red >> p.green >> p.blue;

		return in;
	}

	ostream& operator<<(ostream& out, Pixel& p){

		out << p.red << " " << p.green << " " << p.blue;

		return out;
	}

	Image::Image(){
		name = "";
	}

	Image::Image(std::string name_): name(name_)
	{}

	Image::~Image()
	{}

	istream& operator>>(istream& in, Image& i){
		i.read();

		return in;
	}

	ostream& operator<<(ostream& out, Image& i){
		i.print();

		return out;
	}

} // adrd