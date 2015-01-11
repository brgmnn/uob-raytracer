#pragma once
#include <cmath>

#include "Material.hpp"
#include "../Vector3.hpp"
#include "../Light/Ray.hpp"

namespace Graphics {
class Specular: public Material {
private:
	void init_ks();
public:
	Colour colour;
	double k_ambient;
	double k_diffuse;
	double k_specular;
	double k_reflective;
	double k_distribution;

	Specular();
	Specular(const Colour &colour);
	Specular(int red, int green, int blue);
	~Specular();

	Colour get_colour(const Vector3 &point, const Vector3 &direction, const Vector3 &normal,
		int depth, bool debug = false);
};
}
