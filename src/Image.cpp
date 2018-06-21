#include "Image.h"

namespace adrd {

	Image::Image(){
		name = "";
	}

	Image::Image(std::string name_): name(name_)
	{}

	Image::~Image()
	{}

} // adrd