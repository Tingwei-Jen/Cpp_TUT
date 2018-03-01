#include <stdio.h>

class GlobalClass{
 public:

  static GlobalClass *getinstance(){

    if(!s_instance)
      s_instance = new GlobalClass();
    return s_instance;
  }
  
  void set_value(int value){
    m_value = value;
  }

  int get_value(){
    return m_value;
  }

  static GlobalClass *s_instance;
  int m_value;
};


GlobalClass *GlobalClass::s_instance = 0; //because of static!!

int main(){

    GlobalClass::getinstance()->set_value(20);
    printf("%d\n",GlobalClass::getinstance()->get_value());
    
    GlobalClass::getinstance()->set_value(30);
    printf("%d\n",GlobalClass::getinstance()->get_value());


	return 0;
}