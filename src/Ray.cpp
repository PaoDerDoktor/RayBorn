#include "../include/Ray.hpp"

Ray::Ray(const Point & origin, const Vector & direction) : origin(origin), direction(direction) {}


Point  Ray::getOrigin()    const {
    return this->origin;
}

Vector Ray::getDirection() const {
    return this->direction;
}


void Ray::setOrigin   (const Point  & origin) {
    this->origin = origin;
}

void Ray::setDirection(const Vector & direction) {
    this->direction = direction;
}

Point Ray::pointAtParameter(const double t) const {
    return this->origin.getTranslation(this->direction * t);
}