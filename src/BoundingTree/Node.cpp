#include "Node.hpp"
using namespace Graphics;

/*		Constructor and Destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Node::Node() {
	left = NULL;
	right = NULL;
	obj = NULL;
}

Node::Node(Object *obj) {
	left = NULL;
	right = NULL;
	this->obj = obj;
	update_bound();
}

Node::Node(Node *left, Node *right) {
	this->left = left;
	this->right = right;
	obj = NULL;
	update_bound();
}

Node::~Node() {
	delete left;
	delete right;
	delete obj;
}

/*		Updates the values for the bounding area
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void Node::update_bound() {
	Vector3 c_left, c_right;
	double r_left, r_right;

	if (obj != NULL) {
		center = obj->get_center();
		radius = obj->get_bounding_radius();
	} else {
		if (left != NULL) {
			c_left = left->get_center();
			r_left = left->get_bounding_radius();
		}
		if (right != NULL) {
			c_right = right->get_center();
			r_right = right->get_bounding_radius();
		}

		if (left != NULL && right != NULL) {
			Vector3 disp = c_left - c_right;

			if (r_left < std::numeric_limits<double>::infinity() &&
					r_right < std::numeric_limits<double>::infinity()) {
				radius = (disp.length() + r_left + r_right+0.5)/2;
			} else {
				radius = std::numeric_limits<double>::infinity();
			}
			
			center = c_right + disp.normalised()*(radius-r_right);
		} else if (left != NULL) {
			center = left->get_center();
			radius = left->get_bounding_radius();
		} else if (right != NULL) {
			center = right->get_center();
			radius = right->get_bounding_radius();
		} else {
			center = Vector3(0,0,0);
			radius = 0.0;
		}
	}
}

Vector3 Node::get_center() const {
	return center;
}

double Node::get_bounding_radius() const {
	return radius;
}

/*		Test for ray intersection with objects in the scene
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool Node::hit_by(const Ray &ray) const {
	if (radius < std::numeric_limits<double>::infinity()) {
		double a, b, c;
		Vector3 objspace_origin = ray.origin - center;

		a = ray.direction.dot(ray.direction);
		b = ray.direction.dot(objspace_origin) * 2;
		c = objspace_origin.dot(objspace_origin) - radius*radius;

		double discriminant = b*b - 4*a*c;

		if (discriminant >= 0.0)
			return true;
		else
			return false;
	}
	return true;
}

double Node::hit_distance(const Ray &ray) const {
	double t, t_hit = std::numeric_limits<double>::infinity();

	if (obj != NULL && obj->hit_by(ray) && t_hit > (t = obj->hit_distance(ray)))
		t_hit = t;
	if (left != NULL && left->hit_by(ray) && t_hit > (t = left->hit_distance(ray)))
		t_hit = t;
	if (right != NULL && right->hit_by(ray) && t_hit > (t = right->hit_distance(ray)))
		t_hit = t;
	return t_hit;
}

Object *Node::hit(const Ray &ray) const {
	double t, t_hit = std::numeric_limits<double>::infinity();
	Object *o_hit = NULL;

	if (obj != NULL && t_hit > (t = obj->hit_distance(ray))) {
		t_hit = t;
		o_hit = obj;
	}

	if (left != NULL && t_hit > (t = left->hit_distance(ray))) {
		t_hit = t;
		o_hit = left->hit(ray);
	}

	if (right != NULL && t_hit > (t = right->hit_distance(ray))) {
		t_hit = t;
		o_hit = right->hit(ray);
	}

	return o_hit;
}
