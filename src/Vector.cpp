#include "../include/Vector.hpp"
#include "../include/TripletContainer.hpp"

#include <cmath>
#include <iostream>

Vector::Vector(const Vector & v) : TripletContainer( v) {}
Vector::Vector(const Vector * v) : TripletContainer(*v) {}
Vector::Vector(const double a, const double b, const double c) : TripletContainer(a, b, c) {}
Vector::Vector(const Point &start, const Point & end) : Vector(start.getVectorTo(end)) {}


double Vector::getX() const {
    return this->operator[](0);
}

double Vector::getY() const {
    return this->operator[](1);
}

double Vector::getZ() const {
    return this->operator[](2);
}


void Vector::setX(const double x) {
    this->operator[](0) = x;
}

void Vector::setY(const double y) {
    this->operator[](1) = y;
}

void Vector::setZ(const double z) {
    this->operator[](2) = z;
}


double Vector::getLength() const {
    return sqrt(
        this->getX() * this->getX() +
        this->getY() * this->getY() +
        this->getZ() * this->getZ()
    );
}

double Vector::getSquaredLength() const {
    return (
        this->getX() * this->getX() +
        this->getY() * this->getY() +
        this->getZ() * this->getZ()
    );
}


void Vector::makeUnit() {
    double l = this->getLength();
    this->setX(this->getX() / l);
    this->setY(this->getY() / l);
    this->setZ(this->getZ() / l);
}

Vector Vector::getUnit() const {
    return Vector(this);
}


Vector Vector::operator + (const Vector & v) const {
    return Vector(
        this->getX() + v.getX(),
        this->getY() + v.getY(),
        this->getZ() + v.getZ()
    );
}

Vector Vector::operator - (const Vector & v) const {
    return Vector(
        this->getX() - v.getX(),
        this->getY() - v.getY(),
        this->getZ() - v.getZ()
    );
}

Vector Vector::operator * (const Vector & v) const {
    return Vector(
        this->getX() * v.getX(),
        this->getY() * v.getY(),
        this->getZ() * v.getZ()
    );
}

Vector Vector::operator / (const Vector & v) const {
    return Vector(
        this->getX() / v.getX(),
        this->getY() / v.getY(),
        this->getZ() / v.getZ()
    );;
}

Vector Vector::operator / (const double t) const {
    return Vector(
        this->getX() / t,
        this->getY() / t,
        this->getZ() / t
    );
}

Vector Vector::operator * (const double t) const {
    return Vector(
        this->getX() * t,
        this->getY() * t,
        this->getZ() * t
    );
}


double Vector::dot  (const Vector & v) const {
    return (
        this->getX() * v.getX() +
        this->getY() * v.getY() +
        this->getZ() * v.getZ()
    );
}

Vector Vector::cross(const Vector & v) const {
    return Vector(
        this->getY() * v.getZ() - this->getZ() * v.getY(),
        this->getX() * v.getZ() - this->getZ() * v.getX(),
        this->getX() * v.getY() - this->getY() * v.getX()
    );
}


double dot  (const Vector & v1, const Vector & v2) {
    return v1.dot(v2);
}

Vector cross(const Vector & v1, const Vector & v2) {
    return v1.cross(v2);
}


std::istream & operator >> (std::istream & is,       Vector & v) {
    is >> v[0] >> v[1] >> v[2];
    return is;
}

std::ostream & operator << (std::ostream & os, const Vector & v) {
    os << "[" << v[0] << ", " << v[1] << ", " << v[2] << "]";
    return os;
}