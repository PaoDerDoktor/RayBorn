#include "../include/RGB.hpp"
#include "../include/DeciRGB.hpp"
#include "../include/RGBUtils.hpp"

RGB::RGB(const DeciRGB & drgb)
    : r(rbRGB::to255_0(drgb.getR())), g(rbRGB::to255_0(drgb.getG())), b(rbRGB::to255_0(drgb.getB())) {}
RGB::RGB(const int r, const int g, const int b) : r(r%256), g(g%256), b(b%256) {}
RGB::RGB(const RGB & rgb) : r(rgb.r),  g(rgb.g),  b(rgb.b)  {}
RGB::RGB(const RGB * rgb) : r(rgb->r), g(rgb->g), b(rgb->b) {}


int RGB::getR() const {
    return this->r;
}

int RGB::getG() const {
    return this->g;
}

int RGB::getB() const {
    return this->b;
}


void RGB::setR(const int r) {
    this->r = r%256;
}

void RGB::setG(const int g) {
    this->g = g%256;
}

void RGB::setB(const int b) {
    this->b = b%256;
}


void RGB::setR(const double r) {
    this->r = rbRGB::to255_0(r);    
}

void RGB::setG(const double g) {
    this->g = rbRGB::to255_0(g);
}

void RGB::setB(const double b) {
    this->b = rbRGB::to255_0(b);
}


std::istream & operator >> (std::istream & is,       RGB & rgb) {
    int stamp;

    is >> stamp;
    rgb.setR(stamp);
    
    is >> stamp;
    rgb.setG(stamp);
    
    is >> stamp;
    rgb.setB(stamp);
    
    return is;
}

std::ostream & operator << (std::ostream & os, const RGB & rgb) {
    os << "[" << rgb.getR() << ", " << rgb.getG() << ", " << rgb.getB() << "]";
    return os;
}