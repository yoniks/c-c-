

/*
 
 Pre-existing header files: Files which are already available in C/C++ compiler we just need to import them, use #incloud <angled>
User-defined header files: These files are defined by the user and can be imported, use #include "quotes"
 ./= this path, ../go 1 folder,.../go 2 folder ,  example "../namefolder/name2.h".
 */


#include <iostream>

 #include "vvsr.h"

using namespace std;


int main(){
    char str[]="Hello word!";
    uuper_string_by_ref(str[0]);
   add_dash_to_space_by_value(str);// pointer first address
    cout<<str<<"\n";
    return 0;
}
