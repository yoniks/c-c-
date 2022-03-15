
//conditional compilation directives
#ifndef vvsr_h
#define vvsr_h
#include <iostream>
using namespace std;



// lower to uuper
void uuper_string_by_ref(char &str){// ref to adrress
    // it is not possible to change what the reference parameter is pointing to
  
   
    if(str>32&&str<127){
        int cou=0;
        char *p;
        p=&str;// pointer on the value
      
        while (*p) {//or (*p)!='\0'
            if(*p>96&&*p<123){
                *p=(*p-32);
            }
            
            p++;// next pointer
            cout<<((*p)=='\0');
        }
        
    }else{
        cout<<"variable should be initialize! \n";
    }
}


void add_dash_to_space_by_value(char *str){
    int cou=0;
    if(*str>32&&*str<127){
        for(int i=0;*str;i++){// or *str!='\0'
            if(*str==' '){
                *str='-';
            }
            cout<<++cou;
            str++;// next adrress
        }
    }
}
#endif
    
/*
 
 //
 #define WX_DECLARE_LIST_XO(elT, baseT, liT, decl)                             \
     decl _WX_LIST_HELPER_##liT                                                \
     {                                                                         \
         typedef elT _WX_LIST_ITEM_TYPE_##liT;                                 \
         typedef std::list<elT> BaseListType;                                  \
     public:                                                                   \
         static BaseListType EmptyList;                                        \
         static void DeleteFunction( _WX_LIST_ITEM_TYPE_##liT X );             \
     };                                                                        \
                                                                               \
 
 */
