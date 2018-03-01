#include "iostream"

using namespace std;
class Light{
 public:
  Light(){
    cout<<"Construct Light"<<endl;
  }
  void TurnOn(){
  	cout<<"TurnOn Light"<<endl;
  }
  void TurnOff(){
  	cout<<"TurnOff Light"<<endl;
  }
};
class TV{
 public:
  TV(){
  	cout<<"Construct TV"<<endl;
  }
  void TurnOn(){
    cout<<"TurnOn TV"<<endl;
  }
  void TurnOff(){
    cout<<"TurnOff TV"<<endl;
  }
};
class Popcorn{
 public:
  Popcorn(){
  	cout<<"Construct Popcorn"<<endl;
  }	
  void pop(){
  	cout<<"pop Popcorn"<<endl;
  }
  void off(){
  	cout<<"off Popcorn"<<endl;
  }
};

class HomeFacade{
 public:
  HomeFacade(Light *light , TV *tv , Popcorn *popcorn)
  : _light(light),_tv(tv),_popcorn(popcorn){
    cout<<"Construct HomeFacade"<<endl;
  }
  void BackHome(){
    cout<<"back home"<<endl;
    _light->TurnOn();
    _tv->TurnOn();
    _popcorn->pop();
  }
  void Sleep(){
    cout<<"Sleep Sleep"<<endl;
    _light->TurnOff();
    _tv->TurnOff();
    _popcorn->off();
  }
 private:
  Light *_light;
  TV *_tv;
  Popcorn *_popcorn;
};

int main(){
  Light *light = new Light();
  TV *tv = new TV();
  Popcorn *popcorn = new Popcorn();

  HomeFacade *home = new HomeFacade(light,tv,popcorn);
  home->BackHome();
  home->Sleep();
  return 0;	
}