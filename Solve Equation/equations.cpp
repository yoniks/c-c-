#include <iostream>
using namespace std;
void isCorrent(int);
float solveEquation1(float);

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //isCorrent(3);
   // printf("%f \n", solveEquation1(3));
     
    if(solveEquation1(4)==17){
      std::cout << "Corrent! \n";
    }else{
      std::cout << "Incorrent! \n";
    }
    return 0;
}


//4x + 13(x + 3) + 7(3x)= 115
void isCorrent(int x){// we send number and the method check if the equation is equale after solve it 
    
    int result=115;
    int temp=0;
    temp = 4*x + 13*x + 13*3;
    temp += (3*x) * 7;
    if(temp==result){
      
        std::cout << "Corrent! \n";
    }else{
        std::cout << "Incorrent! \n";
    }
}


//4(x - 5) = 48  the method will return the solution.
float solveEquation1(float x1){
    // We have to undo the outer multiplication before we can do anything about the inner //subtraction
    float x = 1;
    float Equal= 48/x1;
    float temp = 4/x1;
    if(temp==1){// we undid the multiplication
        return x = Equal + 5;
    }else{
        x = temp*x;
        temp = temp*(-5);
        Equal = Equal+(-1)*temp;// both of side we add number to undo the left number
        printf("%f diving %f =\n", Equal, x);
        return Equal/x;// diving both of side to find the x
    }
    return 0;
}
