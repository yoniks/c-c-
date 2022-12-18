#include <iostream>
using namespace std;
int findTheIndexOfValue(int Numbers[], int N);
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int N=20;
    int Numbers[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1};
    std::cout << "Num of instance that contain 1 is: " << findTheIndexOfValue(Numbers,N);
    
    return 0;
}
int findTheIndexOfValue(int Numbers[], int N){
    std::cout <<Numbers[0]<<"-"<<N<<"\n";
    for(int i=(N/2);i>1;i=(i/2)){  //min diving 2 index
        
        if(Numbers[i]==0&&i==(N/2)){
            break;//GO TO SECOND LOOP
        }else{//than the half of arr is equ value of 1
            if(Numbers[i]==0){
                for(int j=i;j<=(N/2);j++){//searching the value of first
                    if(Numbers[j]==1)     //with value one
                        return j;// teturn the index of this value
                }
            }
            
        }
        
    }
    
    for(int i=N;i > (N/2);i=((i-(N/2))/2)+(N/2)){//min diving till half of array
        std::cout <<Numbers[0]<<"--"<<i<<"\n";
        if(Numbers[i]==0){
            for(int j=i; j <= N; j++){//searching the value of first
                if(Numbers[j]==1)     //with value one
                    return j;// teturn the index of this value
            }
        }
    }
    
    
    return 0;
}
