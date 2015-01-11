#include "Ray.hpp"
using namespace Graphics;
Scene *Ray::scene = NULL;
int Ray::max_recursion = 10;

/*		Ray constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Ray::Ray(const Vector3 &origin, const Vector3 &direction) : origin(origin),
	direction(direction.normalised()) {}

/*		Trace the rays colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Colour Ray::trace() const {
	return trace(Ray::max_recursion+1);
}

Colour Ray::trace(int depth) const {
	if (depth > 0) {
		std::tuple<double,Colour> t, hitpoint(std::numeric_limits<double>::infinity(),
			Ray::scene->background);

		Object *obj = Ray::scene->tree_root->hit(*this);

		if (obj != NULL) {
			hitpoint = obj->hit(*this, depth-1);
		}

		return std::get<1>(hitpoint);
	}
	return Colour(0,0,0);
}

/*		Test for intersection
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool Ray::clear_path() const {
	return clear_path(std::numeric_limits<double>::infinity());
}

bool Ray::clear_path(double distance) const {
	double t;

	t = Ray::scene->tree_root->hit_distance(*this);

	if (t < distance)
		return false;

	return true;
}
