#include "Raytracer.hpp"
using namespace Graphics;

/*		Raytracer constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Raytracer::Raytracer() : image(500, 400) {}
Raytracer::Raytracer(int width, int height) : image(width, height) {}
Raytracer::Raytracer(int width, int height, Camera &cam) :  camera(cam), image(width, height) {}
Raytracer::~Raytracer() {}

/*		Render the scene
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// renders the scene in its current state and places the image data inside the image object
void Raytracer::render_scene() {
	camera.fix_aperture_ratio(image.width, image.height);
	camera.update_screen_vectors(image.width, image.height);

	for (int i = 0; i < image.width; i++)
		for (int j = 0; j < image.height; j++) {
			Ray pixel_ray(camera.eye_position,
				(camera.get_pixel_screen_intersection(i, j) - camera.eye_position).normalised());

			image(i,j) = pixel_ray.trace();
		}
}

/*		Manipulate the scene
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Raytracer::add_light(Light *light) {
	scene.add_light(light);
}

/*		Save rendered image
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// saves the rendered image
void Raytracer::save_image(const std::string &path) {
	image.write_to_file(path);
}

/*		Setters
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Raytracer::set_background(const Colour &colour) {
	scene.background = colour;
}

// camera modification
void Raytracer::set_eye(const Vector3 &eye) {
	camera.set_eye(eye);
}
