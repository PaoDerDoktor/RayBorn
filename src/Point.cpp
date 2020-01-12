#include "../include/Point.hpp"
#include "../include/Vector.hpp"

#include <iostream>

Point::Point(const Point & p) : TripletContainer( p) {}

Point::Point(const Point * p) : TripletContainer(*p) {}

double Point::getX() const {
    return this->operator[](0);
}

double Point::getY() const {
    return this->operator[](1);
}

double Point::getZ() const {
    return this->operator[](2);
}


void Point::setX(const double x) {
    this->operator[](0) = x;
}

void Point::setY(const double y) {
    this->operator[](1) = y;
}

void Point::setZ(const double z) {
    this->operator[](2) = z;
}


Vector Point::getVectorTo  (const Point & end  ) const {
    return Vector(
        end.getX() - this->getX(),
        end.getY() - this->getY(),
        end.getZ() - this->getZ()
    );
}

Vector Point::getVectorFrom(const Point & start) const {
    return Vector(
        this->getX() - start.getX(),
        this->getY() - start.getY(),
        this->getZ() - start.getZ()
    );
}

std::istream & operator >> (std::istream & is,       Point & p) {
    double stamp;
    
    is >> stamp;
    p.setX(stamp);
    
    is >> stamp;
    p.setY(stamp);
    
    is >> stamp;
    p.setZ(stamp);

    return is;
}

std::ostream & operator << (std::ostream & os, const Point & p) {
    os << "[" << p.getX() << ", " << p.getY() << ", " << p.getZ() << "]";
    return os;
}