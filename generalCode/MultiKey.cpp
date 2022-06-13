//
//  main.cpp
//  Spider_Search
//
//  Created by $ on 4/11/22.
//

#include <iostream>
#include <map>
#include <new>
#include "Template.h"
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
  

   /* News<string,30> *pn;
    try {//TData<char,30>
        pn= new TData<string,30>();
    } catch (bad_alloc xa) {
        cout<<"allocation Failure\n";
        return 1;
    }*/
    string *pStr;
    int *pInt;
     try {//News<char,30>
         pStr= new string;
         pInt= new int;
     } catch (bad_alloc xa) {
         cout<<"allocation Failure\n";
         return 1;
     }
   
    *pStr="id-123";
    *pInt=456;
      //key str     value int
    Country<string, int> obj0(*pStr,to_string(*pInt));
    obj0.setValueInt(111);
    cout<<"resultr: "<<obj0.getIntBy2Key(*pStr,to_string(*pInt))<<"\n";
    
    
    Country<string, string> obj1(to_string(1),to_string(*pInt));
    obj1.setValueString("yoni");
    cout<<"result: "<<obj1.getStrBy2Key(to_string(1),to_string(*pInt))<<"\n";
   
    
    Country<string, int> obj3(*pStr);
     obj3.setValueInt(222);
     cout<<"resultr: "<<obj3.getIntBy1Key(*pStr)<<"\n";

    delete pStr;
    delete pInt;
    return 0;
}
