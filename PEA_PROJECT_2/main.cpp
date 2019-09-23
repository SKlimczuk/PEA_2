//
//  main.cpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

#include "Tabu.hpp"
#include "Annealing.hpp"

using namespace std;

void simulation(string filename);
void simulation(string filename, int cities);
vector<string> initVectorWithSimulationFiles();

int main(int argc, const char * argv[]) {
    
     srand(time( NULL ));
    
    Tabu *tabu = nullptr;
    Annealing *annealing = nullptr;
    
    string MAIN_MENU = "\n-----MENU-----\n1-read data from file\n2-display graph\n3-tabu search alghoritm\n4-simulated annealing alhorithm\n0-exit\nCHOICE: ";
    string FILE_MENU = "\ninsert file name: ";
    string TIME_CRITERIA = "TIME";
    string ITER_CRITERIA = "ITER";
    
    int choice;
    
    bool menuFlowCondition = true;
    
    do {
        
        do {
            cout << MAIN_MENU;
            cin >> choice;
        } while(0 > choice || choice > 4);
        
        switch (choice) {
            case 1:
            {
                //read data from file
                string filename;
                cout << FILE_MENU;
                cin >> filename;
                tabu = new Tabu(filename);
                annealing = new Annealing(filename);
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
                if(tabu != nullptr){
                    int criteriaChoose;
                    bool menuCriteriaFlowCondition = true;
                    do {
                        cout << "\n-----FINAL CRITERIA-----" << endl;
                        cout << "1-number of iterations\n2-time\n0-exit\nCHOICE: ";
                        cin >> criteriaChoose;
                        switch (criteriaChoose) {
                            case 1:{
                                int numOfIterations;
                                cout << "number of iterations: ";
                                cin >> numOfIterations;
                                tabu->tabuAlgorithm(ITER_CRITERIA, numOfIterations);
                            }break;
                            case 2:{
                                int numOfSeconds;
                                cout << "number of seconds: ";
                                cin >> numOfSeconds;
                                tabu->tabuAlgorithm(TIME_CRITERIA, numOfSeconds);
                            }break;
                            case 0:{
                                menuCriteriaFlowCondition = false;
                            }break;
                            default:
                                break;
                        }
                    }while(menuCriteriaFlowCondition);
                }
                else
                    cout << endl << "GRAPH IS NOT INITIALIZED" << endl;
            } break;
            case 4:
            {
                if(annealing != nullptr){
                    double temperatureMax;
                    double temperatureMin;
                    do{
                        cout << "-----TEMPERATURE-----" << endl;
                        cout << "pass min temperature: ";
                        cin >> temperatureMin;
                        cout << "pass max temperature: ";
                        cin >> temperatureMax;
                    }while (temperatureMax <= temperatureMin);
                    annealing->simulatedAnnealingAlgorithm(temperatureMax, temperatureMin);
                }
                else
                    cout << endl << "GRAPH IS NOT INITIALIZED" << endl;
            } break;
            case 0:
            {
                //exit
                if(tabu != nullptr)
                    tabu->~Tabu();
                if(annealing != nullptr)
                    annealing->~Annealing();
                menuFlowCondition = false;
            } break;
            default:
                break;
        }
    } while(menuFlowCondition);
    
    return 0;
}
