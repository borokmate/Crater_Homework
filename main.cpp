#include "Crater.h"
#include "CraterManager.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>
#include <limits>

void ReadLinesFromFile(const std::string& filename);
void Split(const std::string& str, char delimiter, std::vector<std::string>& tokens);
void WaitForEnter();

int main(){
    
    std::string filename = "3_Kraterek/felszin_tpont.txt";
    std::string craterName;
    SetConsoleOutputCP(CP_UTF8);

    ReadLinesFromFile(filename);
    
    std::cout << "2. feladat" << std::endl;
    CraterManager::numberOfCraters();

    std::cout << "3. feladat" << std::endl;
    std::cout << "Kérem a kráter nevét: ";
    std::getline(std::cin, craterName);
    CraterManager::findCraterByName(craterName);

    std::cout << "4. feladat" << std::endl;
    CraterManager::findLargestCrater();

    std::cout << "6. feladat" << std::endl;
    std::cout << "Kérem a kráter nevét: ";
    std::getline(std::cin, craterName);
    CraterManager::findOverlappingCraters(craterName);

    std::cout << "7. feladat" << std::endl;
    CraterManager::findCratersInsideOtherCraters();

    CraterManager::createCraterAreaTextFile();

    std::cout << "\nA program véget ért. Nyomjon meg egy billentyűt a kilépéshez.";
    WaitForEnter();
    std::cout << "\nKilépés..." << std::endl;

    return 0; 
}

void ReadLinesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<std::string> tokens;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    while (std::getline(file, line)) {
        Split(line, '\t', tokens);
        if (tokens.size() >= 4) {
            float x = std::stof(tokens[0]);
            float y = std::stof(tokens[1]);
            float radius = std::stof(tokens[2]);
            std::string name = tokens[3];

            Crater crater(x, y, radius, name);
            CraterManager::addCrater(crater);
        } else {
            std::cerr << "Invalid line format: " << line << std::endl;
        }
        tokens.clear();
    }

    file.close();
}

void Split(const std::string& str, char delimiter, std::vector<std::string>& tokens) {
    size_t start = 0;
    size_t end = str.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start, end));
}

void WaitForEnter() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;

    GetConsoleMode(hStdin, &mode);

    SetConsoleMode(hStdin, mode & ~(DWORD)ENABLE_ECHO_INPUT);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    SetConsoleMode(hStdin, mode);
}