#pragma once

#include "../Vector3.hpp"
#include "Colour.hpp"
#include "Light.hpp"

namespace Graphics {
class SpotLight : public Light {
private:
	Vector3 origin;
	Vector3 direction;
	int k_distribution;
public:
	SpotLight();
	SpotLight(const Colour &colour, double intensity, const Vector3 &origin,
		const Vector3 &direction);
	SpotLight(const Colour &colour, double intensity, const Vector3 &origin,
		const Vector3 &direction, int distribution);
	~SpotLight();

	Vector3 get_direction(const Vector3 &at) const;
	double get_distance(const Vector3 &at) const;
	double get_intensity(const Vector3 &at) const;
};
}
