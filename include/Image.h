#include <iostream>
#include <vector>

namepace adrd{
	
	class Pixel {
	private:
		int red;
		int green;
		int blue;
	public:
		Pixel();
		~Pixel();

		friend istream& operator>>(istream& in, Pixel p);
		friend ostream& operator<<(ostream& in, Pixel p);
	};

	class Image {
	private:
		unsigned largura;
		unsigned altura;
		std::vector<Pixel> data;
	public:
		Image();
		~Image();

		friend istream& operator>>(istream& in, Image i);
		friend ostream& operator<<(ostream& in, Image i);
	};

}