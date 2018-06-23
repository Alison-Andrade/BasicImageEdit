#include "Image.h"

namespace adrd {

	class Filter {
	private:
		
	public:
		Filter();
		~Filter();

		virtual static void operator()() = 0;
	};

} // adrd