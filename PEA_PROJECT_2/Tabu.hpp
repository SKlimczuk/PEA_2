//
//  Tabu.hpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef Tabu_hpp
#define Tabu_hpp

#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <sstream>

#include "TabuList.hpp"

using namespace std;

class Tabu {
private:
    //ilosc miast (wierzcholkow)
    int cities;
    //graf w postaci macierzy sasiedztwa
    int **graph;
    //sciezka i waga optymalnego rozwiazania
    int *bestPath;
    int bestScore;
    //sciezka i waga optymalnego rozwiazania tymczasowego
    int *tempBestPath;
    int tempBestScore;
    //lista tabu
    TabuList *tabuList;
 
public:
    Tabu();
    Tabu(string filename);
    ~Tabu();
    
    void displayGraph();
    void tabuAlgorithm();
    
    int *setBestPath();
    int *setTempBestPath();
    
    void swap(int x, int y);
};

#endif /* Tabu_hpp */
