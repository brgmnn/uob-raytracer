#pragma once

#include "../Vector3.hpp"
#include "Colour.hpp"
#include "Light.hpp"

namespace Graphics {
class PointLight : public Light {
private:
	Vector3 origin;
public:
	using Light::get_intensity;
	using Light::get_direction;

	PointLight();
	PointLight(const Colour &colour, double intensity, const Vector3 &origin);
	~PointLight();

	Vector3 get_direction(const Vector3 &at) const;
	double get_intensity(const Vector3 &at) const;
	double get_distance(const Vector3 &at) const;
};
}
