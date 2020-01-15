#ifndef Camera_H
#define Camera_H

#include "Point.hpp"
#include "Vector.hpp"
#include "Shape.hpp"
#include "Scene.hpp"
#include "Ray.hpp"

#include <string>

class Camera : public Shape {
    private:
           int         pxWidth;
           int        pxHeight;
         Point lowerLeftCorner;
        Vector         vpWidth;
        Vector        vpHeight;

    public :
        Camera(const Point & center, const Vector & direction, const int pxWidth, const int pxHeight,
               const Point & lowerLeftCorner, const Vector & vpWidth, const Vector & vpheight);

           int         getPxWidth() const;
           int        getPxHeight() const;
         Point getLowerLeftCorner() const;
        Vector         getVpWidth() const;
        Vector        getVpHeight() const;

        void        setPxWidth (const   int            pxWidth);
        void        setPxHeight(const   int           pxHeight);
        void setLowerLeftCorner(const Point  & lowerLeftCorner);
        void         setVpWidth(const Vector &         vpWidth);
        void        setVpHeight(const Vector &        vpHeight);

        void trace(const std::string & filename, const Scene & scene) const;

        virtual bool isHitByRay(const Ray & ray) const;
};

#endif