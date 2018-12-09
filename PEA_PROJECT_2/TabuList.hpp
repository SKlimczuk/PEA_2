//
//  TabuList.hpp
//  PEA_PROJECT_2
//
//  Created by Szymon Klimczuk on 09/12/2018.
//  Copyright © 2018 Szymon Klimczuk. All rights reserved.
//

#ifndef TabuList_hpp
#define TabuList_hpp

#include <stdio.h>

class TabuList {
//private:
public:
    int **tabuList;
    int size;
    int cadency;
//public:
    TabuList();
    TabuList(int size);
    ~TabuList();

    void addElement(int a, int b);
    void refreshTabuList();
    void resetTabuList();
    
    int** getTabuList();
    
};
#endif /* TabuList_hpp */
