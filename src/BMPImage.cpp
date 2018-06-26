#include "BMPImage.h"

namespace adrd {

	BMPImage::BMPImage(): Image()
	{}

	BMPImage::BMPImage(std::string name_): Image(name_)
	{}

	BMPImage::~BMPImage()
	{}

	void
	BMPImage::read(std::istream& in){

		in.read(reinterpret_cast<char *>(&this->bfType), sizeof(this->bfType));
		in.read(reinterpret_cast<char *>(&this->bfSize), sizeof(this->bfSize));
		in.read(reinterpret_cast<char *>(&this->bfReserved1), sizeof(this->bfReserved1));
		in.read(reinterpret_cast<char *>(&this->bfReserved2), sizeof(this->bfReserved2));
		in.read(reinterpret_cast<char *>(&this->bfOffBits), sizeof(this->bfOffBits));

		in.read(reinterpret_cast<char *>(&this->biSize), sizeof(this->biSize));
		in.read(reinterpret_cast<char *>(&this->biWidth), sizeof(this->biWidth));
		in.read(reinterpret_cast<char *>(&this->biHeight), sizeof(this->biHeight));
		in.read(reinterpret_cast<char *>(&this->biPlanes), sizeof(this->biPlanes));
		in.read(reinterpret_cast<char *>(&this->biBitCount), sizeof(this->biBitCount));
		in.read(reinterpret_cast<char *>(&this->biCompression), sizeof(this->biCompression));
		in.read(reinterpret_cast<char *>(&this->biSizeImage), sizeof(this->biSizeImage));
		in.read(reinterpret_cast<char *>(&this->biXPelsPerMeter), sizeof(this->biXPelsPerMeter));
		in.read(reinterpret_cast<char *>(&this->biYPelsPerMeter), sizeof(this->biYPelsPerMeter));
		in.read(reinterpret_cast<char *>(&this->biClrUsed), sizeof(this->biClrUsed));
		in.read(reinterpret_cast<char *>(&this->biClrImportant), sizeof(this->biClrImportant));

		while(!in.eof()){

			Pixel p;

			in >> p;

			this->data.push_back(p);
		}
	}

	void
	BMPImage::print(std::ostream& out){
		out.write(reinterpret_cast<char *>(&this->bfType), sizeof(this->bfType));
		out.write(reinterpret_cast<char *>(&this->bfSize), sizeof(this->bfSize));
		out.write(reinterpret_cast<char *>(&this->bfReserved1), sizeof(this->bfReserved1));
		out.write(reinterpret_cast<char *>(&this->bfReserved2), sizeof(this->bfReserved2));
		out.write(reinterpret_cast<char *>(&this->bfOffBits), sizeof(this->bfOffBits));

		out.write(reinterpret_cast<char *>(&this->biSize), sizeof(this->biSize));
		out.write(reinterpret_cast<char *>(&this->biWidth), sizeof(this->biWidth));
		out.write(reinterpret_cast<char *>(&this->biHeight), sizeof(this->biHeight));
		out.write(reinterpret_cast<char *>(&this->biPlanes), sizeof(this->biPlanes));
		out.write(reinterpret_cast<char *>(&this->biBitCount), sizeof(this->biBitCount));
		out.write(reinterpret_cast<char *>(&this->biCompression), sizeof(this->biCompression));
		out.write(reinterpret_cast<char *>(&this->biSizeImage), sizeof(this->biSizeImage));
		out.write(reinterpret_cast<char *>(&this->biXPelsPerMeter), sizeof(this->biXPelsPerMeter));
		out.write(reinterpret_cast<char *>(&this->biYPelsPerMeter), sizeof(this->biYPelsPerMeter));
		out.write(reinterpret_cast<char *>(&this->biClrUsed), sizeof(this->biClrUsed));
		out.write(reinterpret_cast<char *>(&this->biClrImportant), sizeof(this->biClrImportant));


		for (auto i = this->data.begin(); i < this->data.end(); i++){
			out << *i;
		}
	}

} // adrd