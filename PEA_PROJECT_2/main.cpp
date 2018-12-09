//
//  main.cpp
//  PEA_PROJECT_1
//
//  Created by Szymon Klimczuk on 20/10/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>

#include "Tabu.hpp"

using namespace std;

void simulation(string filename);
void simulation(string filename, int cities);
vector<string> initVectorWithSimulationFiles();

int main(int argc, const char * argv[]) {
    
    Tabu *tabu = nullptr;
    
    string MAIN_MENU = "\n-----MENU-----\n1-read data from file\n2-display matrix\n3-tabu search alghoritm\n0-exit\nCHOICE: ";
    string FILE_MENU = "\ninsert file name: ";
    string TSP_FAIL = "\ngraph is not initialized !\n";
    
    int choice;
    
    bool menuFlowCondition = true;
    
    do {
        
        do {
            cout << MAIN_MENU;
            cin >> choice;
        } while(0 > choice || choice > 3 );
        
        switch (choice) {
            case 1:
            {
                //read data from file
                string filename;
                cout << FILE_MENU;
                cin >> filename;
                tabu = new Tabu(filename);
            } break;
            case 2:
            {
                if(tabu != nullptr)
                    tabu->displayGraph();
                else
                    cout << endl << "GRAPH IS NOT INITIALIZED" << endl;
            } break;
            case 3:
            {
            } break;
            case 0:
            {
                //exit
                menuFlowCondition = false;
            } break;
            default:
                break;
        }
    } while(menuFlowCondition);
    
    return 0;
}
