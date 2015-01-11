#include "PointLight.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
PointLight::PointLight() : Light(), origin(0,0,10) {}

PointLight::PointLight(const Colour &colour, double intensity, const Vector3 &origin)
	: Light(colour, intensity), origin(origin) {}

PointLight::~PointLight() {}

/*		Get values
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 PointLight::get_direction(const Vector3 &at) const {
	// multiply by -1 because i think the direction of the vector needs to be reversed. as
	// intuitively the light direction we give is the direction the light travels in, but when using
	// it in the cross product what we really want is the direction the light came from.
	return (origin - at).normalised();
}

double PointLight::get_distance(const Vector3 &at) const {
	return (at - origin).length();
}

double PointLight::get_intensity(const Vector3 &at) const {
	return intensity;
}
