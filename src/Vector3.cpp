#include "Vector3.hpp"
using namespace Graphics;

/*		Constructor and destructor
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3::Vector3() {
	x = 0.0;
	y = 0.0;
	z = 0.0;
}

Vector3::Vector3(const Vector3 &cpy) {
	x = cpy.x;
	y = cpy.y;
	z = cpy.z;
}

Vector3::Vector3(int x, int y, int z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3::Vector3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

/*		Overloaded vector-to-vector comparison operators
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool Vector3::operator== (const Vector3 &rhs) const {
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool Vector3::operator!= (const Vector3 &rhs) const {
	return x != rhs.x || y != rhs.y || z != rhs.z;
}

/*		Overloaded vector-to-scalar float arithmetic operators
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 Vector3::operator+ (float rhs) const {
	return Vector3(x+rhs, y+rhs, z+rhs);
}

Vector3 Vector3::operator- (float rhs) const {
	return Vector3(x-rhs, y-rhs, z-rhs);
}

Vector3 Vector3::operator* (float rhs) const {
	return Vector3(x*rhs, y*rhs, z*rhs);
}

Vector3 Vector3::operator/ (float rhs) const {
	return Vector3(x/rhs, y/rhs, z/rhs);
}

/*		Overloaded vector-to-scalar double arithmetic operators
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 Vector3::operator+ (double rhs) const {
	return Vector3(x+rhs, y+rhs, z+rhs);
}

Vector3 Vector3::operator- (double rhs) const {
	return Vector3(x-rhs, y-rhs, z-rhs);
}

Vector3 Vector3::operator* (double rhs) const {
	return Vector3(x*rhs, y*rhs, z*rhs);
}

Vector3 Vector3::operator/ (double rhs) const {
	return Vector3(x/rhs, y/rhs, z/rhs);
}

/*		Overloaded vector-to-scalar int arithmetic operators
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 Vector3::operator+ (int rhs) const {
	return Vector3(x+rhs, y+rhs, z+rhs);
}

Vector3 Vector3::operator- (int rhs) const {
	return Vector3(x-rhs, y-rhs, z-rhs);
}

Vector3 Vector3::operator* (int rhs) const {
	return Vector3(x*rhs, y*rhs, z*rhs);
}

Vector3 Vector3::operator/ (int rhs) const {
	return Vector3(x/rhs, y/rhs, z/rhs);
}

/*		Overloaded vector-to-vector arithmetic operators
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 Vector3::operator+ (const Vector3 &rhs) const {
	return Vector3(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vector3 Vector3::operator- (const Vector3 &rhs) const {
	return Vector3(x-rhs.x, y-rhs.y, z-rhs.z);
}

/*		Vector special functions
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
Vector3 Vector3::cross(const Vector3 &rhs) const {
	return Vector3(y*rhs.z-z*rhs.y, z*rhs.x-x*rhs.z, x*rhs.y-y*rhs.x);
}

double Vector3::dot(const Vector3 &rhs) const {
	return x*rhs.x + y*rhs.y + z*rhs.z;
}

Vector3 Vector3::normalised() const {
	double len = length();
	return Vector3(x/len, y/len, z/len);
}

double Vector3::length() const {
	return sqrt(x*x + y*y + z*z);
}

/*		Printing functions
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
std::string Vector3::to_string() {
	std::stringstream tmp;
	tmp << "(" << x << "," << y << "," << z << ")";
	return tmp.str();
}
