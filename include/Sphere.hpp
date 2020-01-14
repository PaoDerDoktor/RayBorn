#ifndef Sphere_H
#define Sphere_H

#include "Shape.hpp"
#include "Vector.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"

class Sphere : public Shape {
    private:
        double radius;

    public:
        Sphere(const Point & center, const double radius);

        double getRadius() const;

        void setRadius(const double radius);

        virtual bool isHitByRay(const Ray &ray) const;
};

#endif