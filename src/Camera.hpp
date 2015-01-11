#pragma once

#include "Vector3.hpp"

namespace Graphics {
class Camera {
private:

public:
	// data relating to the screen plane
	Vector3 normal;
	Vector3 center;
	Vector3 x_axis;
	Vector3 y_axis;
	double pixel_width;
	double pixel_height;
	int width;
	int height;

	// camera information
	Vector3 eye_position;
	Vector3 look_at;
	Vector3 up;
	double screen_distance;

	// screen aperture width and height
	double aperture_height;
	double aperture_width;


	Camera();

	void fix_aperture_ratio(int width, int height);
	void update_screen_vectors(int width, int height);
	Vector3 get_pixel_screen_intersection(int x, int y);

	void set_eye(const Vector3 &eye);
};
}
