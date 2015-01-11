#pragma once

#include "Material.hpp"
#include "../Light/Ray.hpp"
#include "../Vector3.hpp"

namespace Graphics {
class Lambert: public Material {
private:
public:
	Colour colour;
	double k_ambient;
	double k_diffuse;
	
	Lambert();
	Lambert(const Colour &colour);
	Lambert(int red, int green, int blue);
	~Lambert();

	Colour get_colour(const Vector3 &point, const Vector3 &direction, const Vector3 &normal,
		int depth, bool debug = false);
};
}
