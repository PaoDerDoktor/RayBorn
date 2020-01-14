#include "../include/Sphere.hpp"
#include "../include/Point.hpp"
#include "../include/Vector.hpp"
#include "../include/Ray.hpp"

Sphere::Sphere(const Point & center, const double radius)
    : Shape(center, Vector(1, 0, 0)), radius(radius) {}


double Sphere::getRadius() const {
    return this->radius;
}


void Sphere::setRadius(double const radius) {
    this->radius = radius;
}


bool Sphere::isHitByRay(const Ray & ray) const {
    Vector oc = ray.getOrigin().getVectorTo(this->getCenter());

    double a = dot(ray.getDirection(), ray.getDirection());
    double b = 2.0 * dot(oc, ray.getDirection());
    double c = dot(oc, oc) - this->radius * this->radius;

    double delta = b * b - 4 * a * c;

    return delta > 0;
}