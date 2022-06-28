//
//  main.cpp
//  trigonometry
//
//  Created by yo on 6/24/22.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#define PI 3.1415926
using namespace std;
float findByX_YTheDiagonal(float x, float y);
float findByX_DiagonalTheAngle(float x, float Diagonal);
float findByY_DiagonalTheAngle(float y, float Diagonal);
float findByDiagona_AngleTheX(float diagonal, float angle);
float findByDiagona_AngleTheY(float diagonal, float angle);
int main(int argc, const char * argv[]) {
    // insert code here...
    
   float X=200.0,Y=150.0, Diagonal=0,angle=0;
  //  double temp=sin(30*PI/180)*215;
   // double temp=cos(30*PI/180)*315;
   
    
     Diagonal=  findByX_YTheDiagonal(X,Y);
    
    if(Diagonal>0&&Diagonal>X&&Diagonal>Y){
    std::cout<<"Diagonal of x and y is: " <<" "<<Diagonal<<"\n";
   angle= findByX_DiagonalTheAngle(X,Diagonal);
    std::cout<<"angle of x: " <<angle<<"\n";
   angle= findByY_DiagonalTheAngle(Y,Diagonal);
    std::cout<<"angle of y: " <<angle<<"\n";

  float  ofY= findByDiagona_AngleTheY(Diagonal,angle);
    float  ofX= findByDiagona_AngleTheX(Diagonal,angle);
    std::cout<<"by value of Diagona and Angle found Y: " <<ofY<<"\n"<<"x: "<<ofX<<"\n";
    }
    return 0;
}
float findByX_YTheDiagonal(float x, float y){
    if(x<=0||y<=0){
        return 0.0;
    }// the square
    float temp= (x*x)+(y*y);
    // we get the square root
    temp=sqrt(temp);
    if(temp<= x|| temp<= y){return 0.0;}
    return temp;
}
float findByX_DiagonalTheAngle(float x, float Diagonal){
    if(x>=Diagonal||x==0||Diagonal==0){
        return 0.0;
    }
    float angle= acos(x/Diagonal);
    return angle*(180/PI);
}
float findByY_DiagonalTheAngle(float y, float Diagonal){
    if(y>=Diagonal||y==0||Diagonal==0){
        return 0.0;
        }
    float angle= asin(y/Diagonal);
    
    return angle*(180/PI);
}


float findByDiagona_AngleTheX(float diagonal, float angle){
    if(diagonal==0||angle==0||angle>=diagonal){
        return 0.0;
    }
    float X=cos(angle*PI/180)*diagonal;
    float angleOf= findByX_DiagonalTheAngle(X, diagonal);
    if(angleOf!=angle){return 0.0;}
    return X;//==X
}
float findByDiagona_AngleTheY(float diagonal, float angle){
    if(diagonal==0||angle==0||angle>=diagonal){
        return 0.0;
    }
 
    float Y=sin(angle*PI/180)*diagonal;//==Y
    float test= findByY_DiagonalTheAngle(Y,diagonal);
    if(test!=angle){
        return 0.0;
    }
    return Y;
}
