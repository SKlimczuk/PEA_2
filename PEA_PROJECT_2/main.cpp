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

using namespace std;

void simulation(string filename);
void simulation(string filename, int cities);
vector<string> initVectorWithSimulationFiles();

int main(int argc, const char * argv[]) {
    
    string MAIN_MENU = "\n-----MENU-----\n1-read data from file\n2-taboo search alghoritm\n0-exit\nCHOICE: ";
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
                
            } break;
            case 2:
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
