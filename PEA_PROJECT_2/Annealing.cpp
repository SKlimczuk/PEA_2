//
//  Annealing.cpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 11/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Annealing.hpp"

int calculateCostSA(int **graph, int *arr, int limit);
void displayResultSA(int* arr, int limit, int cost);
int* copyPath(int* path, int limit);

Annealing::Annealing(){}

Annealing::Annealing(string filename){
    ifstream file;
    file.open(filename.c_str());
    
//    if(!file.good())
//        cout << endl << filename << ": INCORRECT FILE !" << endl;
//    else
//    {
//        cout << endl << filename << ": CORRECT FILE !" << endl;
    
        file >> this->cities;
        
        graph = new int*[cities];
        for(int i = 0; i < cities; i++){
            graph[i] = new int[cities];
            for(int k = 0; k < cities; k++)
                graph[i][k] = 0;
        }
        
        int weight;
        for(int i = 0; i < cities; i++){
            for(int k = 0; k < cities; k++){
                file >> weight;
                graph[i][k] = weight;
            }
        }
        file.close();
//        cout << "\nCITIES:" << cities << endl;
//    }
}

Annealing::~Annealing(){
    for(int i = 0; i < cities; i++)
        delete[] graph[i];
    delete[] graph;
}

void Annealing::simulatedAnnealingAlgorithm(double temperatureMax, double temperatureMin){
    tempBestPath = new int[cities];
    bestPath = new int[cities];
    bestCost = INT_MAX;
    
    //losowa sciezka startowa i jej przypisanie jako optymalna
    tempBestPath = setTempBestPath();
    bestPath = setBestPath();
    
    while(temperatureMax > temperatureMin){
        int *temp = generateRandomSwap(tempBestPath);
        if(((double) rand() / (RAND_MAX)) < generateProbability(temperatureMax, temp, tempBestPath)){
            tempBestPath = copyPath(temp, cities);
            if(calculateCostSA(graph, tempBestPath, cities) < bestCost){
                bestCost = calculateCostSA(graph, tempBestPath, cities);
                bestPath = setBestPath();
            }
        }
        temperatureMax = temperatureMax*0.95;
    }
    displayResultSA(bestPath, cities, bestCost);
    
    delete[] tempBestPath;
    delete[] bestPath;
}

int* Annealing::setBestPath(){
    for(int i = 0; i < cities; i++)
        bestPath[i] = tempBestPath[i];
    return bestPath;
}

int* Annealing::setTempBestPath(){
    tempBestPath[0] = 0;
    tempBestPath[cities] = 0;
    for(int i = 1; i < cities; i++)
        tempBestPath[i] = i;
    return tempBestPath;
}

int* Annealing::generateRandomSwap(int *path){
    int randomA;
    int randomB;
    do{
        randomA = rand() % cities;
        randomB = rand() % cities;
    } while (randomA == randomB && randomA != 0 && randomB != 0);
    
    double temp = path[randomA];
    path[randomA] = path[randomB];
    path[randomB] = temp;
    
    return path;
}

double Annealing::generateProbability(int temperature, int* pathA, int* pathB){
    int diff = calculateCostSA(graph, pathA, cities)-calculateCostSA(graph, pathB, cities);
    int exponanta = exp((-1)*diff/temperature);
    return min(1,exponanta);
}

int calculateCostSA(int** graph, int* arr, int limit){
    int sum = 0;
    for(int i = 0; i < limit; i++)
        sum += graph[arr[i]][arr[i+1]];
    return sum;
}

void displayResultSA(int* arr, int limit, int cost){
    cout << "\nCOST: " << cost << endl;
    cout << "PATH: ";
    for(int i = 0; i < limit; i++)
        cout << setw(2) << arr[i] << " ->";
    cout << setw(3) << arr[limit] << endl;
}

int* copyPath(int* path, int limit){
    int *temp = new int[limit];
    for(int i = 0; i < limit; i++)
        temp[i] = path[i];
    temp[limit] = 0;
    return temp;
}

