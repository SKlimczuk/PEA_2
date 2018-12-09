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

using namespace std;

class Tabu {
private:
    int cities;
    int **graph;
public:
    Tabu();
    Tabu(string filename);
    ~Tabu();
    
    void displayGraph();
};

#endif /* Tabu_hpp */
