#ifndef Point_H
#define Point_H

#include "TripletContainer.hpp"
#include "Vector.hpp"

class Vector;

#include <iostream>

class Point : private TripletContainer {
    public:
        Point(const Point & p);
        Point(const Point * p);

        double getX() const;
        double getY() const;
        double getZ() const;

        void setX(const double x);
        void setY(const double y);
        void setZ(const double z);

        Vector getVectorTo  (const Point & end  ) const;
        Vector getVectorFrom(const Point & start) const;
};

std::istream & operator >> (std::istream & is,       Point & p);
std::ostream & operator << (std::ostream & os, const Point & p);

#endif