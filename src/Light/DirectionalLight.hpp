#pragma once

#include "../Vector3.hpp"
#include "Colour.hpp"
#include "Light.hpp"

namespace Graphics {
class DirectionalLight : public Light {
private:
	Vector3 direction;
public:
	DirectionalLight();
	DirectionalLight(const Colour &colour, double intensity, const Vector3 &direction);
	~DirectionalLight();

	Vector3 get_direction(const Vector3 &at) const;
};
}
