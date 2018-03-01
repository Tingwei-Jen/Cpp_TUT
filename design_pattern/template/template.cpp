#include "iostream"

using namespace std;

class Game{
 public:
  Game(){
  	cout<<"Construct Game"<<endl;
  }
  void play(){
    initialize();
    gametype();
    turnoffps4();
  }
  void initialize(){
    cout<<"initialize ps4"<<endl;
  }
  void turnoffps4(){
    cout<<"turnoffps4"<<endl;
  }
  virtual void gametype() = 0;
};
class basketball : public Game{
 public:
  basketball(){
  	cout<<"Construct basketball"<<endl;
  }
  void gametype(){
  	cout<<"2k16"<<endl;
  }
};
class witcher : public Game{
 public:
  witcher(){
  	cout<<"Construct witcher"<<endl;
  }
  void gametype(){
  	cout<<"witcher good"<<endl;
  }
};

int main(){

  Game *game1 = new basketball();
  Game *game2 = new witcher();

  game1->play();
  game2->play();

  return 0;	
}