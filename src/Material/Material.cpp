#include "Material.hpp"
using namespace Graphics;
const double Material::shadow_tweak = 0.01;

const double Material::default_k_ambient		= 1.0;
const double Material::default_k_diffuse		= 1.0;
const double Material::default_k_specular		= 1.0;
const double Material::default_k_reflective		= 0.4;
const double Material::default_k_distribution	= 60.0;

std::vector<Light*> *Material::lights = NULL;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Material::Material() {}
Material::~Material() {}

void Material::link_lights(std::vector<Light*> *lights) {
	Material::lights = lights;
}

void Material::link_obj(Object *obj) {
	parent_obj = obj;
}
