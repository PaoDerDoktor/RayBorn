#include <iostream>

#include "../include/Vector.hpp"
#include "../include/Point.hpp"
#include "../include/Camera.hpp"
#include "../include/Sphere.hpp"
#include "../include/Scene.hpp"

int main(int argc, char *argv[]) {
	Point camCenter(0, 0, 0);
	Vector camDirection(0, 0, 1);
	Point camLLC(-2, -1, 1);
	Vector camVpWidth(4, 0, 0);
	Vector camVpHeight(0, 2, 0);
	int pxWidth(200);
	int pxHeight(50);

	Point sphereCenter(0, 0, 1);
	double sphereRadius(0.5);

	Camera cam(camCenter, camDirection, pxWidth, pxHeight, camLLC, camVpWidth, camVpHeight);

	Sphere sphere(sphereCenter, sphereRadius);

	Scene scene;

	scene.addShape(&sphere);

	cam.trace("render.ppm", scene);
}