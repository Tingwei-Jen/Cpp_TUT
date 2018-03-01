#include <iostream>

using namespace std;

//將行爲封裝
class Flybehavior{
 public:
  virtual void fly() = 0;
};
class flywithA : public Flybehavior{
 public:
  void fly(){
      cout<<"fly with A"<<endl;
  }
};
class flywithB : public Flybehavior{
 public :
  void fly(){
      cout<<"fly with B"<<endl;
  }
};

class Shitbehavior{
  public:
   virtual void shit() = 0;
};
class ShitwithC : public Shitbehavior{
  public:
   void shit(){
       cout<<"shit with C"<<endl;
   }
};
class ShitwithD : public Shitbehavior{
  public:
   void shit(){
       cout<<"shit with D"<<endl;
   }
};

//抽象類別///
class Duck{
 public:
  Duck(Flybehavior *flybehavior , Shitbehavior *shitbehavior)://合成
  _flybehavior(flybehavior),_shitbehavior(shitbehavior){ 
    cout<<"contruct duck"<<endl;      
  }
  ~Duck(){
    cout<<"Destruct duck "<<endl;
  }

 public:  
  virtual void color() = 0; 

 public: 
  void setFlybehavior(Flybehavior *flybehavior){
    _flybehavior = flybehavior;  
  }
  void setShitbehavior(Shitbehavior *shitbehavior){
    _shitbehavior = shitbehavior;  
  }
  void performfly(){
    _flybehavior->fly();
  }
  void performshit(){
    _shitbehavior->shit();  
  }

 protected:
  Flybehavior *_flybehavior;
  Shitbehavior *_shitbehavior;
};

//具體實踐///
class DuckA : public Duck{
 public : 
  DuckA(Flybehavior *flybehavior , Shitbehavior *shitbehavior):
  Duck(flybehavior,shitbehavior){
    cout<<"contruct duckA"<<endl;
  }
  ~DuckA(){
    cout<<"Destruct duckA "<<endl;
  }
  void color(){
      cout<<"color is aa"<<endl;
  }
};
class DuckB : public Duck{
 public : 
  DuckB(Flybehavior *flybehavior , Shitbehavior *shitbehavior):
  Duck(flybehavior,shitbehavior){
    cout<<"contruct duckB"<<endl;
  }
  ~DuckB(){
    cout<<"Destruct duckB "<<endl;
  }
  void color(){
    cout<<"color is bb"<<endl;
  }
};


int main()
{
   cout << "Hello World" << endl; 
   Duck *duck1 = new DuckA(new flywithA(),new ShitwithC());
   Duck *duck2 = new DuckB(new flywithB(),new ShitwithD());

   duck1->color();
   duck2->color();

   duck1->performfly();
   duck2->performfly();

   duck1->performshit();
   duck2->performshit();

   duck1->setFlybehavior(new flywithB());
   duck2->setShitbehavior(new ShitwithC());

   duck1->performfly();
   duck2->performfly();

   duck1->performshit();
   duck2->performshit();

   delete duck1;

   return 0;
}