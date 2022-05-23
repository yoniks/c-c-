//
//  even_odd_map.h
//  even_odd_map
//
//  Created by yo on 5/23/22.
//

#ifndef even_odd_map_h
#define even_odd_map_h

#include <typeinfo>
#include <map>
using  namespace std;
template<typename K, typename V>
class even_odd_map {
    friend void IntervalMapTest();
    
    
    V m_valBegin;
    int SIZE=0,size_array=10,size_counter=0;
    int *counter= new int[size_array];
    std::map<K,V> m_map;
    
    //NOTE keeping private if you not call to fun from main
    //print the k and v
   void IntervalMapTest(){
       std::cout<<"the new size of map: " <<m_map.size()<<"\n";
       std::cout<<"you added to map: " <<size_array<< " times"<<"\n";
       
       //if the array going to be full grow it by new allocate
       if(size_array<m_map.size()+SIZE){
           SIZE*=2;
           size_array+= SIZE;
          int *p_new_value=new int[size_array];//Allocate for free memore
           for(int i=0;i<size_array;i++){
               p_new_value[i]= counter[i];
           }
           delete [] counter;// DELETE THE OLD MEMORY AND POINTER TO NEW
           counter=p_new_value;// counter pointer to new size now
       }
       
    }
    
public:
    
    ~even_odd_map(){
        delete [] counter;
    }
    // constructor associates whole range of K with val
    even_odd_map(V const& val): m_valBegin(val)
    {
       // if the value type is not char
        if( typeid(val).name()!=typeid(char).name()){// it mean the type not int
            throw "the type of variable should to be char";
        }
      
    }
    V getMValBegin(){
        return m_valBegin;
    }
  
    void assign( K const& keyBegin, K const& keyEnd, V  val ) {
        
       
        std::map<int, char>::iterator itr;
        //IF THE VALUE IS in scope A-Z OR a-z  //(keyBegin<keyEnd)
        if(((val>64&&val<91) || (val>96&&val<123))&&keyBegin<keyEnd){
         /*
          the fun print the key and value and if the size of array not  enough so we grow dynamic the array,
          */
            SIZE=keyEnd-keyBegin;
            IntervalMapTest();
            int index_map=(int)m_map.size();
            cout<<"size: "<<index_map;
               for(int i=keyBegin;i<=keyEnd; i++){//x1 to x2 initialzion
                   
                  
                   /*
                        for example if  the map has 16  objects 0 to 15,
                    and we sent next 20  to 25
                    as key so i have 15 to 20 empty object i should fill it,
                    and than i will add to right keys 20 to 25.
                                             */
                   if(!m_map.empty()){
                   if((int)m_map.size()<keyBegin){
                       for(int j=(int)m_map.size();j<keyBegin; j++){
                           
                           m_map.insert(std::pair<int, char>(j,val));
                       }
                   }
                   }
                   
                   
                   /*
                    if index map is not even grow the value BY assci in one step else
                    do nothing
                    */
                   
                   if(index_map%2!=0){
                       val+=1;
                   }
                       
                   if(val>=123){
                       val=(char)65;
                   }
                       
                       m_map.insert(std::pair<int, char>(i,val));
                       ++index_map;
                       /*
                        keeping the v in array, array grow dynamic allocate
                        */
                       counter[size_counter]=val;
                       size_counter++;
                   
                   
                   
                   
                }
                
                
           
                
            }
        /*
         print
         */
        for(std::map<int, char>::iterator  itr= m_map.begin(),
            end= m_map.end();itr!=end;++itr ){
            std::cout << itr->first << " --> " << itr->second << std::endl;
        }
        
     
           
    }
    
    
 
    
    
    // look-up of the value associated with key
        V const& operator[]( K const& key ) const {
            auto it=m_map.upper_bound(key);
            if(it==m_map.begin()) {
                return m_valBegin;
            } else {
                return (--it)->second;
            }
        }
    };


#endif /* even_odd_map_h */
