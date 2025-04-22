#include "Crater.h"
#include <string>

Crater::Crater(float newX, float newY, float newRadius, std::string newName){
    x = newX;
    y = newY;
    radius = newRadius;
    name = newName;
}

float Crater::getX() const {
    return x;
}

float Crater::getY() const {
    return y;
}

float Crater::getRadius() const {
    return radius;
}

std::string Crater::getName() const {
    return name;
}

void Crater::setX(float newX) {
    x = newX;
}

void Crater::setY(float newY) {
    y = newY;
}

void Crater::setRadius(float newRadius) {
    radius = newRadius;
}

void Crater::setName(const std::string& newName) {
    name = newName;
}