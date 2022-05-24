//
//  Template.h
//  Spider_Search
//
//  Created by $ on 4/11/22.
//
/* void setNews(N *d, int i){
     if(i<0 || i>Size-1){
         throw "Error: ";
     }
     N *p;
     p=d;
     Data[i]= *p;
     p++;
     Data[++i]= *p;
     
     cout<<"-> "<<*p<<"->>" <<Data[1];
   }*/

#ifndef Template_h
#define Template_h
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
/*
template <class  N, int Size=50>
struct TData {
private:
    N *p;
    N Data[Size];
    N value;
public:
    N *getData();
    N getValue();
    N &operator[] (int i);
    ~TData();
   // News(N *n);
    TData(N n);
    TData();
};

template<class N, int Size>
TData<N,Size>::TData(N v){
    value=v;
}
template<class N, int Size>
TData<N,Size>::TData(){}

template<class N, int Size>
N *TData<N,Size>::getData(){
    for(int i=0;*p;i++){
        Data[i]=*p;
        p++;
    }
    return Data;
}

template<class N, int Size>
N TData<N,Size>::getValue(){
  //  cout<<"getV"<<value<<"\n";
    return value;
}
template<class N, int Size>
N &TData<N, Size>::operator[](int i)
{
    if(i<0 || i>Size-1){
        throw "Error: ";
    }
    return Data[i];
}
template<class N, int Size>
TData<N,Size>::~TData(){
  //  cout<<"Destructing"<<"\n";
}

*/



template <class C1, class C2>
struct Country {//or struct MultiKey{}
private:
    C1 anyKeyType1, anyKeyType2;
    C2 T;
    map<Country<string, string>,TData<string>> d;
    map<Country<string, string>,TData<int>> d1;
     string isTypeStr();// return value type of str
    int isTypeInt();// return value type of int
public:
    // member functions
    C1 getKeyType1(){
        return anyKeyType1;
    }
    C1 getKeyType2(){
        return anyKeyType2;
    }
    ~Country();
    Country(C1 _ad1);
    Country(C1 _ad1,C1 _ad2);
   // Country(C1 _ad1,C1 _ad2,C1 ad3);
    void setValueString(C2 v);
    void setValueInt(C2 v);
   
    
    C2 getStrBy1Key(C1 _ad1);
    C2 getStrBy2Key(C1 _ad1,C1 _ad2);
    
    C2 getIntBy1Key(C1 _ad1);
    C2 getIntBy2Key(C1 _ad1,C1 _ad2);
  //  C2 getValueBy3Key(C1 _ad1,C1 _ad2,C1 _ad3);

};


//template <class C1,class C2> <-dont declared here!
bool operator<(Country<string, string>  a,Country<string, string> b){
    return a.getKeyType1()<b.getKeyType1();
}



// by one key
template <class C1,class C2>
Country<C1, C2>::Country(C1 _ad1){
     string isStrType;
    if(_ad1==C1{}||typeid(_ad1)!=typeid(isStrType)){//if null
        throw "Error";
    }
    anyKeyType1=_ad1;
    cout<<"key: "<<anyKeyType1<<"\n";
}
//by two key
template <class C1,class C2>
Country<C1, C2>::Country(C1 _ad1, C1 _ad2){
     string isStrType;
    if(_ad1==C1{}||_ad2==C1{}!!typeid(_ad1)!=typeid(isStrType)){//if null or _ad1/2
        throw "Error";
    }
    anyKeyType1=_ad1+_ad2;
}


template <class C1,class C2>
void Country<C1, C2>::setValueString(C2 __v){
 
    d.insert(pair<Country<string , string>,TData<string>>
             (Country<string, string>(anyKeyType1),TData<string>(__v)));
       
}

template <class C1,class C2>
void Country<C1, C2>::setValueInt(C2 __v){

    d1.insert(pair<Country<string , string>,TData<int>>
             (Country<string, string>(anyKeyType1),TData<int>(__v)));
     
}


/* <key, value> if we declared the value
as int we must set int and return int
return the value <type1,type2> by key*/

/* return same type value we are declared,
 if you try return wrong type for example value of key is int but fun return declared as c2 string
you get wrong value, probably the compiler see the number from table ascii and rturen the char or the program throw*/
template <class C1,class C2>
C2 Country<C1, C2>::getStrBy1Key(C1 _ad1){
    anyKeyType1=_ad1;                      
    T=  isTypeStr();
     return (C2)T;
}
template <class C1,class C2>
C2 Country<C1, C2>::getStrBy2Key(C1 _ad1,C1 _ad2){
    anyKeyType1= _ad1+_ad2;
       T=  isTypeStr();
        return (C2)T;
}
template <class C1,class C2>
C2 Country<C1, C2>::getIntBy1Key(C1 _ad1){
    anyKeyType1=_ad1;
    T=  isTypeInt();
     return (C2)T;
}
template <class C1,class C2>
C2 Country<C1, C2>::getIntBy2Key(C1 _ad1,C1 _ad2){
    anyKeyType1= _ad1+_ad2;
    T=  isTypeInt();
     return (C2)T;
}



template <class C1,class C2>
string Country<C1, C2>::isTypeStr(){
    map<Country<string, string>,TData<string>>::iterator r;
   r= d.find(Country<string, string>(anyKeyType1));//_ad1+_ad2
    if(r!=d.end()){
        return  r->second.getValue();
    }
    return "";
}
template <class C1,class C2>
int Country<C1, C2>::isTypeInt(){
    map<Country<string, string>,TData<int>>::iterator r1;
    r1= d1.find(Country<string, string>(anyKeyType1));
     if(r1!=d1.end()){
         return r1->second.getValue();
     }
    return 0;
}
template <class C1,class C2>
Country<C1, C2>::~Country(){}



















#endif /* Template_h */
