#include <iostream>

using namespace std;

class Beverage{
 public:
  Beverage(){
  	cout<<"constract beverage"<<endl;
  }
  virtual void AddMeterial()= 0;
  void PouredCup(){                      //預設 可以在次類別推翻
  	cout<<"pouredcup"<<endl;
  }
};

class GreenTea :public Beverage{
 public: 
  GreenTea():Beverage(){
  	cout<<"constract green tea"<<endl;
  }
  void AddMeterial(){
  	cout<<"add green tea meterial"<<endl;
  }
};
class BlackTea :public Beverage{
 public:
  BlackTea():Beverage(){
  	cout<<"constract black tea"<<endl;
  }
  void AddMeterial(){
  	cout<<"add black tea meterial"<<endl;
  }
};

enum name{
  GREENTEA,
  BLACKTEA
};

class simplefactory{
 public:
  static simplefactory *getinstance(){
    static simplefactory *s_instance = new simplefactory();
    return s_instance;
  } 
  Beverage* createbeverage(name _name){
    Beverage *_beverage;
    if(_name==GREENTEA){
      _beverage = new GreenTea();
    } else if(_name==BLACKTEA){
      _beverage = new BlackTea();
    } else {
      _beverage = NULL;
    }
    return _beverage;
  }
};

class BevarageStores{
 public: 
  BevarageStores(){
    cout<<"constract BevarageStores"<<endl;
  }
  void BerageOrdering(name _name){
  	Beverage *_beverage = simplefactory::getinstance()->createbeverage(_name);
    _beverage->AddMeterial();
    _beverage->PouredCup();
  }
};

int main(){

  BevarageStores *store1 = new BevarageStores();
  store1->BerageOrdering(GREENTEA);
  store1->BerageOrdering(BLACKTEA);
  return 0;	
}