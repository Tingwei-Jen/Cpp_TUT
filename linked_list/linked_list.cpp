#include "stdio.h"
#include "new"
class Node{
 public:
  Node(int val){

  	value_ = val;
  	next_ = NULL;
  }
  Node *next_;
  Node *previous_;
  int value_;

};

class myList{
 public:
  myList(){
 	head = NULL;
  }
  

  void pushback(int value){
    Node *new_node = new Node(value);
    if(!head){
      head = new_node;
      tail = new_node;
    } else {
      Node *p = head;
      while(1){
        if(!p->next_){
          p->next_ = new_node;
          new_node->previous_ = tail;
          tail = new_node;
          break;
        } else {
          p = p->next_;
        }
      }        
    }
  }
  void pushfront(int value){
    Node *new_node = new Node(value);
    if(!head){
      head = new_node;
      tail = new_node;
    } else {
      Node *p = tail;
      while(1){
        if(!p->previous_){
          p->previous_ = new_node;
          new_node->next_ = head;
          head = new_node;
          break;
        } else{
          p = p->previous_;
        }
      }
    }
  }
  int front(){
    
    if(!head)
      return 0;    
    else 
    return head->value_; 
  } 

  void removeback(){

    Node *p= head;
    Node *backhouse;
    backhouse = tail;
    if (!head)
      return;
    else if(size()==1){
      delete head;	
      head = NULL;
      return;
    } else {
      tail = tail->previous_;
      while(1){
        if(!p->next_->next_){
          delete p->next_;
          p->next_ = NULL;
          return;
        } else {
          p = p->next_;
        }
      }
    }
  }
  void removefront(){
    
    Node *p= tail;
    Node *fronthouse;
    fronthouse = head;
    if (!head)
      return;
    else if(size()==1){
      delete head; 
      head = NULL;
      return;
    } else {      
      head = head->next_;
      while(1){
        if(!p->previous_->previous_){
          delete p->previous_;
          p->previous_ = NULL;
          return;
        } else {
          p = p->previous_;
        }
      }
    }
  } 
  int size(){
    
    int size_num = 0;
    if(!head){
      return size_num;
    }
    else {
      Node *p;
      p = head;
      while(1){
        if(p)
          size_num ++; 
        else 
          break;
        p = p->next_;
      }
      return size_num;
    }
  }

  int get(int index){
   
    int size_num = 0;
   
    Node *p;
    p = head;
    while(1){
      if(p){
        if(index == size_num){
          return p->value_;
        }
        size_num ++; 
      }
      else
        break;
      p = p->next_;    
    }
  }

  void print_from_tail(){  
    Node *q;
    q = tail;
    if(!q){
      return;
    } else if(size()==1){ 
      printf("%d ",q->value_);
    } else {
      while(1){
        if(q)
          printf("%d ",q->value_);
        else 
          break;
        q = q->previous_;   
      }
    }
    printf("\n");
  }

 private:
  Node *head;
  Node *tail;
};

struct node{
  node(int val){
    value = val;
    next = NULL;
  }
  int value;
  node *next;
};

node* pushbackrecursive(node* p,int val){
  if(!p){
    node *new_node = new node(val);
    p=new_node;
  } else {
    p->next = pushbackrecursive(p->next,val);
  }
  return p;
}

void printorder(node* p){
  if(p){
    printf("%d \n",p->value);
    printorder(p->next);
  }
}

int main(){

  node* HEAD;
  HEAD = pushbackrecursive(HEAD,10);
  HEAD = pushbackrecursive(HEAD,20);
  HEAD = pushbackrecursive(HEAD,30);
  HEAD = pushbackrecursive(HEAD,40);
  printorder(HEAD);

  //myList list;
  /*list.pushback(10);
  list.pushback(20);
  list.pushback(30);
  list.pushfront(60);
  list.pushfront(70);
  //list.removeback();
  list.removefront();
  for(int i=0;i<list.size();i++){
    printf("size:%d i:%d:%d\n",list.size(),i,list.get(i));
  }
  list.print_from_tail();*/
}