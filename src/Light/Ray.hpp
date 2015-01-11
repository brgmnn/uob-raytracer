#pragma once
#include <limits>
#include <tuple>

#include "Colour.hpp"
#include "../Geometry/Object.hpp"
#include "../Geometry/Sphere.hpp"
#include "../Scene.hpp"
#include "../Vector3.hpp"

namespace Graphics {
class Colour;
class Vector3;
class Object;

class Ray {
private:
	static Scene *scene;
	static int max_recursion;
public:
	const Vector3 origin;
	const Vector3 direction;

	Ray(const Vector3 &origin, const Vector3 &direction);

	Vector3 intersection_point(const Object &obj);
	Vector3 intersection_normal(const Object &obj);

	bool clear_path() const;
	bool clear_path(double distance) const;

	Colour trace() const;
	Colour trace(int depth) const;

	friend class Scene;
};
}
