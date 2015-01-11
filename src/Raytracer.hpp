#pragma once
#include <string>

#include "Camera.hpp"
#include "Image.hpp"
#include "Scene.hpp"
#include "Light/Ray.hpp"
#include "Light/Light.hpp"
#include "Geometry/Object.hpp"

namespace Graphics {
class Raytracer {
private:
	Camera camera;
	Image image;
public:
	Scene scene;
	Raytracer();
	Raytracer(int width, int height);
	Raytracer(int width, int height, Camera &cam);
	~Raytracer();

	// add lights to the scene
	void add_light(Light *light);

	// setters
	void set_background(const Colour &colour);

	// rendering functions
	void render_scene();
	void save_image(const std::string &path);

	// camera modification
	void set_eye(const Vector3 &eye);
};
}
