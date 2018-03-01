#include <stdio.h>
#include <iostream>

using namespace std;

template <class T>
T add(T a,T b){
  T result;
  result = a+b;
  return result;
}

template <class K>
class circle{
 public:
  circle(K var1_,int var2_);
  ~circle();	
  K add(K a,K b);
  K var1; 
  int var2;
 private:
  K result;
};

template <class K>
circle<K>::circle(K var1_,int var2_):var1(var1_),var2(var2_){

}
template <class K>
circle<K>::~circle(){
	
}
template <class K>
K circle<K>::add(K a,K b){
  result = a+b;
  return result;
}


int main(){

  cout<<add(1.0,2.0)<<endl;
  circle<int> aa(1.5,3);
  circle<double> bb(1.5,3);
  cout<<aa.var1<<"  "<<bb.var1<<endl;
  cout<<aa.var2<<"  "<<bb.var2<<endl;
  cout<<aa.add(5.5,7.8)<<"  "<<bb.add(5.5,7.8)<<endl;
}