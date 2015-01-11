#include "Vector3.hpp"
#include "BoundingTree/Node.hpp"
#include "Geometry/Sphere.hpp"
#include "Geometry/Triangle.hpp"
#include "Geometry/Plane.hpp"
#include "Material/DiffuseColour.hpp"
#include "Material/Lambert.hpp"
#include "Material/Specular.hpp"
#include "Light/DirectionalLight.hpp"
#include "Light/PointLight.hpp"
#include "Light/SpotLight.hpp"
#include "Raytracer.hpp"

using namespace Graphics;

void render_2p1();
void render_2p2();
void render_4p1();
void render_4p2();
void render_5p1();
void render_5p2();

int main(int argc, char* argv[]) {
	// creates the raytracer variable
	Raytracer raytracer(1200,800);
	raytracer.set_eye(Vector3(-15,0,1));
	// raytracer.set_eye(Vector3(-10,0,5));
	raytracer.set_background(Colour(0,20,100));

	// adds lights
	raytracer.add_light(new DirectionalLight(Colour(200,200,255), 0.1, Vector3(0,0,-1)));
	raytracer.add_light(new PointLight(Colour(255,255,255), 0.3, Vector3(-8,0,10)));
	raytracer.add_light(new SpotLight(Colour(255,255,255), 1.0, Vector3(-4,0,20), Vector3(4,0,-20), 80));

	raytracer.add_light(new SpotLight(Colour(0,127,255), 0.6, Vector3(0,-6,20), Vector3(-2,2,-20), 80));
	raytracer.add_light(new SpotLight(Colour(160,0,255), 0.6, Vector3(0,6,20), Vector3(-2,-2,-20), 80));
	raytracer.add_light(new SpotLight(Colour(255,255,0), 0.6, Vector3(6,4,20), Vector3(0,0,-20), 80));
	raytracer.add_light(new SpotLight(Colour(0,255,0), 0.6, Vector3(6,-4,20), Vector3(0,0,-20), 80));

	// materials
	Specular *snow = new Specular(255,255,255);
	snow->k_reflective = 0.2;
	snow->k_specular = 0.4;
	snow->k_distribution = 200;
	snow->k_distribution = 1;

	Lambert *black = new Lambert(0,0,0);

	Specular *carrot = new Specular(255,114,0);

	// snow man body parts
	Sphere *lower_body1 = new Sphere(Vector3(0,0,-2), 3, snow);
	Sphere *lower_body2 = new Sphere(Vector3(0.0,0.0,-3.5), 3, snow);
	
	Sphere *upper_body1 = new Sphere(Vector3(0.0,0.0,1.0), 2, snow);
	Sphere *upper_body2 = new Sphere(Vector3(0.0,0.0,2.4), 1.8, snow);

	Sphere *head = new Sphere(Vector3(0.0,0.0,4.8), 1, snow);
	Plane *hat = new Plane(Vector3(0.0,0.0,5.5), Vector3(-1,0,-4), 1.5, black);
	Sphere *hat_top = new Sphere(Vector3(0,0,6), 0.7, black);

	Sphere *eye1 = new Sphere(Vector3(-1.0,-0.4,5.0), 0.1, black);
	Sphere *eye2 = new Sphere(Vector3(-1.0, 0.4,5.0), 0.1, black);

	Sphere *nose = new Sphere(Vector3(-1.0,0.0,4.7), 0.2, carrot);

	Sphere *mouth1 = new Sphere(Vector3(-0.8,0.0,4.2), 0.09, black);
	Sphere *mouth2 = new Sphere(Vector3(-0.9,0.2,4.25), 0.09, black);
	Sphere *mouth3 = new Sphere(Vector3(-0.9,0.4,4.33), 0.09, black);
	Sphere *mouth4 = new Sphere(Vector3(-0.9,-0.2,4.25), 0.09, black);
	Sphere *mouth5 = new Sphere(Vector3(-0.9,-0.4,4.33), 0.09, black);

	Sphere *button1 = new Sphere(Vector3(-1.75,0.0, 2.8), 0.22, black);
	Sphere *button2 = new Sphere(Vector3(-1.95,0.0, 1.2), 0.22, black);
	Sphere *button3 = new Sphere(Vector3(-2.8,0.0, -1.0), 0.22, black);

	Specular *mirror = new Specular(100,100,100);
	mirror->k_ambient = 0.0;
	mirror->k_diffuse = 0.2;
	mirror->k_specular = 0.4;
	mirror->k_reflective = 0.8;
	mirror->k_distribution = 500;

	// ground plane
	Plane *p1 = new Plane(Vector3(0,0,-5), Vector3(0,0,1), new Specular(255,255,255));

	raytracer.scene.tree_root = new Node(
		new Node(p1),
		new Node(
			new Node(
				new Node(
					new Node(
						new Node(head),
						new Node(
							new Node(
								new Node(nose),
								new Node(
									new Node(mouth1),
									new Node(
										new Node(
											new Node(mouth2),
											new Node(mouth3)),
										new Node(
											new Node(mouth4),
											new Node(mouth5))))),
							new Node(
								new Node(eye1),
								new Node(eye2)))),
					new Node(
						new Node(hat),
						new Node(hat_top))),
				new Node(
					new Node(
						new Node(button3),
						new Node(
							new Node(button1),
							new Node(button2))),
					new Node(
						new Node(upper_body1),
						new Node(upper_body2)))),
			new Node(
				new Node(lower_body1),
				new Node(lower_body2))));

	// render and save the image
	raytracer.render_scene();
	raytracer.save_image("snowman-disco.bmp");

	// render_2p1();
	// render_2p2();
	// render_4p1();
	// render_4p2();
	// render_5p1();
	// render_5p2();

	return 0;
}


// renders the image used under Simple Primitives / Spheres and Planes
void render_2p1() {
	Raytracer raytracer(600,400);
	raytracer.set_background(Colour(0,0,0));

	// raytracer.add_light(new DirectionalLight(Colour(255,255,255),10.0,Vector3(0,0,-1)));
	raytracer.add_light(new DirectionalLight());

	Lambert *mblue = new Lambert(0,127,255);
	Lambert *mred = new Lambert(255,100,100);
	Specular *white = new Specular(255,255,255);

	Sphere *s1 = new Sphere(Vector3(0,0,1), 2.0, mblue);
	Sphere *s2 = new Sphere(Vector3(0,4,1), 1.4, mred);

	// base plane
	Plane *p1 = new Plane(Vector3(0,0,-2), Vector3(0,0,1), white);

	Plane *pcircle1 = new Plane(Vector3(0,-5,1), Vector3(-1,0,2), 2.0, mred);
	Plane *pcircle2 = new Plane(Vector3(0,-5,1), Vector3(-2,0,-1), 2.0, mblue);

	raytracer.scene.tree_root = new Node(
		new Node(p1),
		new Node(
			new Node(
				new Node(s1),
				new Node(pcircle1)),
			new Node(
				new Node(s2),
				new Node(pcircle2))));

	raytracer.render_scene();
	raytracer.save_image("report-2.1.bmp");
}

// renders the image used under Simple primitives / Triangles
void render_2p2() {
	Raytracer raytracer(600,400);

	raytracer.set_eye(Vector3(-4,-2,2));
	raytracer.add_light(new DirectionalLight(Colour(255,255,255), 0.7, Vector3(0,-1,-4)));
	raytracer.add_light(new PointLight(Colour(255,255,255), 0.7, Vector3(-8,0,10)));

	Triangle *t1 = NULL;
	Triangle *t2 = NULL;
	Triangle *t3 = NULL;
	Triangle *t4 = NULL;

	t1 = new Triangle(Vector3(-1,-1,0), Vector3(-1,1,0), Vector3(0,0,1), new Lambert(255,0,0));

	Specular *wmir = new Specular(255,255,255);
	wmir->k_reflective = 2.0;
	wmir->k_diffuse = 0.5;
	Plane *ground = new Plane(Vector3(0.0,0.0,-0.8), Vector3(0,0,1), wmir);

	raytracer.scene.tree_root = new Node(
		new Node(ground),
		new Node(
			new Node(
				new Node(t3),
				new Node(t4)),
			new Node(
				new Node(t1),
				new Node(t2))));

	// raytracer.scene.tree_root = new Node(t3);

	raytracer.render_scene();
	raytracer.save_image("report-2.2.bmp");
}

// lambert material demonstration
void render_4p1() {
	Raytracer raytracer(600,400);

	raytracer.set_eye(Vector3(-10,0,1));
	raytracer.add_light(new DirectionalLight());

	Lambert *blue = new Lambert(50,127,255);
	Lambert *red = new Lambert(255,127,127);
	Lambert *green = new Lambert(127,255,127);

	Sphere *s1 = new Sphere(Vector3(0,0,0), 2.0, blue);
	Sphere *s2 = new Sphere(Vector3(0,4,0), 2.0, red);
	Sphere *s3 = new Sphere(Vector3(0,-4,0), 2.0, green);

	Plane *ground = new Plane(Vector3(0.0,0.0,-1.5), Vector3(0,0,1), new Lambert(255,255,255));

	raytracer.scene.tree_root = new Node(
		new Node(
			new Node(ground),
			new Node(s1)),
		new Node(
			new Node(s2),
			new Node(s3)));

	raytracer.render_scene();
	raytracer.save_image("report-4.1.bmp");
}

// specular material demonstration
void render_4p2() {
	Raytracer raytracer(600,400);

	raytracer.set_eye(Vector3(-10,0,1));
	raytracer.add_light(new DirectionalLight());

	Specular *blue = new Specular(50,127,255);
	Specular *red = new Specular(255,127,127);
	Specular *green = new Specular(127,255,127);

	Sphere *s1 = new Sphere(Vector3(0,0,0), 2.0, blue);
	Sphere *s2 = new Sphere(Vector3(0,4,0), 2.0, red);
	Sphere *s3 = new Sphere(Vector3(0,-4,0), 2.0, green);

	Plane *ground = new Plane(Vector3(0.0,0.0,-1.5), Vector3(0,0,1), new Specular(255,255,255));

	raytracer.scene.tree_root = new Node(
		new Node(
			new Node(ground),
			new Node(s1)),
		new Node(
			new Node(s2),
			new Node(s3)));

	raytracer.render_scene();
	raytracer.save_image("report-4.2.bmp");
}

// Point and spot light demonstration
void render_5p1() {
	Raytracer raytracer(600,400);

	raytracer.set_eye(Vector3(-10,0,40));
	// raytracer.add_light(new DirectionalLight());
	// raytracer.add_light(new PointLight(Colour(255,255,255), 0.7, Vector3(0.5,-13.0,0.0)));
	raytracer.add_light(new SpotLight(Colour(255,0,0), 1.0, Vector3(-4.0,20.0,-0.5), Vector3(1,0,0)));
	raytracer.add_light(new SpotLight(Colour(255,255,0), 2.0, Vector3(-4.0, 10.0,-0.5), Vector3(1,0,0), 10));
	raytracer.add_light(new SpotLight(Colour(0,255,0), 3.0, Vector3(-4.0,0.0,-0.5), Vector3(1,0,0), 40));
	raytracer.add_light(new SpotLight(Colour(0,255,255), 6.0, Vector3(-4.0,-10.0,-1.0), Vector3(1,0,0), 400));
	raytracer.add_light(new SpotLight(Colour(255,0,255), 20.0, Vector3(-4.0,-20.0,-1.3), Vector3(1,0,0), 2000));

	Specular *blue = new Specular(50,127,255);
	Specular *red = new Specular(255,127,127);
	Specular *green = new Specular(127,255,127);

	Sphere *s1 = new Sphere(Vector3(8,-13,0), 2.0, blue);
	Sphere *s2 = new Sphere(Vector3(-7,-6,0), 2.0, red);
	Sphere *s3 = new Sphere(Vector3(-7,-20,0), 2.0, green);

	Sphere *s4 = new Sphere(Vector3(8,13,0), 2.0, blue);
	Sphere *s5 = new Sphere(Vector3(-7,6,0), 2.0, green);
	Sphere *s6 = new Sphere(Vector3(-7,20,0), 2.0, red);

	Plane *ground = new Plane(Vector3(0.0,0.0,-1.5), Vector3(0,0,1), new Specular(255,255,255));

	raytracer.scene.tree_root = new Node(
		new Node(ground),
		new Node(
			new Node(new Node(s1), new Node(new Node(s2), new Node(s3))),
			new Node(new Node(s4), new Node(new Node(s5), new Node(s6)))));

	raytracer.render_scene();
	raytracer.save_image("report-5.1.bmp");
}

// shadow demonstration
void render_5p2() {
	Raytracer raytracer(600,400);

	raytracer.set_eye(Vector3(-20,0,8));
	raytracer.add_light(new SpotLight(Colour(255,127,127), 0.7, Vector3(0,4,20), Vector3(0,-8,-20), 50));
	raytracer.add_light(new SpotLight(Colour(127,127,255), 0.7, Vector3(0,-4,20), Vector3(0,8,-20), 50));
	raytracer.add_light(new SpotLight(Colour(255,255,255), 0.7, Vector3(10,0,20), Vector3(-20,0,-20), 40));
	raytracer.add_light(new SpotLight(Colour(127,255,127), 0.7, Vector3(-10,0,20), Vector3(20,0,-20), 40));

	Specular *blue = new Specular(50,127,255);
	blue->k_distribution = 70;
	Specular *white = new Specular();
	white->k_distribution = 500;

	Sphere *s1 = new Sphere(Vector3(0,0,5), 2.0, blue);
	Plane *ground = new Plane(Vector3(0.0,0.0,-1.5), Vector3(0,0,1), white);

	raytracer.scene.tree_root = new Node(
		new Node(ground),
		new Node(s1));

	raytracer.render_scene();
	raytracer.save_image("report-5.2.bmp");
}
