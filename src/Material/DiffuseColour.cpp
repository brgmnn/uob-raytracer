#include "DiffuseColour.hpp"
using namespace Graphics;

/*		Constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
DiffuseColour::DiffuseColour() : diffuse_colour(0,100,255) {}
DiffuseColour::DiffuseColour(const Colour &colour) : diffuse_colour(colour) {}
DiffuseColour::DiffuseColour(int red, int green, int blue) : diffuse_colour(red, green, blue) {}
DiffuseColour::~DiffuseColour() {}

/*		Get Colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour DiffuseColour::get_colour(const Vector3 &point, const Vector3 &direction,
	const Vector3 &normal, int depth, bool debug) {
	return diffuse_colour;
}
