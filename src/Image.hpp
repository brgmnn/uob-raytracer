#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#include "Light/Colour.hpp"

namespace Graphics {
class Image {
private:
	// Colour* pixels;
	std::vector<Colour> pixels;

	unsigned char* int_to_chararr(unsigned int val);

public:
	Image(int width, int height);
	Image(int width, int height, Colour bg);
	~Image();

	inline Colour& operator() (int x, int y);
	inline Colour  operator() (int x, int y) const;
	
	const int width;
	const int height;

	bool write_to_file(const std::string &path);
};

/*		Image grid
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
inline Colour& Image::operator() (int x, int y) {
	return pixels[x+y*width];
}

inline Colour Image::operator() (int x, int y) const {
	return pixels[x+y*width];
}
}
