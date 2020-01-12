#ifndef RGB_H
#define RGB_H

#include "TripletContainer.hpp"
#include "DeciRGB.hpp"

#include <iostream>

class RGB {
    private:
        int r;
        int g;
        int b;

    public :
        RGB(const DeciRGB & drgb);
        RGB(int r, int g, int b);
        RGB(const RGB & rgb);
        RGB(const RGB * rgb);

        int getR() const;
        int getG() const;
        int getB() const;

        void setR(const int r);
        void setG(const int g);
        void setB(const int b);

        void setR(const double r);
        void setG(const double g);
        void setB(const double b);
};

std::istream & operator >> (std::istream & is,       RGB & rgb);
std::ostream & operator << (std::ostream & os, const RGB & rgb);

#endif