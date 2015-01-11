#include "DirectionalLight.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
DirectionalLight::DirectionalLight() : Light(), direction(0,0,-1) {}

DirectionalLight::DirectionalLight(const Colour &colour, double intensity, const Vector3 &direction)
	: Light(colour, intensity), direction(direction.normalised()) {}

DirectionalLight::~DirectionalLight() {}

/*		Get values
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 DirectionalLight::get_direction(const Vector3 &at) const {
	// multiply by -1 because i think the direction of the vector needs to be reversed. as
	// intuitively the light direction we give is the direction the light travels in, but when using
	// it in the cross product what we really want is the direction the light came from.
	return direction * -1;
}
