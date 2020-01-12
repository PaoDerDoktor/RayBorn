#include "../include/TripletContainer.hpp"

#include <stdexcept>
#include <string>
#include <iostream>

TripletContainer::TripletContainer() : a(0), b(0), c(0) {};

TripletContainer::TripletContainer(double a, double b, double c) : a(a), b(b), c(c) {};
TripletContainer::TripletContainer(const TripletContainer & t) : a(t[0]), b(t[1]), c(t[2]) {};
TripletContainer::TripletContainer(double array[3]) : a(array[0]), b(array[1]), c(array[2]) {};


const TripletContainer & TripletContainer::operator + () const {
    return *this;
}

TripletContainer   TripletContainer::operator - () const {
    return TripletContainer (
        -this->a,
        -this->b,
        -this->c
    );
}

TripletContainer TripletContainer::operator + (const TripletContainer & t) const {
    return TripletContainer (
        this->a + t[0],
        this->b + t[1],
        this->c + t[2]
    );
}

TripletContainer TripletContainer::operator - (const TripletContainer & t) const {
    return TripletContainer (
        this->a - t[0],
        this->b - t[1],
        this->c - t[2]
    );
}

TripletContainer TripletContainer::operator * (const TripletContainer & t) const {
    return TripletContainer (
        this->a * t[0],
        this->b * t[1],
        this->c * t[2]
    );
}

TripletContainer TripletContainer::operator / (const TripletContainer & t) const {
    return TripletContainer (
        this->a / t[0],
        this->b / t[1],
        this->c / t[2]
    );
}


TripletContainer & TripletContainer::operator += (const TripletContainer & t) {
    this->a += t.a;
    this->b += t.b;
    this->c += t.c;
}

TripletContainer & TripletContainer::operator -= (const TripletContainer & t) {
    this->a -= t.a;
    this->b -= t.b;
    this->c -= t.c;
}


TripletContainer & TripletContainer::operator *= (const TripletContainer & t) {
    this->a *= t.a;
    this->b *= t.b;
    this->c *= t.c;
}

TripletContainer & TripletContainer::operator /= (const TripletContainer & t) {
    this->a /= t.a;
    this->b /= t.b;
    this->c /= t.c;
}


double   TripletContainer::operator[] (const int i) const {
    if (i > 2 || i < 0) {
        throw std::out_of_range("Triplet doesn't have any "+std::to_string(i)+"th element.");
    } else {
        return (i == 0) ? this->a : (i == 1) ? this->b : this->c;
    }
}

double & TripletContainer::operator[] (const int i)       {
    if (i > 2 || i < 0) {
        throw std::out_of_range("Triplet doesn't have any "+std::to_string(i)+"th element.");
    } else {
        return (i == 0) ? this->a : (i == 1) ? this->b : this->c;
    }
}


std::istream & operator >> (std::istream & is,       TripletContainer & t) {
    is >> t[0] >> t[1] >> t[2];
    return is;
}

std::ostream & operator << (std::ostream & os, const TripletContainer & t) {
    os << "[" << t[0] << ", " << t[1] << ", " << t[2] << "]";
    return os;
}