#pragma once

#include "Material.hpp"

namespace Graphics {
class DiffuseColour: public Material {
private:
public:
	Colour diffuse_colour;
	
	DiffuseColour();
	DiffuseColour(const Colour &colour);
	DiffuseColour(int red, int green, int blue);
	~DiffuseColour();

	Colour get_colour(const Vector3 &point, const Vector3 &direction, const Vector3 &normal,
		int depth, bool debug = false);
};
}
