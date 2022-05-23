//
//  main.cpp
//  even_odd_map
//
//  Created by yo on 5/23/22.
//

#include <iostream>
#include "even_odd_map.h"
int main(int argc, const char * argv[]) {
    // we not allocate more memory to map becuse the library already allocate
    char str='d';
    even_odd_map<int, char> m_obj(str);
    m_obj.assign(0, 15, str);
   str='g';
     m_obj.assign(19, 25, str);// the value is not differnt that not add
  
   
    return 0;
}
