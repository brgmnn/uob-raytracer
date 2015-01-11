#include "Plane.hpp"
using namespace Graphics;

/*		Constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Plane::Plane() : Object() {}
Plane::Plane(const Vector3 &cent, const Vector3 &normal)
		: Object(cent, std::numeric_limits<double>::infinity()), normal(normal) {
	this->d = -cent.dot(normal);
}

Plane::Plane(const Vector3 &cent, const Vector3 &normal, Material *mat)
		: Object(cent, std::numeric_limits<double>::infinity(), mat), normal(normal) {
	this->d = -cent.dot(normal);
}

Plane::Plane(const Vector3 &cent, const Vector3 &normal, double radius)
		: Object(cent, radius), normal(normal) {
	this->d = -cent.dot(normal);
}

Plane::Plane(const Vector3 &cent, const Vector3 &normal, double radius, Material *mat)
		: Object(cent, radius, mat), normal(normal) {
	this->d = -cent.dot(normal);
}

/*		Calculate the hit colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool Plane::hit_by(const Ray &ray) const {
	if (bounding_radius < std::numeric_limits<double>::infinity()) {
		return Object::hit_by(ray);
	} else {
		if (normal.dot(ray.direction) == 0.0)
			return false;
		return true;
	}
}

double Plane::hit_distance(const Ray &ray) const {
	if (bounding_radius < std::numeric_limits<double>::infinity()) {
		double t = std::numeric_limits<double>::infinity(), t_hit = std::numeric_limits<double>::infinity();
		
		// need to specify less than zero, as the direction vectors in the rays point in the direction
		// that the ray is travelling.
		if (normal.dot(ray.direction) < 0.0)
			t = -(normal.dot(ray.origin) + d)/normal.dot(ray.direction);

		// calculate the point on the plane where we hit
		Vector3 hitpoint = ray.origin + ray.direction*t;

		// set the hitpoint if it is within the radius
		if ((hitpoint-center).length() < bounding_radius)
			t_hit = t;

		return t_hit;
	} else {
		double t_hit = std::numeric_limits<double>::infinity();
		
		// need to specify less than zero, as the direction vectors in the rays point in the
		// direction that the ray is travelling.
		if (normal.dot(ray.direction) < 0.0)
			t_hit = -(normal.dot(ray.origin) + d)/normal.dot(ray.direction);

		return t_hit;
	}
}

std::tuple<double,Colour> Plane::hit(const Ray &ray, int depth) const {
	double t_hit = hit_distance(ray);

	if (t_hit < std::numeric_limits<double>::infinity()) {
		Vector3 hitpoint = ray.origin + ray.direction*t_hit;

		return std::tuple<double, Colour>(t_hit, material->get_colour(hitpoint, ray.direction,
			normal, depth));
	}

	return std::tuple<double, Colour>(std::numeric_limits<double>::infinity(), Colour(0,0,0));
}
