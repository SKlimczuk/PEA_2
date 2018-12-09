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
    this->tabuList = new int*[size];
    this->cadency = 10;
    
    for(int i = 0; i < size; i++){
        tabuList[i] = new int[size];
        for(int k = 0; k < size; k++)
            tabuList[i][k] = 0;
    }
}

TabuList::~TabuList(){
    for(int i = 0; i < size; i++)
        delete[] tabuList[i];
    delete[] tabuList;
}

//void TabuList::addElement(){
//
//}
//
//void TabuList::addElement(){
//
//}

void TabuList::resetTabuList(){
    for(int i = 0; i < size; i++)
        for(int k = 0; k < size; k++)
            tabuList[i][k] = 0;
}
