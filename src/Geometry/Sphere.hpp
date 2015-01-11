#pragma once
#include <tuple>
#include <limits>

#include "../Vector3.hpp"
#include "Object.hpp"

namespace Graphics {
class Object;

class Sphere : public Object {
private:
public:
	Sphere();
	Sphere(const Vector3 &cent, double radius);
	Sphere(const Vector3 &cent, double radius, Material *mat);

	// bool hit_by(const Ray &ray) const;
	double hit_distance(const Ray &ray) const;
	std::tuple<double,Colour> hit(const Ray &ray, int depth) const;
};
}
