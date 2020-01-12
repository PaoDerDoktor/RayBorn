#ifndef TripletContainer_H
#define TripletContainer_H

#include <iostream>

class TripletContainer {
    private:
        double a;
        double b;
        double c;

    public:
        TripletContainer();

        TripletContainer(double a, double b, double c);
        TripletContainer(const TripletContainer & t);
        TripletContainer(double array[3]);


        const TripletContainer & operator +  () const;
              TripletContainer   operator -  () const;

        TripletContainer operator + (const TripletContainer & t) const;
        TripletContainer operator - (const TripletContainer & t) const;
        TripletContainer operator * (const TripletContainer & t) const;
        TripletContainer operator / (const TripletContainer & t) const;

        TripletContainer & operator += (const TripletContainer & t);
        TripletContainer & operator -= (const TripletContainer & t);
        TripletContainer & operator *= (const TripletContainer & t);
        TripletContainer & operator /= (const TripletContainer & t);

        double   operator[] (const int i) const;
        double & operator[] (const int i);
};


std::istream & operator >> (std::istream & is,       TripletContainer & t);
std::ostream & operator << (std::ostream & os, const TripletContainer & t);

#endif