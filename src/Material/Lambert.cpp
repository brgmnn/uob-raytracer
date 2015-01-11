#include "Lambert.hpp"
using namespace Graphics;

/*		Constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Lambert::Lambert() : colour(255,255,255), k_ambient(Material::default_k_ambient),
	k_diffuse(Material::default_k_diffuse) {}
Lambert::Lambert(const Colour &colour) : colour(colour), k_ambient(Material::default_k_ambient),
	k_diffuse(Material::default_k_diffuse) {}
Lambert::Lambert(int red, int green, int blue) : colour(red, green, blue),
	k_ambient(Material::default_k_ambient), k_diffuse(Material::default_k_diffuse) {}
Lambert::~Lambert() {}

/*		Get Colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour Lambert::get_colour(const Vector3 &point, const Vector3 &direction, const Vector3 &normal,
		int depth, bool debug) {
	double intensity = Light::ambient_intensity * k_ambient;
	Colour incoming_colour = Light::ambient_colour * intensity;

	for (int i = 0; i < lights->size(); i++) {
		Ray shadow_ray = Ray(point+lights->at(i)->get_direction(point)*Material::shadow_tweak,
			lights->at(i)->get_direction(point));

		if (shadow_ray.clear_path(lights->at(i)->get_distance(point))) {
			intensity = normal.dot(lights->at(i)->get_direction(point))
				/ normal.length()
				/ lights->at(i)->get_direction(point).length()
				* lights->at(i)->get_intensity(point);

			if (intensity > 0.0) {
				incoming_colour += lights->at(i)->get_colour() * intensity * k_diffuse;
			}
		}
	}

	return incoming_colour * colour;
}

