#ifndef CRATER_H
#define CRATER_H
#include <string>

class Crater {
    public:
        float x;
        float y;
        float radius;
        std::string name;
        Crater(float newX, float newY, float newRadius, std::string newName);
        float getX() const;
        float getY() const;
        float getRadius() const;
        std::string getName() const;
        void setX(float newX);
        void setY(float newY);
        void setRadius(float newRadius);
        void setName(const std::string& newName);
};

#endif // CRATER_H
