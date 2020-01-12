#include "../include/DeciRGB.hpp"
#include "../include/RGBUtils.hpp"

#include <cmath>
#include <iostream>

DeciRGB::DeciRGB(const double r, const double g, const double b)
    : TripletContainer(
        (rbRGB::to1_0(r)),
        (rbRGB::to1_0(g)),
        (rbRGB::to1_0(b))
      ) {}
DeciRGB::DeciRGB(const int r, const int g, const int b)
    : TripletContainer(
        (rbRGB::to1_0(r)),
        (rbRGB::to1_0(g)),
        (rbRGB::to1_0(b))
      ) {}
DeciRGB::DeciRGB(const DeciRGB & drgb) : TripletContainer(drgb[0], drgb[1], drgb[2]) {}
DeciRGB::DeciRGB(const DeciRGB * drgb)
    : TripletContainer(
        drgb->operator[](0),
        drgb->operator[](1),
        drgb->operator[](2)
      ) {}


double DeciRGB::getR() const {
    return this->operator[](0);
}

double DeciRGB::getG() const {
    return this->operator[](1);
}

double DeciRGB::getB() const {
    return this->operator[](2);
}


void DeciRGB::setR(const double r) {
    this->operator[](0) = rbRGB::to1_0(r);
}

void DeciRGB::setG(const double g) {
    this->operator[](1) = rbRGB::to1_0(g);
}

void DeciRGB::setB(const double b) {
    this->operator[](2) = rbRGB::to1_0(b);
}


void DeciRGB::setR(const int r) {
    this->operator[](0) = rbRGB::to1_0(r);
}

void DeciRGB::setG(const int g) {
    this->operator[](1) = rbRGB::to1_0(g);
}

void DeciRGB::setB(const int b) {
    this->operator[](2) = rbRGB::to1_0(b);
}


DeciRGB DeciRGB::operator + (const DeciRGB & drgb) const {
    return DeciRGB(
        rbRGB::to1_0(this->getR() + drgb.getR()),
        rbRGB::to1_0(this->getG() + drgb.getG()),
        rbRGB::to1_0(this->getB() + drgb.getB())
    );
}

DeciRGB DeciRGB::operator - (const DeciRGB & drgb) const {
    return DeciRGB(
        rbRGB::to1_0(this->getR() - drgb.getR()),
        rbRGB::to1_0(this->getG() - drgb.getG()),
        rbRGB::to1_0(this->getB() - drgb.getB())
    );
}


DeciRGB DeciRGB::operator * (const double d) const {
    return DeciRGB(
        rbRGB::to1_0(this->getR() * d),
        rbRGB::to1_0(this->getG() * d),
        rbRGB::to1_0(this->getB() * d)
    );
}

DeciRGB DeciRGB::operator / (const double d) const {
    return DeciRGB(
        rbRGB::to1_0(this->getR() / d),
        rbRGB::to1_0(this->getG() / d),
        rbRGB::to1_0(this->getB() / d)
    );
}


void DeciRGB::operator += (const DeciRGB & drgb) {
    this->setR(rbRGB::to1_0(this->getR() + drgb.getR()));
    this->setG(rbRGB::to1_0(this->getG() + drgb.getG()));
    this->setB(rbRGB::to1_0(this->getB() + drgb.getB()));
}

void DeciRGB::operator -= (const DeciRGB & drgb) {
    this->setR(rbRGB::to1_0(this->getR() - drgb.getR()));
    this->setG(rbRGB::to1_0(this->getG() - drgb.getG()));
    this->setB(rbRGB::to1_0(this->getB() - drgb.getB()));
}


void DeciRGB::operator *= (const double d) {
    this->setR(rbRGB::to1_0(this->getR() * d));
    this->setG(rbRGB::to1_0(this->getG() * d));
    this->setB(rbRGB::to1_0(this->getB() * d));
}

void DeciRGB::operator /= (const double d) {
    this->setR(rbRGB::to1_0(this->getR() / d));
    this->setG(rbRGB::to1_0(this->getG() / d));
    this->setB(rbRGB::to1_0(this->getB() / d));
}


DeciRGB operator * (const double d, const DeciRGB & drgb) {
    return DeciRGB(
        drgb.getR() * d,
        drgb.getG() * d,
        drgb.getB() * d
    );
}


std::istream & operator >> (std::istream & is,       DeciRGB & drgb) {
    double stamp;
    
    is >> stamp;
    drgb.setR(stamp);
    
    is >> stamp;
    drgb.setG(stamp);
    
    is >> stamp;
    drgb.setB(stamp);

    return is;
}

std::ostream & operator << (std::ostream & os, const DeciRGB & drgb) {
    os << "[" << drgb.getR() << ", " << drgb.getG() << ", " << drgb.getB() << "]";
    return os;
}