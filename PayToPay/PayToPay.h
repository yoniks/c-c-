//
//  PayToPay.h
//  PayToPay
//
//  Created by $ on 4/21/22.
//
#ifndef PayToPay_h
#define PayToPay_h

#include <iostream>
#include <typeinfo>
#include <map>
using namespace std;
//typedef struct CreditCard;
struct CreditCard {
     string nameCard;
     string CardOwner;
    unsigned short int SIZE=4;
    unsigned short int numberCard[4];//16 bits, 0 to 65,535
    unsigned short int date[2];
    unsigned short securityCode;
    double price;
};

class BaseUser{
    
private:
    CreditCard *userCard;
    
    string email;
    string userID;
public:
  
    ~BaseUser(){}
    virtual bool setUserID(string &_email,string &_userID){
        email=_email;
        userID=_userID;
        cout<<"";
        return false;
    }
    virtual bool setUserCard(CreditCard *__uc){
        bool res;
        //__uc->numberCard is pointer to value
        cout<<"class base_user setUserCard: "<<__uc->numberCard<<"\n";
        res= isWrongCard(__uc->numberCard, __uc->SIZE);
        userCard=__uc;
        if(userCard&&res){
            return true;
        }
        return false;
    }
    CreditCard *getUserCard(){
        return userCard;
    }
protected:
    bool  isWrongCard(unsigned short int *numCard,unsigned size){
        if(size==0){
            return false;
        }
        int counter=0;
        while (counter<size&&*numCard) {
            if(*numCard==0){
                return false;
            }
            numCard++;
        }
        return true;
    }

};

class EncryptionCreditCard: public BaseUser{
private:
    int keyPrivate=170;
    unsigned short int EncCard[4]={0,0,0,0};
  //  CreditCard *userCard;
public:
   
     bool setUserID(string &_email,string &_userID){
         if(_email.size()==0||_userID.size()==0){
             //throw "Error";
             return false;
         }
         return true;
    }
     bool setUserCard(CreditCard *__uc){
         bool result;
         result=BaseUser::isWrongCard(__uc->numberCard,__uc->SIZE);
         if(result){//EncryptionCreditCard
             for(int i=0;i<__uc->SIZE-1;i++){// the last 4 digit we do'nt Enc
               EncCard[i]=__uc->numberCard[i] ^ keyPrivate;
                 __uc->numberCard[i]=EncCard[i]<<1; //same as a multiply by 2
                 
               }
            
        }
         
        cout<<"setUserCard: class EncryptionCreditCard \n"<<result<<"\n";
         cout<<"setUserCard: class EncryptionCreditCard \n"<<__uc->numberCard[0]<<"\n";
        return result;
    }
    unsigned short int *getEncCard(){
        return EncCard;
    }
};



class Store: public BaseUser{
  private:
      double *totalPrice;
      string item;
      map<string,double> items;
public:
     
    bool setUserID(string &_email,string &_userID){
        if(_email.size()==0||_userID.size()==0){
            //throw "Error";
            return false;
        }
        return true;
   }
    bool setUserCard(CreditCard *__uc){
        totalPrice=&__uc->price;
       cout<<"";
       return false;
   }
    bool removeItem(){
        
        return false;
    }
    bool addItem(string i,double p){
        item=i;
        *totalPrice+=p;
        items.insert(make_pair( i,p));
        if(!item.empty()){
            return true;
        }
        return false;
    }
    bool printItem(){
        map<string,double>::iterator it;
        for(it= items.begin(); it != items.end(); it++){//->it pointer to map
            cout<<"item: \n"<<(*it).first<< "price: " << (*it).second<<"\n";
        }
        cout<<"totalPrice: "<<*totalPrice<<"\n";
        
        return false;
    }
  
    string getItem();
    
};
bool operator<(Store  a,Store b){
    return a.getItem()<b.getItem();
}

string Store::getItem(){
    return item;
}

#endif /* PayToPay_h */
