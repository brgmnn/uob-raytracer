#include "SpotLight.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
SpotLight::SpotLight() : Light(), origin(0,0,10) {}

SpotLight::SpotLight(const Colour &colour, double intensity, const Vector3 &origin,
	const Vector3 &direction)
	: Light(colour, intensity), origin(origin), direction(direction.normalised()),
	k_distribution(Light::default_k_distribution) {}

SpotLight::SpotLight(const Colour &colour, double intensity, const Vector3 &origin,
	const Vector3 &direction, int distribution)
	: Light(colour, intensity), origin(origin), direction(direction.normalised()),
	k_distribution(distribution) {}

SpotLight::~SpotLight() {}

/*		Get values
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 SpotLight::get_direction(const Vector3 &at) const {
	// multiply by -1 because i think the direction of the vector needs to be reversed. as
	// intuitively the light direction we give is the direction the light travels in, but when using
	// it in the cross product what we really want is the direction the light came from.
	return (origin - at).normalised();
}

double SpotLight::get_distance(const Vector3 &at) const {
	return (at - origin).length();
}

// modify the spot lights dot distribution
double SpotLight::get_intensity(const Vector3 &at) const {
	double dot = direction.dot((at - origin).normalised());

	if (dot < 0.0) {
		return 0.0;
	} else {
		return intensity * pow(dot, k_distribution);
	}
}
