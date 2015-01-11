#include "Triangle.hpp"
using namespace Graphics;

/*		Constructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Triangle::Triangle() : Object() {}
// Triangle::Triangle(const Vector3 &cent, double radius) : Object(cent, radius) {}
// Triangle::Triangle(const Vector3 &cent, double radius, Material *mat) : Object(cent, radius, mat) {}

Triangle::Triangle(const Vector3 &a, const Vector3 &b, const Vector3 &c, Material *mat,
		bool invert_normal)
		: Object((a + b + c) / 3, Triangle::max_distance((a + b + c)/3, a, b, c), mat), a(a), b(b),
		c(c), normal((b-a).cross(c-a).normalised()) {
	this->center = (a + b + c) / 3;
	this->bounding_radius = Triangle::max_distance(center, a, b, c);
	
	// if (invert_normal)
		// this->normal = (c-a).cross(b-a).normalised();
	// else
		// this->normal = (b-a).cross(c-a).normalised();
	
	this->d = -a.dot(normal);
}

/*		Calculate the hit colour
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
double Triangle::hit_distance(const Ray &ray) const {
	double t_hit = std::numeric_limits<double>::infinity();
	
	if (normal.dot(ray.direction) != 0.0)
		t_hit = -(normal.dot(ray.origin) + d)/normal.dot(ray.direction);

	// if (normal.dot(ray.direction) > 0.0)
	// 	t_hit = -(normal.dot(ray.origin) + d)/normal.dot(ray.direction);

	if (t_hit < std::numeric_limits<double>::infinity()) {
		Vector3 hitpoint = ray.origin + ray.direction*t_hit;
		Vector3 v0 = b-a, v1 = c-a, v2 = hitpoint-a;
		
		// cramers rule for solving linear equations is applied here
		double d00 = v0.dot(v0); 
		double d01 = v0.dot(v1);
		double d11 = v1.dot(v1);
		double d20 = v2.dot(v0);
		double d21 = v2.dot(v1);
		double denom = d00*d11 - d01*d01;
		double v = (d11*d20 - d01*d21) / denom;
		double w = (d00*d21 - d01*d20) / denom;
		double u = 1.0-v-w;

		if (u <= 1.0 && u >= 0.0 && v <= 1.0 && v >= 0.0 && w <= 1.0 && w >= 0.0)
			return t_hit;
		else
			return std::numeric_limits<double>::infinity();
	}

	return std::numeric_limits<double>::infinity();
}

std::tuple<double,Colour> Triangle::hit(const Ray &ray, int depth) const {
	double t_hit = hit_distance(ray);

	if (t_hit < std::numeric_limits<double>::infinity()) {
		Vector3 hitpoint = ray.origin + ray.direction*t_hit;

		return std::tuple<double, Colour>(t_hit, material->get_colour(hitpoint, ray.direction,
			normal, depth, true));
	}

	return std::tuple<double, Colour>(std::numeric_limits<double>::infinity(), Colour(0,0,0));
}

double Triangle::max_distance(const Vector3 &center, const Vector3 &a, const Vector3 &b,
		const Vector3 &c) {

	// I added these slight scalings up to make sure that the bounding sphere of the triangle
	// actually encompassed the triangle as it was slightly too small otherwise.
	double dist_a = (a-center).length()*1.01+0.5;
	double dist_b = (b-center).length()*1.01+0.5;
	double dist_c = (c-center).length()*1.01+0.5;

	if (dist_a >= dist_b && dist_a >= dist_c)
		return dist_a;
	if (dist_b >= dist_a && dist_b >= dist_c)
		return dist_b;
	if (dist_c >= dist_a && dist_c >= dist_b)
		return dist_c;

	return dist_a + dist_b + dist_c;
}
