#ifndef Shape_H
#define Shape_H

#include "Ray.hpp"
#include "Point.hpp"
#include "Vector.hpp"

class Shape {
    private:
        Point  center;
        Vector direction;

    public :
        Shape(const Point & center, const Vector & direction);

        Point  getCenter   () const;
        Vector getDirection() const;

        void setCenter   (const Point & center);
        void setDirection(const Vector & direction);

        virtual bool isHitByRay(const Ray & ray) const = 0;
};

#endif