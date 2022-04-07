

/*
 
 Pre-existing header files: Files which are already available in C/C++ compiler we just need to import them, use #incloud <angled>
User-defined header files: These files are defined by the user and can be imported, use #include "quotes"
 ./= this path, ../go 1 folder,.../go 2 folder ,  example "../namefolder/name2.h".
 */


#include <iostream>

 #include "vvsr.h"

using namespace std;
void neg(&x);

int main(){
    char str[]="Hello word!";
 //Call-by-reference passes the address of the argument to the function
 //code within the function can change the value of the argument outside the function.
    uuper_string_by_ref(str[0]);// or str
// using call-by-value, a copy of the argument is passed to the function.
 //this means that code within a function cannot alter the arguments used to call the function.
   add_dash_to_space_by_value(str);
    cout<<str<<"\n";
 
 
    // if we not send not array in c++, there is another way sending by ref 
     //for example call by refernce
     int x; 
     x = 10;
     cout << x << " negated is ";
     neg(x); // no longer need the & operator
     cout << x << "\n";
    return 0;
}

   void neg(int &i)
   {
     i = -i;     // i is now a reference, don't need *
   }
