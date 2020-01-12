#ifndef DeciRGB_H
#define DeciRGB_H

#include "TripletContainer.hpp"

#include <cmath>
#include <iostream>

class DeciRGB : private TripletContainer {
    public:
        DeciRGB(const double r, const double g, const double b);
        DeciRGB(const int r, const int g, const int b);
        DeciRGB(const DeciRGB & drgb);
        DeciRGB(const DeciRGB * drgb);

        double getR() const;
        double getG() const;
        double getB() const;

        void setR(const double r);
        void setG(const double g);
        void setB(const double b);

        void setR(const int r);
        void setG(const int g);
        void setB(const int b);

        DeciRGB operator + (const DeciRGB & drgb) const;
        DeciRGB operator - (const DeciRGB & drgb) const;

        DeciRGB operator * (const double d) const;
        DeciRGB operator / (const double d) const;

        void operator += (const DeciRGB & drgb);
        void operator -= (const DeciRGB & drgb);

        void operator *= (const double d);
        void operator /= (const double d);
};

DeciRGB operator * (const double d, const DeciRGB & drgb);

std::istream & operator >> (std::istream & is,       DeciRGB & drgb);
std::ostream & operator << (std::ostream & os, const DeciRGB & drgb);

#endif