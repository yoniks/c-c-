//
//  main.cpp
//  PayToPay
//
//  Created by $ on 4/21/22.
// Virtual Functions and Polymorphism 
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
    BaseUser *p=NULL,bu;
    try {
        p=new BaseUser();
    } catch (bad_alloc a) {
        return  1;
    }
    
 //   Store store;
    
    CreditCard cCard;
    cCard.nameCard="MasterCard";
    cCard.date[0]=01;
    cCard.date[1]=26;
    
    cout<<"number card\n";
    for(int i=0;i<cCard.SIZE;i++){
        cCard.numberCard[i]=1234*(i+1);
        cout<<" "<<cCard.numberCard[i]<<" ";
    }
    cout<<"\n\n";
    bu.setUserID(email, idUser);
    delete p;
    EncryptionCreditCard ecc;
    p=&ecc;//now pointer of BaseUser pointing
 
    if(p!=NULL){
    p->encryptionCard(&cCard);
    p->decryptionCard(&cCard);
    }
    p=NULL;
    
    //p=&store;// now pointer of BaseUser pointing to object Store

    return 0;
}
