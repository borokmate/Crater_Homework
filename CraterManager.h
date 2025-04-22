#ifndef CRATERMANAGER_H
#define CRATERMANAGER_H
#include "Crater.h"
#include <vector>
#include <string>
#include <cmath>

class CraterManager {
    public:
        static void addCrater(Crater newCrater);
        static void listCraters();
        static void numberOfCraters();
        static Crater findCraterByName(const std::string& name);
        static void findLargestCrater();
        static double getDistance(double x1, double y1, double x2, double y2);
        static void findOverlappingCraters(const std::string& name);
        static void findCratersInsideOtherCraters();
        static void createCraterAreaTextFile();
    private:
        static std::vector<Crater> craters;
};

#endif // CRATERMANAGER_H
