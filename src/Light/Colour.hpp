#pragma once

namespace Graphics {
class Colour {
private:
	unsigned char vred;
	unsigned char vgreen;
	unsigned char vblue;
	unsigned char valpha;

	unsigned char to_byte(double value) const;
public:
	Colour();
	Colour(unsigned char red, unsigned char green, unsigned char blue);
	Colour(int           red, int           green, int           blue);
	Colour(double        red, double        green, double        blue);
	~Colour();

	int red();
	int green();
	int blue();

	void red(int value);
	void green(int value);
	void blue(int value);

	// overloaded operators for scalar values
	Colour operator* (double rhs) const;
	Colour operator/ (double rhs) const;

	// overloaded operators for colour-colour operations
	Colour operator+ (const Colour &rhs) const;
	Colour operator- (const Colour &rhs) const;
	Colour operator* (const Colour &rhs) const;
	Colour operator/ (const Colour &rhs) const;

	Colour& operator+= (const Colour &rhs);
};
}
