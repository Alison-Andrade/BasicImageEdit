#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include <vector>
#include <string>

namespace adrd{
	
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
		std::string name;
		unsigned largura;
		unsigned altura;
		std::vector<Pixel> data;
	public:
		Image();
		Image(std::string name_);
		~Image();

		virtual void read() = 0;
		virtual void print() = 0;

		friend istream& operator>>(istream& in, Image i);
		friend ostream& operator<<(ostream& in, Image i);
	};

} // adrd

#endif