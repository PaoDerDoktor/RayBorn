
#ifndef Scene_H
#define Scene_H

#include "Shape.hpp"
#include "Ray.hpp"

#include <vector>

class Scene {
    private:
        std::vector<Shape *> shapes;
    
    public:
        Scene(const std::vector<Shape  *> & shapes);
        Scene();

        std::vector<Shape *> getShapes() const;
        int                  getSize()   const;

        void setShapes(const std::vector<Shape *> & shapes);

        Shape * operator [] (int i);

        void addShape(Shape * shape);

        Shape * removeShape(const int i);

        bool hitTest(const Ray & ray) const;
};

#endif