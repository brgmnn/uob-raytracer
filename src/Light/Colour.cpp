#include "Colour.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour::Colour() {
	vred = 0;
	vgreen = 0;
	vblue = 0;
}

Colour::Colour(unsigned char red, unsigned char green, unsigned char blue) {
	vred = red;
	vgreen = green;
	vblue = blue;
}

Colour::Colour(int red, int green, int blue) {
	vred = to_byte(red);
	vgreen = to_byte(green);
	vblue = to_byte(blue);
}

Colour::Colour(double red, double green, double blue) {
	vred = to_byte(red);
	vgreen = to_byte(green);
	vblue = to_byte(blue);
}

Colour::~Colour() {}

/*		Overloaded operators - colour to scalar
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour Colour::operator* (double rhs) const {
	return Colour(vred*rhs, vgreen*rhs, vblue*rhs);
}

Colour Colour::operator/ (double rhs) const {
	return Colour(vred/rhs, vgreen/rhs, vblue/rhs);
}

/*		Overloaded operators - colour to colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour Colour::operator+ (const Colour &rhs) const {
	return Colour((int)vred+rhs.vred, (int)vgreen+rhs.vgreen, (int)vblue+rhs.vblue);
}

Colour Colour::operator- (const Colour &rhs) const {
	return Colour((int)vred-rhs.vred, (int)vgreen-rhs.vgreen, (int)vblue-rhs.vblue);
}

Colour Colour::operator* (const Colour &rhs) const {
	return Colour(to_byte(vred*((double)rhs.vred/255)),
		to_byte(vgreen*((double)rhs.vgreen/255)),
		to_byte(vblue*((double)rhs.vblue/255)));
}

Colour Colour::operator/ (const Colour &rhs) const {
	return Colour(to_byte(vred/((double)rhs.vred/255)),
		to_byte(vgreen/((double)rhs.vgreen/255)),
		to_byte(vblue/((double)rhs.vblue/255)));
}

Colour& Colour::operator+= (const Colour &rhs) {
	int nred, ngreen, nblue;
	nred = (int)vred + rhs.vred;
	ngreen = (int)vgreen + rhs.vgreen;
	nblue = (int)vblue + rhs.vblue;

	vred = to_byte(nred);
	vgreen = to_byte(ngreen);
	vblue = to_byte(nblue);
	return *this;
}

/*		Setters and getters
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int Colour::red() {
	return vred;
}

int Colour::green() {
	return vgreen;
}

int Colour::blue() {
	return vblue;
}

void Colour::red(int value) {
	vred = value;
}

void Colour::green(int value) {
	vgreen = value;
}

void Colour::blue(int value) {
	vblue = value;
}

unsigned char Colour::to_byte(double value) const {
	if (value > 255.0)
		return 255;
	else if (value < 0.0)
		return 0;
	else
		return value;
}
