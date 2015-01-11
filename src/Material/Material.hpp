#pragma once
#include <vector>

#include "../Light/Colour.hpp"
#include "../Light/Light.hpp"

namespace Graphics {
class Object;

class Material {
private:
protected:
	static std::vector<Light*> *lights;
	Object *parent_obj;
public:
	// public constants for materials
	static const double shadow_tweak;

	// default values for ks used in materials. see material.cpp for their values
	static const double default_k_ambient;
	static const double default_k_diffuse;
	static const double default_k_specular;
	static const double default_k_reflective;
	static const double default_k_distribution;

	Material();
	virtual ~Material();

	virtual Colour get_colour(const Vector3 &point, const Vector3 &direction,
		const Vector3 &normal, int depth, bool debug = false) =0;

	// assign the lights so they can be used in colour calculations
	static void link_lights(std::vector<Light*> *lights);
	void link_obj(Object *obj);
};
}
