/*
 One use of a static member variable is to provide access control to some shared resource used by all objects of a class. For example, you might create several objects, each of which needs to write to a specific disk file. Clearly, however, only one object can be allowed to write to the file at a time. In this case, you will want to declare a static variable that indicates when the file is in use and when it is free. Each object then interrogates this variable before writing to the file. The following program shows how you might use a static variable of this type to control access to a scarce resource:
 
 
 */

#include <iostream>
#include <string>
//#include <thread>
   using namespace std;
   class cl {
       static int resource;
   public:
     int get_resource();
     void free_resource() {resource = 0;}
       bool process(char *p,int byte);
   };
   int cl::resource; // define resource

   int cl::get_resource()
   {
     if(resource) return 0; // resource already in use
     else {
       resource = 1;
       return 1;  // resource allocated to this object
     }
    }

bool cl::process(char *p,int byte){
    int counter=0,bytes=byte;
    while(counter<bytes){
        cout<<*p++;
        counter++;
    }
    cout<<"\n done."<<"\n";
    return true;
}
int main() {
     char text[]= "uahsjhdkosldsidj478HGh";
 
cl ob1,ob2;
  
      if(ob1.get_resource()){
         cout  <<"ob1 has resource\n";
          ob1.process(&text[0],sizeof(text));
     }

    if(!ob2.get_resource()) cout << "ob2 denied resource\n";
    ob1.free_resource();// let someone else use it
    if(ob2.get_resource()){
       cout << "ob2 can now use resource\n";
        ob2.process(&text[0],sizeof(text)/2);
    }
return 0; }
/*output
 static % c++ -std=c++20 static.cpp  -o static
 static % ./static
 ob1 has resource
 uahsjhdkosldsidj478HGh
  done.
 ob2 denied resource
 ob2 can now use resource
 uahsjhdkosl
  done.
 
 */
