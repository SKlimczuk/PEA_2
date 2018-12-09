//
//  Swap.cpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#include "Swap.hpp"

Swap::Swap(){
    this->a = 0;
    this->b = 0;
}

Swap::~Swap(){}

int Swap::getA(){
    return this->a;
}

int Swap::getB(){
    return this->b;
}

void Swap::setA(int a){
    this->a = a;
}

void Swap::setB(int b){
    this->b = b;
}
