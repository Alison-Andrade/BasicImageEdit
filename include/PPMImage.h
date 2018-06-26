#ifndef PPM_IMAGE_H
#define PPM_IMAGE_H

#include <fstream>

#include "Image.h"

namespace adrd {

	class PPMImage : public Image {
	private:
		char type[2];
		int max;

		void read(std::istream& in);
		void print(std::ostream& out);
	public:
		PPMImage();
		PPMImage(std::string name_);
		~PPMImage();
	};

} // adrd

#endif // PPM_IMAGE_H
