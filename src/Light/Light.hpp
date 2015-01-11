#pragma once
#include <limits>

#include "../Vector3.hpp"
#include "Colour.hpp"

namespace Graphics {
class Light {
private:
protected:
	Colour colour;
	double intensity;
public:
	static const double default_intensity;
	static const int default_k_distribution;

	static const double ambient_intensity;
	static const Colour ambient_colour;

	Light();
	Light(const Colour &colour, double intensity);
	virtual ~Light();

	Colour get_colour() const;
	virtual double get_intensity(const Vector3 &at) const;
	virtual double get_distance(const Vector3 &at) const;
	virtual Vector3 get_direction(const Vector3 &at) const =0;
};
}
