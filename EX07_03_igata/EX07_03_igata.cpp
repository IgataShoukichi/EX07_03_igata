#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Solid {
public:
	virtual double GetVolume() = 0;
	virtual double GetSurface() = 0;
};

class Box :Solid {
private:
	double width;
	double height;
	double depth;

public:
	Box(
		double width,   //幅
		double height,  //高さ
		double depth) { //奥行
		this->width = width;
		this->height = height;
		this->depth = depth;
	}
	double GetWidth() {
		return width;
	}
	double GetHeight() {
		return height;
	}
	double GetDepth() {
		return depth;
	}
	double GetVolume() {
		return width * height * depth;
	}
	double GetSurface() {
		return (width * height + height * depth + depth * width) * 2;
	}
};
class Cylinder :Solid {
private:
	double radius;
	double height;

public:
	Cylinder(
		double radius,   //半径
		double height) { //高さ

		this->radius = radius;
		this->height = height;
	}
	double GetRadius() {
		return radius;
	}
	double Getheight() {
		return height;
	}
	double GetVolume() {
		return M_PI * radius * radius * height;
	}
	double GetSurface() {
		return 2 * M_PI * radius * (height + radius);
	}
};
class Cone :Solid {
private:
	double radius;
	double height;

public:
	Cone(
		double radius,   //半径
		double height) { //高さ
		this->radius = radius;
		this->height = height;
	}	
	double GetRadius() {
		return radius;
	}
	double Getheight() {
		return height;
	}
	double GetVolume() {
		return M_PI * radius * radius * height / 3;
	}
	double GetSurface() {
		double L = radius * radius + height * height;
		return M_PI * radius * (sqrt(L) + radius);
	}
};
class Sphere :Solid {
private:
	double radius;

public:
	Sphere(
		double radius) { //半径
		this->radius = radius;
	}
	double GetRadius() {
		return radius;
	}
	double GetVolume() {
		return 4 / 3 * M_PI * radius * radius;
	}
	double GetSurface() {
		return 4 * M_PI * radius * radius;
	}
};

int main()
{
	Box box{ 3,5,2.5 };
	cout << "boxの体積=" << box.GetVolume() << endl;
	cout << "boxの表面積=" << box.GetSurface() << endl;
	Cylinder cylinder{ 3,5 };
	cout << "cylinderの体積" << cylinder.GetVolume() << endl;
	cout << "cylinderの表面積" << cylinder.GetSurface() << endl;
	Cone cone{ 3,5 };
	cout << "coneの体積" << cone.GetVolume() << endl;
	cout << "coneの表面積" << cone.GetSurface() << endl;
	Sphere sphere{ 3 };
	cout << "sphereの体積" << sphere.GetVolume() << endl;
	cout << "sphereの表面積" << sphere.GetSurface() << endl;
}