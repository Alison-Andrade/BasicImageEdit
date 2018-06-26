#ifndef _BMP_IMAGE_CPP_
#define _BMP_IMAGE_CPP_

#include <fstream>

#include "Image.h"

namespace adrd {

	class BMPImage : public Image {
	private:
		char bfType[2];
		int bfSize;
		short int bfReserved1;
		short int bfReserved2;
		int bfOffBits;

		int biSize;
		long biWidth;
		long biHeight;
		short int biPlanes;
		short int biBitCount;
		int biCompression;
		int biSizeImage;
		long biXPelsPerMeter;
		long biYPelsPerMeter;
		int biClrUsed;
		int biClrImportant;

		void read(std::istream& in);
		void print(std::ostream& out);
	public:
		BMPImage();
		BMPImage(std::string name_);
		~BMPImage();
	};

} // adrd

#endif // _BMP_IMAGE_CPP_

