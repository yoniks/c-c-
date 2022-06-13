//
// 
//
//  Created by yo on 6/13/22.
//

#include <iostream>
float getTheFloatingPointNumber(const float nFloat);
int getRemnantOfInt(const int nInt,const int base);
float getRemnantOfFloat(const float nFloat, int base);
int main(int argc, const char * argv[]) {
    // insert code here...
 
    float num1= 133.7;
    std::cout<<  getRemnantOfFloat(num1,8)<<"\n";
    
   /* result= getTheFloatingPointNumber(num1);
    int rModul=getRemnantOfInt(num1,2);
    std::cout<<"from number: "<< num1<<"\n";
    std::cout<<"floating point number: "<< result <<"\n"<<"Modulo of "
    <<2<<" is: "<< rModul <<"\n";
    std::cout<<rModul+result<<"\n";*/

    return 0;
}
float getRemnantOfFloat(const float nFloat, int divide){
    if(nFloat>0&&divide>0){
    int n= nFloat;
    float remnan=nFloat-n;
   n= getRemnantOfInt(n,divide);
    return remnan+n;
    }else return 0.0;
}

float getTheFloatingPointNumber(const float nFloat){
    
    int result= nFloat;
    return (nFloat-result);
}
int getRemnantOfInt(const int nInt,const int divide){
    //if send float it convert to int to calculation Modulo
    return nInt%divide;
}
