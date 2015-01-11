#pragma once
#include <tuple>
#include <limits>

#include "../Vector3.hpp"
#include "Object.hpp"

namespace Graphics {
class Object;

class Plane : public Object {
private:
public:
	Vector3 normal;
	double d;

	using Object::hit_by;

	Plane();
	Plane(const Vector3 &cent, const Vector3 &normal);
	Plane(const Vector3 &cent, const Vector3 &normal, Material *mat);
	Plane(const Vector3 &cent, const Vector3 &normal, double radius);
	Plane(const Vector3 &cent, const Vector3 &normal, double radius, Material *mat);

	bool hit_by(const Ray &ray) const;
	double hit_distance(const Ray &ray) const;
	std::tuple<double,Colour> hit(const Ray &ray, int depth) const;
};
}
