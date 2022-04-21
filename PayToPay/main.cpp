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
    BaseUser *p,bu;
    EncryptionCreditCard ecc;
    Store store;
    bu.setUserID(email, idUser);
    
    CreditCard cCard;
    cCard.nameCard="MasterCard";
    cCard.date[0]=01;
    cCard.date[1]=26;
    cout<<cCard.SIZE;
    for(int i=0;i<cCard.SIZE;i++){
        cCard.numberCard[i]=1234*(i+1);
        cout<<"b"<<cCard.numberCard[i]<<"\n";
    }
    
    
    
    p=&ecc;//now pointer of BaseUser pointing
    p->setUserCard(&cCard);
    for(int i=0;i<cCard.SIZE;i++){
        cout<<"a"<<cCard.numberCard[i]<<"\n";
    }
    
    
    p=&store;// now pointer of BaseUser pointing to object Store

    
    
    
    
    return 0;
}
