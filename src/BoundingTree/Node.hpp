#pragma once
#include <limits>
#include "../Geometry/Object.hpp"
#include "../Light/Ray.hpp"

namespace Graphics {
class Node {
private:
public:
	Node *left;
	Node *right;
	Object *obj;

	Vector3 center;
	double radius;

	Node();
	Node(Object *obj);
	Node(Node *left, Node *right);
	~Node();

	bool hit_by(const Ray &ray) const;
	double hit_distance(const Ray &ray) const;
	Object *hit(const Ray &ray) const;

	void update_bound();
	Vector3 get_center() const;
	double get_bounding_radius() const;
};
}
