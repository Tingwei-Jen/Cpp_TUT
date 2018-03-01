#include "iostream"
#include "list"
#include "vector"
using namespace std;

//receiver
class linkedlist{
 public:
  linkedlist(){
    cout<<"Construct linkedlist"<<endl;
  }
  ~linkedlist(){
    cout<<"Destroy linkedlist"<<endl;
  }
  void pushback(int value){
    cout<<"pushback"<<endl;
    mylist.push_back(value);
  }
  void pushfront(int value){
    cout<<"pushfront"<<endl;
    mylist.push_front(value);
  }
  void popback(){
    cout<<"popback"<<endl;
    mylist.pop_back();
  }
  void popfront(){
    cout<<"popfront"<<endl;
    mylist.pop_front();
  }
  void printprint(){
    
    while (!mylist.empty()){
      cout << mylist.front()<<"  ";
      mylist.pop_front();
    }
    cout<<endl;
  }
  int getlistfront(){
  	return mylist.front();
  }
  int getlistback(){
  	return mylist.back();
  }

 private:
  list<int> mylist;

};

class Command{
 public:
  Command(linkedlist *list){
  	cout<<"Construct Command"<<endl;
    _list = list;
  }
  ~Command(){
  	cout<<"Destroy Command"<<endl;
  }
  virtual void execute() = 0;
  virtual void undo() = 0;
  virtual void redo() = 0;

 protected:
  linkedlist *_list;

};
class PushBackCommand : public Command{
 public:
  PushBackCommand(linkedlist *list,int value): Command(list),_value(value){
  	cout<<"Construct PushBackCommand"<<endl;
  }
  ~PushBackCommand(){
  	cout<<"Destroy PushBackCommand"<<endl;
  }
  void execute(){
  	_list->pushback(_value);
  }
  void undo(){
   _list->popback();
  }
  void redo(){
  	_list->pushback(_value);
  }
 private:
  int _value;


};
class PushFrontCommand : public Command{
 public:
  PushFrontCommand(linkedlist *list, int value):Command(list),_value(value){
  	cout<<"Construct PushFrontCommand"<<endl;
  }
  ~PushFrontCommand(){
  	cout<<"Destroy PushFrontCommand"<<endl;
  }
  void execute(){
  	_list->pushfront(_value);
  }
  void undo(){
    _list->popfront();
  }
  void redo(){
  	_list->pushfront(_value);
  }
 private:
  int _value;

};
class PopBackCommand : public Command{
 public:
  PopBackCommand(linkedlist *list):Command(list){
    cout<<"Construct PopBackCommand"<<endl;
  }
  ~PopBackCommand(){
    cout<<"Destroy PopBackCommand"<<endl;
  }
  void execute(){
  	pre_value = _list->getlistback();
    _list->popback();
  }
  void undo(){
  	_list->pushback(pre_value);
  }
  void redo(){
  	pre_value = _list->getlistback();
    _list->popback();
  }  
 private:
  int pre_value; 
};
class PopFrontCommand : public Command{
 public:
  PopFrontCommand(linkedlist *list):Command(list){
  	cout<<"Construct PopFrontCommand"<<endl;
  }
  ~PopFrontCommand(){
  	cout<<"Destroy PopFrontCommand"<<endl;
  }
  void execute(){
  	pre_value = _list->getlistfront();
  	_list->popfront();
  }
  void undo(){
  	_list->pushfront(pre_value);
  }
  void redo(){
  	pre_value = _list->getlistfront();
  	_list->popfront();  	
  } 
 private:
  int pre_value;  
};
class PrintprintCommand : public Command{
 public:
  PrintprintCommand(linkedlist *list):Command(list){
    cout<<"Construct PrintprintCommand"<<endl;
  }
  ~PrintprintCommand(){
    cout<<"Destroy PrintprintCommand"<<endl;
  }
  void execute(){
  	_list->printprint();
  }
  void undo(){
  	
  }
  void redo(){
  	_list->printprint();
  }  
};
class MacroCommand : public Command{
 public:
  MacroCommand(linkedlist *list):Command(list){

  }
  void addcommand(Command *comm){
    commandvec.push_back(comm);
  }
  void execute(){
  	for(int i=0;i<commandvec.size();i++){
      commandvec[i]->execute();
    }
  }
 private:
  vector<Command*> commandvec;

};

class Invoker{
 public:
  Invoker(){
  	cout<<"Construct Invoker"<<endl;
  }
  ~Invoker(){
  	cout<<"Destroy Invoker"<<endl;
  }
  void executeCommand(Command *comm){
  	comm->execute();
  	commandvec.push_back(comm);
  }
  void undo(){
    undocommand = commandvec.back();
    undocommand->undo();
    commandvec.pop_back();
  }
  void redo(){
    redocommand = commandvec.back();
    redocommand->redo();
  }
  void setCommand(Command *comm){
    commandvec.push_back(comm);
  }
  void run(){
    for(int i=0;i<commandvec.size();i++){
      commandvec[i]->execute();
    }
  }
  void undoall(){
    while(!commandvec.empty()){
      undocommand = commandvec.back();
      undocommand->undo();
      commandvec.pop_back();
    }
  }
 private:
  vector<Command*> commandvec;
  Command* undocommand;
  Command* redocommand;

};

int main(){

  Invoker *invoker = new Invoker();// 發命令物件
  linkedlist *listlist_ = new linkedlist();// 執行命令物件

  Command *pushback1 = new PushBackCommand(listlist_ ,10);// 命令
  Command *pushback2 = new PushBackCommand(listlist_ ,20);// 命令
  Command *pushfront1 = new PushFrontCommand(listlist_,30);// 命令
  Command *popfront1 = new PopFrontCommand(listlist_); 
  Command *popback1 = new PopBackCommand(listlist_);
  Command *print = new PrintprintCommand(listlist_);

  invoker->executeCommand(pushback1);
  invoker->executeCommand(pushback2);
  invoker->executeCommand(pushback1);
  invoker->executeCommand(pushback2);
  invoker->undo();
  invoker->undo();
  invoker->undo();
  invoker->executeCommand(print);


 /* invoker->executeCommand(pushback1);
  invoker->redo();
  invoker->redo();
  invoker->redo();
  invoker->redo();
  invoker->redo();
  invoker->executeCommand(print);
  invoker->setCommand(pushback1);
  invoker->setCommand(pushback2);
  invoker->setCommand(pushback1);
  invoker->run();
  invoker->undoall();
  invoker->executeCommand(print);*/
  return 0;
}