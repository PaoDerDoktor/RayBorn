#include "../include/Camera.hpp"
#include "../include/Point.hpp"
#include "../include/Vector.hpp"
#include "../include/Shape.hpp"
#include "../include/Scene.hpp"
#include "../include/Ray.hpp"

#include <string>
#include <fstream>
#include <iostream>

Camera::Camera(const Point & center, const Vector & direction, const int pxWidth, const int pxHeight,
                const Point & lowerLeftCorner, const Vector & vpWidth, const Vector & vpHeight)
    : Shape(center, direction), pxWidth(pxWidth), pxHeight(pxHeight),
      lowerLeftCorner(lowerLeftCorner), vpWidth(vpWidth), vpHeight(vpHeight) {}


   int         Camera::getPxWidth() const {
    return this->pxWidth;
}

   int        Camera::getPxHeight() const {
    return this->pxHeight;
}

 Point Camera::getLowerLeftCorner() const {
    return this->lowerLeftCorner;
}

Vector         Camera::getVpWidth() const {
    return this->vpWidth;
}

Vector        Camera::getVpHeight() const {
    return this->vpHeight;
}


void         Camera::setPxWidth(const    int           pxWidth) {
    this->pxWidth = pxWidth;
}

void        Camera::setPxHeight(const    int          pxHeight) {
    this->pxHeight = pxHeight;
}

void Camera::setLowerLeftCorner(const  Point & lowerLeftCorner) {
    this->lowerLeftCorner = lowerLeftCorner;
}

void         Camera::setVpWidth(const Vector &         vpWidth) {
    this->vpWidth = vpWidth;
}

void        Camera::setVpHeight(const Vector &        vpHeight) {
    this->vpHeight = vpHeight;
}


void Camera::trace(const std::string & filename, const Scene & scene) const {
    std::ofstream imageFile;
    imageFile.open(filename);

    imageFile << "P3\n" << this->pxWidth << " " << this->pxHeight << "\n255\n";

    for (int y = this->pxHeight - 1 ; y >= 0 ; y--) {
        for (int x = 0 ; x < this->pxWidth ; x++) {
            double u = double(x) / this->pxWidth;
            double v = double(y) / this->pxHeight;

            Ray r(this->getCenter(),
                  this->lowerLeftCorner.getTranslation(this->vpWidth*u + this->vpHeight*v)
                  .getVectorFrom(this->getCenter()));

            (scene.hitTest(r)) ? (imageFile << "255 000 000\n") : (imageFile << "255 255 255\n");
        }
    }
}


bool Camera::isHitByRay(const Ray & ray) const {
    return false;
}