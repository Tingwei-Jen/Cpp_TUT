#include <iostream>

using namespace std;

class CarWheel{
 public:
  CarWheel(){
    cout<<"Construct CarWheel"<<endl;
  }
};
class SteelWheel:public CarWheel{
 public:
  SteelWheel(){
    cout<<"Construct SteelWheel"<<endl;
  }
};
class PlasticWheel:public CarWheel{
 public:
  PlasticWheel(){
    cout<<"Construct PlasticWheel"<<endl;
  }
};

class CarShell{
 public:
  CarShell(){
    cout<<"Construct CarShell"<<endl;
  }
};
class SteelShell:public CarShell{
 public:
  SteelShell(){
  	cout<<"Construct SteelShell"<<endl;
  }
};
class PlasticShell:public CarShell{
 public:
  PlasticShell(){
  	cout<<"Construct PlasticSheel"<<endl;
  }
};

class CarColor{
 public:
  CarColor(){
    cout<<"Construct CarColor"<<endl;
  }
};
class YellowCarColor:public CarColor{
 public:
  YellowCarColor(){
    cout<<"Construct YellowCarColor"<<endl;
  }
};
class GreenCarColor:public CarColor{
 public:
  GreenCarColor(){
  	cout<<"Construct GreenCarColor"<<endl;
  }
};

class CarIngredientFactory{    // abstruct factory 
 public:
  CarIngredientFactory(){
    cout<<"Construct CarIngredientFactory"<<endl;
  }
  virtual CarWheel* createwheel() =0;
  virtual CarShell* createshell() =0;
  virtual CarColor* createcolor() =0;
};
class PlasticCarIngredientFactory: public CarIngredientFactory{
 public:
  PlasticCarIngredientFactory(){
  	cout<<"Construct PlasticCarIngredientFactory"<<endl;
  }
  CarWheel* createwheel(){
    return new PlasticWheel();
  }
  CarShell* createshell(){
    return new PlasticShell();
  }
  CarColor* createcolor(){
    return new YellowCarColor();
  }
};
class SteelCarIngredientFactory: public CarIngredientFactory{
 public:
  SteelCarIngredientFactory(){
  	cout<<"Construct SteelCarIngredientFactory"<<endl;
  }
  CarWheel* createwheel(){
    return new SteelWheel();
  }
  CarShell* createshell(){
    return new SteelShell();
  }
  CarColor* createcolor(){
    return new GreenCarColor();
  }
};



class Car{
 public:
  Car(){
  	cout<<"Construct Car"<<endl;
  }
  virtual void Prepare()=0;
  void TestCar(){
  	cout<<"Testing Car"<<endl;
  }
 protected:
  CarWheel* _wheel;
  CarShell* _shell;
  CarColor* _color;
};
class PlasticCar :public Car{
 public:
  PlasticCar(CarIngredientFactory* ingredientfactory){
    _ingredientfactory = ingredientfactory;
    cout<<"Construct PlasticCar"<<endl;
  }
  void Prepare(){
    _wheel = _ingredientfactory->createwheel();
    _shell = _ingredientfactory->createshell();
    _color = _ingredientfactory->createcolor();
  }
 private:
  CarIngredientFactory* _ingredientfactory;
};
class SteelCar :public Car{
 public:
  SteelCar(CarIngredientFactory* ingredientfactory){
    _ingredientfactory = ingredientfactory;
    cout<<"Construct SteelCar"<<endl;
  }
  void Prepare(){
    _wheel = _ingredientfactory->createwheel();
    _shell = _ingredientfactory->createshell();
    _color = _ingredientfactory->createcolor();
  }
 private:
  CarIngredientFactory* _ingredientfactory;
};

enum CarName{
  PLASTICCAR,
  STEELCAR
};



class CarStore{
 public:
  CarStore(){
    cout<<"Construct CarStore"<<endl;
  }
  void OrderingCar(CarName _name){
  	Car* car = createcar(_name);
  	car->Prepare();
  	car->TestCar();
  }
 protected:
  virtual Car* createcar(CarName _name) =0; //factory method
};
class CarCarStore: public CarStore{
 public:
  CarCarStore(){
  	cout<<"Construct CarCarStore"<<endl;
  }
  Car* createcar(CarName _name){
    Car* car;
    if(_name==PLASTICCAR){
      CarIngredientFactory* ingredientfactory = new PlasticCarIngredientFactory();
      car = new PlasticCar(ingredientfactory);
    } else if (_name==STEELCAR){
      CarIngredientFactory* ingredientfactory = new SteelCarIngredientFactory();
      car = new SteelCar(ingredientfactory);
    } else {
      car = NULL;
    }
    return car;
  }
};

int main(){
  CarStore* store1 = new CarCarStore();
  store1->OrderingCar(PLASTICCAR);
  store1->OrderingCar(STEELCAR);
  return 0;
}