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
private:
    int **tabuList;
    int size;
    int cadency;
public:
    TabuList();
    TabuList(int size);
    ~TabuList();

    void addElement();
    void removeElement();
    void resetTabuList();
    
};
#endif /* TabuList_hpp */
