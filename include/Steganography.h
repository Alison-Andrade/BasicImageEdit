#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include "Image.h"
#include "PPMImage.h"
#include "BMPImage.h"

namespace adrd {

	class Steg {
	private:

		std::shared_ptr<Image> im;
		
		void encode();
		void decode();
	public:
		Steg() = default;

		void operator()(Image im, char flag[2]);
	};

} // adrd

#endif // STEGANOGRAPHY_H
