#pragma once
#include <cmath>
#include <iostream>
#include <sstream>

namespace Graphics {
class Vector3 {
private:
public:
	double x;
	double y;
	double z;

	Vector3();
	Vector3(const Vector3 &cpy);
	Vector3(int x, int y, int z);
	Vector3(double x, double y, double z);

	// vector-vector comparisons
	bool operator== (const Vector3 &rhs) const;
	bool operator!= (const Vector3 &rhs) const;

	// vector-scalar float arithmetic
	Vector3 operator+ (float rhs) const;
	Vector3 operator- (float rhs) const;
	Vector3 operator* (float rhs) const;
	Vector3 operator/ (float rhs) const;

	// vector-scalar double arithmetic
	Vector3 operator+ (double rhs) const;
	Vector3 operator- (double rhs) const;
	Vector3 operator* (double rhs) const;
	Vector3 operator/ (double rhs) const;

	// vector-scalar int arithmetic
	Vector3 operator+ (int rhs) const;
	Vector3 operator- (int rhs) const;
	Vector3 operator* (int rhs) const;
	Vector3 operator/ (int rhs) const;

	// vector-vector arithmetic
	Vector3 operator+ (const Vector3 &rhs) const;
	Vector3 operator- (const Vector3 &rhs) const;

	// vector specific functions
	Vector3 cross(const Vector3 &rhs) const;
	double dot(const Vector3 &rhs) const;
	double length() const;
	Vector3 normalised() const;

	// printing functions
	std::string to_string();
	friend std::ostream& operator<< (std::ostream &out, const Vector3 &vec) {
		out << "(" << vec.x << "," << vec.y << "," << vec.z << ")";
		return out;
	}
};
}
