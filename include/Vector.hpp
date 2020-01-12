#ifndef Vector_H
#define Vector_H

#include "TripletContainer.hpp"
#include "Point.hpp"

class Point;

class Vector : public TripletContainer {
    public:
        Vector(const Vector & v);
        Vector(const Vector * v);
        Vector(const double a, const double b, const double c);
        Vector(const Point & start, const Point & end);

        double getX() const;
        double getY() const;
        double getZ() const;

        void setX(const double x);
        void setY(const double y);
        void setZ(const double z);

        double getLength()        const;
        double getSquaredLength() const;
    
        void   makeUnit();
        Vector getUnit() const;

        Vector operator + (const Vector & v) const;
        Vector operator - (const Vector & v) const;
        Vector operator * (const Vector & v) const;
        Vector operator / (const Vector & v) const;

        Vector operator / (const double t) const;
        Vector operator * (const double t) const;

        void operator /= (const double t);
        void operator *= (const double t);

        double dot   (const Vector & v) const;
        Vector cross (const Vector & v) const;
};


Vector operator * (const double t, const Vector & v);

double dot   (const Vector & v1, const Vector & v2);
Vector cross (const Vector & v1, const Vector & v2);

std::istream & operator >> (std::istream & is,       Vector & v);
std::ostream & operator << (std::ostream & os, const Vector & v);

#endif