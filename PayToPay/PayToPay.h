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
    unsigned short int securityCode;
    double price=0;
protected:
    const short int sizeEnc=5;
    const short int keyEncryptin[5]={4571,5641,7316,1734,1113};// encryption every num with 8 letters
};

class BaseUser{
    
private:
    
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
  
    virtual bool setUserCard(CreditCard &__uc){//
        bool res;
        //__uc->numberCard is pointer to value
        cout<<"class base_user setUserCard: "<<__uc.numberCard<<"\n";
        res= isWrongCard(__uc.numberCard, __uc.SIZE);
      
        if(res){
            return true;
        }
        return false;
    }
    virtual bool decryptionCard(CreditCard *__uc){return false;}
    virtual  bool encryptionCard(CreditCard *__uc){return false; }
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

class EncryptionCreditCard: public BaseUser,private CreditCard {
private:
  //  unsigned short int EncCard[4]={0,0,0,0};

public:
    
     bool setUserID(string &_email,string &_userID){
         if(_email.size()==0||_userID.size()==0){
             //throw "Error";
             return false;
         }
         return true;
    }
     bool encryptionCard(CreditCard *__uc){
         bool result;
         EncryptionCreditCard objEnc;
         result=BaseUser::isWrongCard(__uc->numberCard,__uc->SIZE);
         
         if(result){//EncryptionCreditCard
             for(int i=0;i<__uc->SIZE-1;i++){// the last 4 digit we do'nt Enc
                 for(int j=0;j<objEnc.sizeEnc;j++){
                     __uc->numberCard[i]=__uc->numberCard[i] ^ objEnc.CreditCard::keyEncryptin[j];
                       
                 }
                 __uc->numberCard[i]<<=1;
               }
             /* if this class inherits from 2 class
              that both of them inherits from base class we dec  name::variable*/
        
        }
         
         cout<<"encryption \n";
         for(int k=0;k<__uc->SIZE;k++){
             cout<<" "<<__uc->numberCard[k];
         }
         cout<<" \n";
        return result;
    }
    bool decryptionCard(CreditCard *__uc){
        cout<<"before decryption \n";
        for(int k=0;k<__uc->SIZE;k++){
            cout<<" "<<__uc->numberCard[k];
        }
        cout<<" \n";
        bool result;
        EncryptionCreditCard objEnc;
        result=BaseUser::isWrongCard(__uc->numberCard,__uc->SIZE);
        if(result){//EncryptionCreditCard
            for(int i=0;i<__uc->SIZE-1;i++){// the last 4 digit we do'nt Enc
                __uc->numberCard[i]>>=1;//
                for(int j=objEnc.sizeEnc-1;j>=0;j--){
                    __uc->numberCard[i]=__uc->numberCard[i] ^ objEnc.CreditCard::keyEncryptin[j];
                }
               
              }
            /* if this class inherits from 2 class
             that both of them inherits from base class we dec  name::variable*/
       
       }
        
        cout<<"decryption \n";
        for(int k=0;k<__uc->SIZE;k++){
            cout<<" "<<__uc->numberCard[k];
        }
        cout<<" \n";
       return result;
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
    bool setUserCard(CreditCard &__uc){
        *totalPrice=__uc.price;
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
/*
 Sometimes you need some of the features pointers provide, such as avoiding extra copies of large pieces of data, but don't need the full power of pointers. In these situations, you could use a reference. A reference is a variable that refers to another variable, sharing the same backing memory. References, however, are used just like regular variables. You can think of a reference as a stripped-down pointer without needing to use special asterisk and ampersand syntax to use the referred-to value or when assigning
 References can be used to pass structures into functions without having to pass the whole structure, and without having to worry about NULL pointers.
 Since a reference refers to the original object at all times, you both avoid copying and can modify the original object passed in to the function.
 */
