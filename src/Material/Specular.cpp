#include "Specular.hpp"
using namespace Graphics;

/*		Constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Specular::Specular() : colour(255,255,255), k_ambient(Material::default_k_ambient),
	k_diffuse(Material::default_k_diffuse), k_specular(Material::default_k_specular),
	k_reflective(Material::default_k_reflective),
	k_distribution(Material::default_k_distribution) {}

Specular::Specular(const Colour &colour) : colour(colour), k_ambient(Material::default_k_ambient),
	k_diffuse(Material::default_k_diffuse), k_specular(Material::default_k_specular),
	k_reflective(Material::default_k_reflective),
	k_distribution(Material::default_k_distribution) {}

Specular::Specular(int red, int green, int blue) : colour(red, green, blue),
	k_ambient(Material::default_k_ambient), k_diffuse(Material::default_k_diffuse),
	k_specular(Material::default_k_specular), k_reflective(Material::default_k_reflective),
	k_distribution(Material::default_k_distribution) {}

Specular::~Specular() {}

/*		Get Colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour Specular::get_colour(const Vector3 &point, const Vector3 &direction, const Vector3 &normal,
		int depth, bool debug) {
	double intensity_lambert = Light::ambient_intensity * k_ambient;
	Colour incoming_lambert = Light::ambient_colour * intensity_lambert;
	double intensity_specular = 0.0;
	Colour incoming_specular = Colour(0,0,0);

	Vector3 reflection_direction = direction - normal * direction.dot(normal) * 2.0;
	Ray reflection = Ray(point + reflection_direction.normalised()*Material::shadow_tweak,
		reflection_direction);
	// Ray reflection = Ray(point, reflection_direction);

	for (int i = 0; i < lights->size(); i++) {
		Ray shadow_ray = Ray(point+lights->at(i)->get_direction(point)*Material::shadow_tweak,
			lights->at(i)->get_direction(point));

		if (debug)
			std::cout << "dot = " << (normal.dot(lights->at(i)->get_direction(point)) / normal.length() / lights->at(i)->get_direction(point).length()) << std::endl;

		if (shadow_ray.clear_path(lights->at(i)->get_distance(point))) {
			// lambert component
			intensity_lambert = normal.dot(lights->at(i)->get_direction(point))
				/ normal.length()
				/ lights->at(i)->get_direction(point).length()
				* lights->at(i)->get_intensity(point);

			if (intensity_lambert > 0.0) {
				incoming_lambert += lights->at(i)->get_colour() * intensity_lambert * k_diffuse;
			}

			// specular component
			Ray light_ray = Ray(point, lights->at(i)->get_direction(point));
			double rl_dot = reflection.direction.dot(lights->at(i)->get_direction(point));

			if (rl_dot > 0.0) {
				intensity_specular = pow(rl_dot / reflection.direction.length()
					/ lights->at(i)->get_direction(point).length(), k_distribution)
					* lights->at(i)->get_intensity(point);

				if (intensity_specular > 0.0) {
					incoming_specular += lights->at(i)->get_colour()*intensity_specular*k_specular;
				}
			}
		}
	}

	return incoming_lambert * colour + incoming_specular + reflection.trace(depth)*k_reflective;
}

