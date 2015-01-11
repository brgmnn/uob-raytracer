#pragma once
#include <tuple>
#include <vector>

#include "../Vector3.hpp"
#include "../Light/Colour.hpp"
#include "../Light/Light.hpp"
#include "../Material/Material.hpp"
#include "../Material/DiffuseColour.hpp"

namespace Graphics {
class Ray;
class Material;
class DiffuseColour;
class Scene;

class Object {
private:
protected:
public:
	Vector3 center;
	double bounding_radius;
	Material *material;
	
	// base constructors
	Object();
	Object(const Vector3 &cent, double b_radius);
	Object(const Vector3 &cent, double b_radius, Material *mat);
	virtual ~Object();

	// assign the lights and object so they can be used in colour calculations
	void link_obj(Object *obj);

	// hit functions
	virtual bool hit_by(const Ray &ray) const;
	virtual std::tuple<double,Colour> hit(const Ray &ray, int depth) const =0;
	virtual double hit_distance(const Ray &ray) const =0;

	// setters and getters
	Vector3 get_center() const;
	double get_bounding_radius() const;

	void set_center(const Vector3 &center);
	void set_bounding_radius(double bounding_radius);
};
}

#include "../Light/Ray.hpp"
#include "../Material/Material.hpp"
#include "../Material/DiffuseColour.hpp"
#include "../Scene.hpp"
