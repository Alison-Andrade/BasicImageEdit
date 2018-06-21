#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <iostream>
#include <vector>
#include <string>

using std::istream;
using std::ostream;

namespace adrd{
	
	class Pixel {
	private:
		int red;
		int green;
		int blue;
	public:
		Pixel();
		Pixel(int red_, int green_, int blue_);
		~Pixel();

		void setRed(int red_);
		void setGreen(int green_);
		void setBlue(int blue_);

		friend istream& operator>>(istream& in, Pixel p);
		friend ostream& operator<<(ostream& in, Pixel p);
	};

	class Image {
	protected:
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

		friend istream& operator>>(istream& in, Image& i);
		friend ostream& operator<<(ostream& out, Image& i);
	};

} // adrd

#endif