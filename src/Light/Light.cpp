#include "Light.hpp"
using namespace Graphics;

const double Light::default_intensity = 0.7;
const int Light::default_k_distribution = 1;

const double Light::ambient_intensity = 0.1;
const Colour Light::ambient_colour = Colour(255,255,255);

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Light::Light() : colour(255,255,255), intensity(Light::default_intensity) {}
Light::Light(const Colour &colour, double intensity) : colour(colour), intensity(intensity) {}
Light::~Light() {}

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour Light::get_colour() const {
	return colour;
}

double Light::get_distance(const Vector3 &at) const {
	return std::numeric_limits<double>::infinity();
}

double Light::get_intensity(const Vector3 &at) const {
	return intensity;
}
