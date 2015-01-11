#include "Image.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Image::Image(int width, int height) : pixels(width*height), width(width), height(height) {}

Image::Image(int width, int height, Colour bg) : pixels(width*height, bg), width(width),
	height(height)  {}

Image::~Image() {}

/*		Write to file
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool Image::write_to_file(const std::string &path) {
	std::ofstream file;
	char* colour_block = new char[3]();
	char* header = new char[56]();
	unsigned char* tmp;

	//		begin boring BMP header information
	// bmp magic number
	header[0] = 'B';
	header[1] = 'M';

	// file size (including full header)
	memcpy(&header[2], (tmp = int_to_chararr(55+(3*width*height))), 4);
	memcpy(&header[34], tmp, 4);
	delete[] tmp;

	// start of pixel grid data
	memcpy(&header[10], (tmp = int_to_chararr(56)), 4);
	delete[] tmp;

	// DIB header size - 15.
	memcpy(&header[14], (tmp = int_to_chararr(40)), 4);
	delete[] tmp;

	// image width
	memcpy(&header[18], (tmp = int_to_chararr(width)), 4);
	delete[] tmp;

	// image height
	memcpy(&header[22], (tmp = int_to_chararr(height)), 4);
	delete[] tmp;

	header[26] = 1;
	header[28] = 24;

	// resolution
	memcpy(&header[42], (tmp = int_to_chararr(2835)), 4);
	memcpy(&header[46], tmp, 4);
	delete[] tmp;

	int file_length = 56;
	char* pad = new char[1]();

	file.open(path, std::ios::out | std::ios::binary);
	file.write(header, 56);

	for (int j = height-1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			Colour px = (*this)(i, j);

			colour_block[0] = px.blue();
			colour_block[1] = px.green();
			colour_block[2] = px.red();

			file.write(colour_block, 3);
		}

		file_length += 3*width;
		while (file_length%4) {
			file.write(pad, 1);
			file_length++;
		}
	}

	file.close();
	delete[] tmp;

	return true;
}

/*		Conversion functions for file writing
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
unsigned char* Image::int_to_chararr(unsigned int val) {
	unsigned char* arr = new unsigned char[4];
	unsigned int mask = 0xFF;
	
	for (int i = 0; i < 4; i++) {
		arr[i] = (unsigned char)(val & mask);
		val = val >> 8;
	}
	
	return arr;
}
