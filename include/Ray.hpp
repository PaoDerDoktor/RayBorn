#ifndef Ray_H
#define Ray_H

#include "Point.hpp"
#include "Vector.hpp"

class Ray {
    private:
        Point origin;
        Vector direction;
    
    public:
        Ray(const Point & origin, const Vector & direction);

        Point  getOrigin()    const;
        Vector getDirection() const;

        void setOrigin   (const Point  & origin);
        void setDirection(const Vector & direction);

        Point pointAtParameter(const double t) const;
};

#endif