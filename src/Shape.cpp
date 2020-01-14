#include "../include/Shape.hpp"
#include "../include/Vector.hpp"
#include "../include/Point.hpp"

Shape::Shape(const Point & center, const Vector & direction) : center(center), direction(direction) {}


Point  Shape::getCenter   () const {
    return this->center;
}

Vector Shape::getDirection() const {
    return this->direction;
}


void Shape::setCenter   (const Point  & center) {
    this->center = center;
}

void Shape::setDirection(const Vector & direction) {
    this->direction = direction;
}