#include <stdio.h>
#include <iostream>

using namespace std;

class A{
 public:
  A(){
  	printf("constructor is called..\n");
  	count++;
  }
  static int GetValue(){
  	return value_;
  }
  static int GetCount(){
  	return count;
  }

 private:
  static int value_;
  static int count;
};

class B{                    //use non-static variables and functions
 public:
  B(){
  	value_b_ = 20;
  	value_c_ = 30;
  	m_pthis = this;
  }

  static int GetValue(){
  	return value_;
  }
  static int GetValue_b(){
  	return m_pthis->value_b_;
  }
  static int StaticGetValue_c(){
    return m_pthis->GetValue_c();
  }

  int GetValue_c(){
    return value_c_;
  }
  void SetValue_c(int val){
    value_c_ = val;
  }

 private:
  static B *m_pthis; 
  static int value_;
  int value_b_;
  int value_c_;

};

int A::value_ = 10; //static variables initialization
int A::count = 0;
B *B::m_pthis = 0;
int B::value_ = 10;

int main(){

  cout<<"A::GetValue(): "<<A::GetValue()<<endl;
  A a1;
  cout<<"a1.GetCount(): "<<a1.GetCount()<<endl;
  cout<<"A::GetCount(): "<<A::GetCount()<<endl;
  A a2;
  cout<<"a2.GetCount(): "<<a2.GetCount()<<endl;
  cout<<"A::GetCount(): "<<A::GetCount()<<endl;


  cout<<"B::GetValue(): "<<B::GetValue()<<endl;
  B b1;
  cout<<"b1.GetValue_b(): "<<b1.GetValue_b()<<endl;
  cout<<"b1.GetValue_c(): "<<b1.GetValue_c()<<endl;
  cout<<"b1.StaticGetValue_c(): "<<b1.StaticGetValue_c()<<endl;
  B b2;
  cout<<"b2.GetValue_b(): "<<b2.GetValue_b()<<endl;
  b2.SetValue_c(1000);
  cout<<"b2.StaticGetValue_c(): "<<b2.StaticGetValue_c()<<endl;
  cout<<"b1.StaticGetValue_c(): "<<b1.StaticGetValue_c()<<endl;
  cout<<"b1.GetValue_c(): "<<b1.GetValue_c()<<endl;


}