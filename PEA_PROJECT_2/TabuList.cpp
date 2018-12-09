//
//  TabuList.cpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "TabuList.hpp"

TabuList::TabuList(){}

TabuList::TabuList(int size){
    this->size = size;
    this->tabuList = new int*[size];
    this->cadency = 10;
    
    for(int e = 0; e < size; e++){
        tabuList[e] = new int[size];
        for(int f = 0; f < size; f++)
            tabuList[e][f] = 0;
    }
}

TabuList::~TabuList(){
    for(int i = 0; i < size; i++)
        delete[] tabuList[i];
    delete[] tabuList;
}

void TabuList::addElement(int a, int b){
    tabuList[a][b] = cadency;
    tabuList[b][a] = cadency;
}

void TabuList::refreshTabuList(){
    for(int i = 0; i < size; i++)
        for(int k = 0; k < size; k++){
            if(tabuList[i][k] > 0)
                tabuList[i][k] -= 1;
        }
}

void TabuList::resetTabuList(){
    for(int i = 0; i < size; i++)
        for(int k = 0; k < size; k++)
            tabuList[i][k] = 0;
}

int** TabuList::getTabuList(){
    return this->tabuList;
}
