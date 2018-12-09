//
//  Tabu.cpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Tabu.hpp"

int** initializeMatrix(int **matrix, int limit);

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
    {
        delete[] graph[i];
    }
    
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
