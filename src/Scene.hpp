#pragma once
#include <vector>

#include "BoundingTree/Node.hpp"
#include "Light/Colour.hpp"
#include "Light/Light.hpp"
#include "Geometry/Object.hpp"
#include "Geometry/Sphere.hpp"

namespace Graphics {
class Node;
class Ray;
class Object;

class Scene {
private:
	// std::vector<Object*> objects;
	std::vector<Light*> lights;
public:
	Node *tree_root;
	Colour background;

	Scene();
	Scene(int objects);
	~Scene();

	void add_light(Light *light);

	friend class Ray;
};
}
