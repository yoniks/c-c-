/*
 It is possible to grant a nonmember function access to the private members of
  a class by using a keyword friend.
 To declare a friend function, include its prototype within the class.
 two or more classes may contain members that are interrelated
 relative to other parts of your program, for example both of class hold the total_Tax.
 
 -you can create member functions in each class that return a value
 this means additional overhead when the condition is checked
 (that is, two function calls, not just one).
 If the condition needs to be checked frequently, this additional overhead may not be acceptable
 However, using a function that is a friend of each class, it is possible to check the status of each object by calling only this one function. Thus, in situations like this, a friend function allows you to generate more efficient code.
 The following program illustrates this concept:
 
 calculation() is member of SocialSecurity but friend of Tax
 this pro-gram cal-cu-la-tion the tax to SocialSecurity
 
 */

#include <iostream>
using namespace std;
/*declare,
this is a way to create a constant that will work reliably
#define for constants We use another part of the C preprocessor (CPP) to create constant settings of*/
#define base_2022 6331*12 //initializtion
#define level1 0.0597
#define level2 0.1783
  class Tax;
class SocialSecurity{
    // members class
 double less_60,over_60,total_tax;
 public:
    //constractor
    SocialSecurity(){less_60=0;over_60=0;total_tax=0;}
   // ~SocialSecurity();
    void show();
    bool calculation(Tax t);
};

 class Tax{
     double total_tax,sum;
   public:
     Tax(double s){total_tax=0.0,sum=s;}
    friend bool SocialSecurity::calculation(Tax p);
 };
//calculation() is member of SocialSecurity, but friend of Tax
bool SocialSecurity::calculation(Tax p){
    if(p.sum<=0){
        return false;
    }
    less_60=  base_2022*0.6;
    if(p.sum>less_60){
        over_60=p.sum-less_60;
       // if(p.over_60> 45075)
    }
    total_tax= (double) (less_60*level1)+(over_60*level2);
     p.total_tax=total_tax;
    cout<<"class tax: "<<p.total_tax<<"\n"<< "class of SocialSecurity"<< total_tax<<"\n";
    return true;
}
void SocialSecurity::show(){
    cout<<"the tax: "<<total_tax<<"\n";
}

int main(){
    SocialSecurity ss;
    Tax check(72000);
    ss.calculation(check);//
    ss.show();
    /*
     so it allow to do chage at class Tax and keeping copy at class SocialSecurity
     */
 
    return 0;
}

