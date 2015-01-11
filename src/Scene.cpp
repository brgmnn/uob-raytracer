#include "Scene.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Scene::Scene() : objects(), lights() {
Scene::Scene() : lights() {
	Ray::scene = this;
	Material::link_lights(&lights);
	background = Colour(0, 0, 0);

	tree_root = new Node();
}

Scene::~Scene() {
	// for (int i = 0; i < (int)objects.size(); i++)
	// 	delete objects[i];

	for (int i = 0; i < (int)lights.size(); i++)
		delete lights[i];
}

/*		Add things to the scene
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Scene::add_light(Light *light) {
	lights.push_back(light);
}
