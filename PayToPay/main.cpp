//
//  main.cpp
//  PayToPay
//
//  Created by $ on 4/21/22.
//
#include <typeinfo>
#include <iostream>
using namespace std;
#include "PayToPay.h"
//Virtual Functions and Polymorphism
int main(int argc, const char * argv[]) {
    // insert code here...
    string email="yoni@icloud.com";
    string idUser="123445677";
    CreditCard pubObj;
    pubObj.nameCard="MasterCard";
    pubObj.date[0]=01;
    pubObj.date[1]=26;
    cout<<"number card\n";
   
    BaseUser *p=NULL;// storeg in stack when function main return the pointer flushing
  unsigned short int *p_value_card=NULL;
    try {
    p_value_card= new unsigned short int[pubObj.SIZE];// storeg in heap when delete [] name the pointer flushing
    } catch (bad_alloc a) {
        return  1;
    }
    EncryptionCreditCard ecc;
    p=&ecc;//now pointer of BaseUser pointing
   // p_value_card= pubObj.numberCard;//it not good idea to point on card if i want more memory from system operation
    
    for(int i=0;i<pubObj.SIZE;i++){
        p_value_card[i]=1234*(i+1);//initialize card
        cout<<" "<<p_value_card[i]<<" ";
        pubObj.numberCard[i]=1234*(i+1);
    }
    cout<<"__"<<p_value_card<<"\n ";

    if(p!=NULL){
    p->encryptionCard(&pubObj);
    p->decryptionCard(&pubObj);
        //if i need extra array memory the safe way is allocation with heap (new) type and delete when we not need it 
    p_value_card= p->dynamicGrowArray(p_value_card, &pubObj.SIZE);
        // initialize a parameter of type 'unsigned short
        cout<<"size: "<<pubObj.SIZE<<  p_value_card[3] <<"\n";
       
    }
 
    delete [] p_value_card;
    deleteBase(new EncryptionCreditCard());
    p=NULL;
    return 0;
}
/*
 long arrSize = *(&pubObj.numberCard +1) - pubObj.numberCard;
   cout << "The size of the array is: " << arrSize;
 */
