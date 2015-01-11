#include "Object.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Object::Object() : center(0,0,0), bounding_radius(1.0) {
	material = new DiffuseColour();
	material->link_obj(this);
}

Object::Object(const Vector3 &cent, double b_radius) : center(cent), bounding_radius(b_radius) {
	material = new DiffuseColour();
	material->link_obj(this);
}

Object::Object(const Vector3 &cent, double b_radius, Material *mat) : center(cent),
		bounding_radius(b_radius), material(mat) {
	material->link_obj(this);
}

Object::~Object() {}

/*		Test for bounding hit
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool Object::hit_by(const Ray &ray) const {
	double a, b, c;
	Vector3 objspace_origin = ray.origin - center;
	// Vector3 objspace_origin = center - ray.origin;

	a = ray.direction.dot(ray.direction);
	b = ray.direction.dot(objspace_origin) * 2;
	c = objspace_origin.dot(objspace_origin) - bounding_radius*bounding_radius;

	double discriminant = b*b - 4*a*c;

	if (discriminant >= 0.0)
		return true;
	else
		return false;
}

/*		Link together pointers needed for material calculations
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Object::link_obj(Object *obj) {
	material->link_obj(obj);
}

/*		Setters and Getters for certain values
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 Object::get_center() const {
	return center;
}

double Object::get_bounding_radius() const {
	return bounding_radius;
}

void Object::set_center(const Vector3 &center) {
	this->center = center;
}

void Object::set_bounding_radius(double bounding_radius) {
	this->bounding_radius = bounding_radius;
}
