#include "stdio.h"
#include <iostream> 
#include <vector>
#include <list>
#include <stack>
using namespace std;

void vectorpractice(){
  
  vector<int> v;
    
  v.push_back(10);
  v.push_back(20);
  v.push_back(30);
  v.push_back(40);
  v.push_back(50);
  v.push_back(60);
  v.push_back(70);
  v.push_back(80);
  v.push_back(90);
  v.pop_back();
/*  v.resize(10);
  v.reserve(30);*/

  for(int i=0;i<v.size();i++)
    cout<<v[i]<<"  ";
  printf("\n");
  cout<<v.empty()<<"  "<<v.size()<<"  "<<v.capacity()<<endl;   
  cout<<v.front()<<"  "<<v.back()<<"  "<<v.at(1)<<"  "<<endl;
  
  for(std::vector<int>::iterator it = v.begin();it != v.end(); ++it)
  	cout<<*it<<"  ";
  cout<<endl;

  v.clear();
  cout<<v.size()<<"  "<<v.capacity()<<endl;
}

void stackpractice(){
  std::stack<int> mystack;
  mystack.push(10);
  mystack.push(20);
  mystack.push(30);
  mystack.push(40);
  mystack.push(50);
  mystack.pop();
  while (!mystack.empty()){
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';
}

void listpractice(){
  
  std::list<int> mylist (2,100);
  mylist.push_front (200);
  mylist.push_front (300);
  mylist.push_back(600);
  mylist.pop_back();


  for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout <<*it<<"  ";
  std::cout << '\n';
  cout<<mylist.front()<<"  "<<mylist.back()<<endl;
  cout<<mylist.max_size()<<"  "<<mylist.size()<<endl;

}





#define max 5

int ary[max];
int top = -1;

void stack_push(int val){

  if(top>=max-1)
    printf("stack is full\n");
  else {
    top++;
    ary[top] = val; 
  }
}
void stack_pop(){
  if(top<0)
    printf("stack is empty\n");
  else 
    top--;
}

int queue[max];
int rear = -1;
int front = 0;

int enqueue(int val){
  if(rear>=max-1)
    printf("queue is full");
  else{
    rear++;
    queue[rear] = val;
  }
}

int dequeue(){
  if(front==rear)
    printf("queue is empty");
  else {
    front++;
  }
}

int main(){

  //vectorpractice();
  /*stack_push(10);
  stack_push(20);
  stack_push(30);
  stack_pop();
  stack_pop();
  for(int i=0;i<top+1;i++)
    printf("%d ",ary[i]);
  printf("\n");*/

  //stackpractice();
  listpractice();
  /*enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  dequeue();
  dequeue();

  for(int i=front;i<rear+1;i++)
    printf("%d ",queue[i]);
  printf("\n");*/
}