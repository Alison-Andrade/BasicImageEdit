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

		//Setters
		void setRed(int red_);
		void setGreen(int green_);
		void setBlue(int blue_);

		//Getters
		int getRed();
		int getGreen();
		int getBlue();

		friend istream& operator>>(istream& in, Pixel& p);
		friend ostream& operator<<(ostream& in, Pixel& p);
	};

	class Image {
	private:

	protected:
		std::string name;
		unsigned largura;
		unsigned altura;
		std::vector<Pixel> data;

		virtual void read(istream& in) = 0;
		virtual void print(ostream& out) = 0;
	public:
		Image();
		Image(std::string name_);
		~Image();

		//Getters
		int getLargura();
		int getAltura();

		friend istream& operator>>(istream& in, Image& i);
		friend ostream& operator<<(ostream& out, Image& i);
	};

} // adrd

#endif