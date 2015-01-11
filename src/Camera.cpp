#include "Camera.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Camera::Camera() : eye_position(-10,0,2), look_at(0,0,0), up(0,0,1) {
	screen_distance = 5.0;
	aperture_width = 5.0;
	aperture_height = 5.0;
	pixel_width = 0.0;
	pixel_height = 0.0;
	width = 0;
	height = 0;
}

/*		Calculate positions
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Camera::update_screen_vectors(int width, int height) {
	normal = (eye_position - look_at).normalised();
	center = eye_position - normal*screen_distance;
	// y_axis = up.normalised();
	x_axis = normal.cross(up).normalised();
	y_axis = normal.cross(x_axis).normalised();

	pixel_width = aperture_width / width;
	pixel_height = aperture_height / height;
}

void Camera::fix_aperture_ratio(int width, int height) {
	aperture_width = aperture_width * ((double)width / height);
}

Vector3 Camera::get_pixel_screen_intersection(int x, int y) {
	return center + x_axis*(x*pixel_width - 0.5*aperture_width + 0.5*pixel_width)
		+ y_axis*(y*pixel_height - 0.5*aperture_height + 0.5*pixel_height);
}

// camera modification
void Camera::set_eye(const Vector3 &eye) {
	eye_position = eye;
}
