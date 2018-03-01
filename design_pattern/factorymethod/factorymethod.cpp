#include <iostream>

using namespace std;

//product /////////////////////////////////////////////
class Beverage{
 public: 
  Beverage(){
  	cout<<"Constract Beverage"<<endl;
  }
  virtual void AddMeterial()= 0;
  virtual void PouredCup()= 0;
  void Brew(){                          //預設
  	cout<<"Brew the beverage"<<endl;
  }
};

class TaipeiStyleGreenTea :public Beverage{
 public:
  TaipeiStyleGreenTea():Beverage(){
    cout<<"Constract TaipeiStyleGreenTea"<<endl;
  }
  void AddMeterial(){
    cout<<"Add meterial of TaipeiStyleGreenTea"<<endl;
  }
  void PouredCup(){
    cout<<"Poured cup of TaipeiStyleGreenTea"<<endl;
  }
};
class TokyoStyleGreenTea :public Beverage{
 public:
  TokyoStyleGreenTea():Beverage(){
    cout<<"Constract TokyoStyleGreenTea"<<endl;
  }
  void AddMeterial(){
    cout<<"Add meterial of TokyoStyleGreenTea"<<endl;
  }
  void PouredCup(){
  	cout<<"Poured cup of TokyoStyleGreenTea"<<endl;
  }
};
class TaipeiStyleBlackTea :public Beverage{
 public:
  TaipeiStyleBlackTea():Beverage(){
    cout<<"constract TaipeiStyleBlackTea"<<endl;
  }
  void AddMeterial(){
    cout<<"add meterial of TaipeiStyleBlackTea"<<endl;
  }
  void PouredCup(){
  	cout<<"Poured cup of TaipeiStyleBlackTea"<<endl;
  }
};
class TokyoStyleBlackTea :public Beverage{
 public:
  TokyoStyleBlackTea():Beverage(){
    cout<<"constract TokyoStyleBlackTea"<<endl;
  }
  void AddMeterial(){
    cout<<"add meterial of TokyoStyleBlackTea"<<endl;
  }
  void PouredCup(){
    cout<<"Poured cup of TokyoStyleBlackTea"<<endl;
  }
};


enum BeverageName{
  GREENTEA,
  BLACKTEA
};

//factory ///////////////////////////////////////////////
class BeverageStore{
 public:
  BeverageStore(){
  	cout<<"Constuct BeverageStore"<<endl;
  }
  void OrderingBeverage(BeverageName _name){
    Beverage* beverage = createbeverage(_name);
    beverage->AddMeterial();
    beverage->PouredCup();
    beverage->Brew();
  }
 protected:
  virtual Beverage* createbeverage(BeverageName _name) =0; //factory method
};

class TaipeiBeverageStore: public BeverageStore{
 public:
  TaipeiBeverageStore(){
  	cout<<"Constuct TaipeiBeverageStore"<<endl;
  }
  Beverage* createbeverage(BeverageName _name){
    Beverage* _beverage;
    if(_name==GREENTEA){
      _beverage = new TaipeiStyleGreenTea();
    } else if(_name==BLACKTEA){
      _beverage = new TaipeiStyleBlackTea();
    } else {
      _beverage = NULL;
    }
    return _beverage;
  }
};

class TokyoBeverageStore: public BeverageStore{
 public:
  TokyoBeverageStore(){
  	cout<<"Constuct TokyoBeverageStore"<<endl;
  }
  Beverage* createbeverage(BeverageName _name){
    Beverage* _beverage;
    if(_name==GREENTEA){
      _beverage = new TokyoStyleGreenTea();
    } else if(_name==BLACKTEA){
      _beverage = new TokyoStyleBlackTea();
    } else {
      _beverage = NULL;
    }
    return _beverage;
  }
};
///////////////////////////////////////////////////

int main(){
  BeverageStore *store1 = new TaipeiBeverageStore();
  BeverageStore *store2 = new TokyoBeverageStore();

  store1->OrderingBeverage(GREENTEA);
  store1->OrderingBeverage(BLACKTEA);
  store2->OrderingBeverage(GREENTEA);
  store2->OrderingBeverage(BLACKTEA);
  
  return 0;
}