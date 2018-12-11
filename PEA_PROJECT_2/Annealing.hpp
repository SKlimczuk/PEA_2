//
//  Annealing.hpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 11/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Annealing_hpp
#define Annealing_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <cmath>
#include <algorithm>

using namespace std;

class Annealing {
private:
    //ilosc miast (wierzcholkow)
    int cities;
    //graf w postaci macierzy sasiedztwa
    int **graph;
    //sciezka i waga optymalnego rozwiazania
    int *bestPath;
    int bestCost;
    //sciezka i waga optymalnego rozwiazania tymczasowego
    int *tempBestPath;
    int tempBestCost;
    
    //temperatura max
    double temperatureMax;
    //temperatira min
    double temperatureMin;
public:
    Annealing();
    Annealing(string filename);
    ~Annealing();
    
    double decreaseTemperature();
    void simulatedAnnealingAlgorithm(double temperatureMax, double temperatureMin);
    
    int* setBestPath();
    int* setTempBestPath();
    
    int* generateRandomSwap(int* path);
    double generateProbability(int temperature, int* pathA, int* pathB);
};

#endif /* Annealing_hpp */
