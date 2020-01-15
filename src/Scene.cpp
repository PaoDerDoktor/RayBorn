#include "../include/Scene.hpp"
#include "../include/Ray.hpp"
#include "../include/Shape.hpp"

#include <vector>

Scene::Scene(const std::vector<Shape *> & shapes) : shapes(shapes) {}
Scene::Scene() : shapes(std::vector<Shape *>()) {}


std::vector<Shape *> Scene::getShapes() const {
    return this->shapes;
}

int                Scene::getSize()   const {
    return this->shapes.size();
}


void Scene::setShapes(const std::vector<Shape *> & shapes) {
    this->shapes = shapes;
}


Shape * Scene::operator [] (int i) {
    return this->shapes[i];
}


void Scene::addShape(Shape * shape) {
    this->shapes.push_back(shape);
}


Shape * Scene::removeShape(const int i) {
    Shape * stamp = this->shapes[i];
    this->shapes.erase(this->shapes.begin() + i);
    
    return stamp;
}


bool Scene::hitTest(const Ray & ray) const {
    for (int i = 0 ; i < this->shapes.size() ; i < i++) {
        if (this->shapes[i]->isHitByRay(ray)) {
            return true;
        }
    }
    return false;
}