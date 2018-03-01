#include "iostream"

using namespace std;

class Chicken{
 public:
  Chicken(){
  	cout<<"Construct Chicken"<<endl;
  }
  virtual void goggle() = 0;
  virtual void fly() = 0;
};
class BigChicken : public Chicken{
 public:
  BigChicken(){
  	cout<<"Construct BigChicken"<<endl;
  }
  void goggle(){
    cout<<"goggle like bigchicken"<<endl;
  }
  void fly(){
  	cout<<"fly like bigchicken"<<endl;
  }
};

class Duck{
 public:
  Duck(){
    cout<<"Construct Duck"<<endl;
  }
  virtual void quack() = 0;
  virtual void fly() = 0;  
};
class BigDuck : public Duck{
 public:
  BigDuck(){
  	cout<<"Construct BigDuck"<<endl;
  }
  void quack(){
    cout<<"quack like bigduck"<<endl;
  }
  void fly(){
    cout<<"fly like bigduck"<<endl;
  }
};
class ChickenAdapter : public Duck{
 public:
  ChickenAdapter(Chicken *chichi):_chichi(chichi){
  	cout<<"Construct ChickenAdapter"<<endl;
  }
  void quack(){
    _chichi->goggle();
  }
  void fly(){
    _chichi->fly();
  }
 private:
  Chicken *_chichi;
};

int main(){

  Chicken *bigchichi = new BigChicken();
  Duck *chichiadapter = new ChickenAdapter(bigchichi);

  chichiadapter->quack();
  chichiadapter->fly();

  return 0;
}