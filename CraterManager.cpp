#include "CraterManager.h"
#include "Crater.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<Crater> CraterManager::craters;

void CraterManager::addCrater(Crater newCrater) {
    craters.push_back(newCrater);
}

void CraterManager::listCraters() {
    for (const Crater& crater : craters) {
        std::cout << "Crater Name: " << crater.getName() << ", X: " << crater.getX() << ", Y: " << crater.getY() << ", Radius: " << crater.getRadius() << std::endl;
    }
}

void CraterManager::numberOfCraters() {
    std::cout << "Number of craters: " << craters.size() << std::endl;
}

Crater CraterManager::findCraterByName(const std::string& name) {
    for (const Crater& crater : craters) {
        if (crater.getName() == name) {
            std::cout << "A(z) " << crater.getName() << " középpontja X=" << crater.getX() << " Y=" << crater.getY() << " sugara R=" << crater.getRadius() << std::endl;
            return crater;
        }
    }
    std::cout << "Nincs ilyen nevű kráter." << std::endl;
    return Crater(0, 0, 0, "");
}

void CraterManager::findLargestCrater() {

    const Crater* largestCrater = &craters[0];
    for (const Crater& crater : craters) {
        if (crater.getRadius() > largestCrater->getRadius()) {
            largestCrater = &crater;
        }
    }
    std::cout << "A legnagyobb kráter neve: " << largestCrater->getName() << ", sugara: " << largestCrater->getRadius() << std::endl;
}

double CraterManager::getDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void CraterManager::findOverlappingCraters(const std::string& name) {
    Crater crater = findCraterByName(name);
    std::vector<Crater> nonOverlappingCraters = CraterManager::craters;

    if (crater.getName() == "") {
        std::cout << "Nincs ilyen nevű kráter." << std::endl;
        return;
    }
    std::cout << "A(z) " << crater.getName() << " kráter átfedései:" << std::endl;
    for (const Crater& otherCrater : craters) {
        if (otherCrater.getName() != crater.getName()) {
            double distance = getDistance(crater.getX(), crater.getY(), otherCrater.getX(), otherCrater.getY());
            if (distance >= (crater.getRadius() + otherCrater.getRadius())) {
                nonOverlappingCraters.push_back(otherCrater);
            }
        }
    }
    std::cout << "Nincs közös része: ";
    size_t i = 0;
    size_t end = nonOverlappingCraters.size() - 1;
    while (i < end) {
        Crater nonOverlappingCrater = nonOverlappingCraters[i];
        std::cout << nonOverlappingCrater.getName() << ", ";
        ++i;
    }
    Crater nonOverlappingCrater = nonOverlappingCraters[i];
    std::cout << nonOverlappingCrater.getName() << "." << std::endl;
}

void CraterManager::findCratersInsideOtherCraters() {
    for (const Crater& crater : craters) {
        for (const Crater& otherCrater : craters) {
            if (crater.getName() != otherCrater.getName()) {
                double distance = getDistance(crater.getX(), crater.getY(), otherCrater.getX(), otherCrater.getY());
                if (distance <= (crater.getRadius() - otherCrater.getRadius())) {
                    std::cout << "A(z) " << crater.getName() << " kráter tartalmazza a(z) " << otherCrater.getName() << " krátert." << std::endl;
                }
            }
        }
    }
}

void CraterManager::createCraterAreaTextFile(){
    std::ofstream file("crater_radius.txt");
    const double PI = 3.14;
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
    for (const Crater& crater : craters) {
        double area = PI * pow(crater.getRadius(), 2);
        area = round(area * 100) / 100; // Round to 2 decimal places
        file << area << "\t" << crater.getName() << std::endl;
    }
    file.close();
}