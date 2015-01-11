#pragma once
#include <tuple>
#include <limits>

#include "../Vector3.hpp"
#include "Object.hpp"
#include "../Material/Lambert.hpp"

namespace Graphics {
class Object;

class Triangle : public Object {
private:
protected:
public:
	Vector3 a;
	Vector3 b;
	Vector3 c;
	double d;
	Vector3 normal;

	Triangle();
	// Triangle(const Vector3 &cent, double radius);
	// Triangle(const Vector3 &cent, double radius, Material *mat);

	Triangle(const Vector3 &a, const Vector3 &b, const Vector3 &c, Material *mat,
		bool invert_normal = false);

	// bool hit_by(const Ray &ray) const;
	double hit_distance(const Ray &ray) const;
	std::tuple<double,Colour> hit(const Ray &ray, int depth) const;

	// returns the maximum distance between the triangle center and each of its 3 corner verticies
	static double max_distance(const Vector3 &center, const Vector3 &a, const Vector3 &b,
		const Vector3 &c);
};
}
