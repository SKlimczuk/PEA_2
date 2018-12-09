//
//  Tabu.cpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Tabu.hpp"

int** initializeMatrix(int **matrix, int limit);
int calculateCost(int **graph, int *arr, int limit);
void displayResult(int* arr, int limit, int cost);

Tabu::Tabu(string filename){
    ifstream file;
    file.open(filename.c_str());
    
    if(!file.good())
        cout << endl << filename << ": INCORRECT FILE !" << endl;
    else
    {
        cout << endl << filename << ": CORRECT FILE !" << endl;
        
        file >> this->cities;
        
        graph = new int*[cities];
        graph = initializeMatrix(graph, cities);
        
        int weight;
        for(int i = 0; i < cities; i++){
            for(int k = 0; k < cities; k++){
                file >> weight;
                graph[i][k] = weight;
            }
        }
        
        file.close();
        
        cout << "\nCITIES:" << cities << endl;
    }
}

Tabu::~Tabu(){
    for(int i = 0; i < cities; i++)
        delete[] graph[i];
    delete[] graph;
}

void Tabu::displayGraph(){
    for(int i = 0; i < cities; i++){
        for(int k = 0; k < cities; k++){
            cout << setw(4) << graph[i][k] << " ";
        }
        cout << endl;
    }
}

void Tabu::tabuAlgorithm(){
    tempBestPath = new int[cities];
    bestPath = new int[cities];
    tabuList = new TabuList(cities);
    bestCost = INT_MAX;
    Swap bestSwap;
    
    //tymczasowe kryterium zakonczenia
    //TODO: zastanowic sie jak je pozniej ustalac zaleznie od problemu
    int iterationsCriteria = 10000000;
    
    //losowa sciezka startowa i jej przypisanie jako optymalna
    tempBestPath = setTempBestPath();
    bestPath = setBestPath();
    
    //glowna petla algorytmu zalezna od kryterium koncowego
    for(int i = 0; i < iterationsCriteria; i++)
    {
        //funkcja oceny wartosci ruchu
        bestSwap = findBestSwap();
        swap(bestSwap.getA(),bestSwap.getB());
        //porowananiu wynikow
        if(calculateCost(graph, tempBestPath, cities) < bestCost){
            bestCost = calculateCost(graph, tempBestPath, cities);
            bestPath = setBestPath();
        }
        
        if(bestSwap.getA() != 0 && bestSwap.getB() != 0){
            tabuList->addElement(bestSwap.getA(), bestSwap.getB());
            tabuList->refreshTabuList();
        }
    }
    displayResult(bestPath, cities, bestCost);
    
    tabuList->resetTabuList();
    
    delete[] tempBestPath;
    delete[] bestPath;
}

int* Tabu::setBestPath(){
    for(int i = 0; i < cities; i++)
        bestPath[i] = tempBestPath[i];
    return bestPath;
}

int* Tabu::setTempBestPath(){
    tempBestPath[0] = 0;
    tempBestPath[cities] = 0;
    for(int i = 1; i < cities; i++)
        tempBestPath[i] = i;
    return tempBestPath;
}

void Tabu::swap(int x, int y){
    int tmp = tempBestPath[x];
    tempBestPath[x] = tempBestPath[y];
    tempBestPath[y] = tmp;
}

Swap Tabu::findBestSwap(){
    Swap bestSwap;
    int bestSwapCost = INT_MAX;
    
    for (int x = 1; x < cities; x++) {
        for (int y = 1; y < cities; y++) {
            if(x != y){
                swap(x, y);
                tempBestCost = calculateCost(graph, tempBestPath, cities);
                if(tabuList->tabuList[bestSwap.getA()][bestSwap.getB()] == 0 && (tempBestCost-bestCost) < bestSwapCost){
                    bestSwapCost = tempBestCost - bestCost;
                    bestSwap.setA(x);
                    bestSwap.setB(y);
                }
            }
            swap(y,x);
        }
    }
    return bestSwap;
}

//----------------------------------------------class methods
int** initializeMatrix(int **matrix, int limit)
{
    for(int i = 0; i < limit; i++){
        matrix[i] = new int[limit];
        for(int k = 0; k < limit; k++)
            matrix[i][k] = 0;
    }
    return matrix;
}

int calculateCost(int** graph, int* arr, int limit){
    int sum = 0;
    for(int i = 0; i < limit; i++)
        sum += graph[arr[i]][arr[i+1]];
    return sum;
}

void displayResult(int* arr, int limit, int cost){
    cout << "\nCOST: " << cost << endl;
    cout << "PATH: ";
    for(int i = 0; i < limit; i++)
        cout << setw(2) << arr[i] << " ->";
    cout << setw(3) << arr[limit] << endl;
}
