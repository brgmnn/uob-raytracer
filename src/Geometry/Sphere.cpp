#include "Sphere.hpp"
using namespace Graphics;

/*		Constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Sphere::Sphere() : Object() {}
Sphere::Sphere(const Vector3 &cent, double radius) : Object(cent, radius) {}
Sphere::Sphere(const Vector3 &cent, double radius, Material *mat) : Object(cent, radius, mat) {}

/*		Calculate the hit colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double Sphere::hit_distance(const Ray &ray) const {
	double a, b, c, discriminant, t0, t1, t_hit;
	Vector3 objspace_origin = ray.origin - center;

	a = ray.direction.dot(ray.direction);
	b = ray.direction.dot(objspace_origin) * 2;
	c = objspace_origin.dot(objspace_origin) - bounding_radius*bounding_radius;

	discriminant = b*b - 4*a*c;

	if (discriminant >= 0.0) {
		t0 = (-b - sqrt(discriminant)) / 2;
		t1 = (-b + sqrt(discriminant)) / 2;

		if (t0 > 0.0 && t0 < t1)
			t_hit = t0;
		else if (t1 > 0.0)
			t_hit = t1;
		else
			t_hit = std::numeric_limits<double>::infinity();
	} else {
		t_hit = std::numeric_limits<double>::infinity();
	}
	
	return t_hit;
}

std::tuple<double,Colour> Sphere::hit(const Ray &ray, int depth) const {
	double a, b, c, discriminant, t0, t1, t_hit;
	Vector3 objspace_origin = ray.origin - center;

	a = ray.direction.dot(ray.direction);
	b = ray.direction.dot(objspace_origin) * 2;
	c = objspace_origin.dot(objspace_origin) - bounding_radius*bounding_radius;

	discriminant = b*b - 4*a*c;

	if (discriminant >= 0.0) {
		t0 = (-b - sqrt(discriminant)) / 2;
		t1 = (-b + sqrt(discriminant)) / 2;

		if (t0 > 0.0 && t0 < t1)
			t_hit = t0;
		else if (t1 > 0.0)
			t_hit = t1;
		else
			t_hit = std::numeric_limits<double>::infinity();
	} else {
		t_hit = std::numeric_limits<double>::infinity();
	}
	
	if (t_hit < std::numeric_limits<double>::infinity()) {
		Vector3 hitpoint = ray.origin + ray.direction*t_hit;
		Vector3 normal = hitpoint - center;

		return std::tuple<double, Colour>(t_hit, material->get_colour(hitpoint, ray.direction,
			normal, depth));
	} else {
		return std::tuple<double, Colour>(t_hit, Colour(0,0,0));
	}
}
