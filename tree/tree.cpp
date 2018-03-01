#include "stdio.h"
#include <iostream> 

struct BstNode{
  BstNode(int val){
    value = val;
    left = NULL;
    right = NULL;
  }
  int value;
  BstNode *left;          //pre
  BstNode *right;         //next
};

class mytree{
 public:
  mytree(){
  }
  BstNode* Insert(BstNode *p,int val){
    if(!p){
      BstNode *new_node = new BstNode(val); //任意門打開沒東西 蓋房子 傳地址回去
      p = new_node;	                       //遞迴必須有結束點 使得函數得以往上追朔回去!!!!!
    }                                      //把地址傳回去
    else if(val <= p->value){
      p->left = Insert(p->left,val);  
    } else{
      p->right = Insert(p->right,val);	
    }
    return p;
  }
  bool search(BstNode *p,int val){
  	if(!p)
  	  return false;                   //<--(結束點)                   
  	else if(p->value == val)
  	  return true;                    //<--(結束點)
  	else if(val <= p->value){
       return( search(p->left,val) );
  	} else {
       return( search(p->right,val) );
  	}
  }
  void inorder(BstNode *p){
  	if(p){
      inorder(p->left);
      printf("%d \n",p->value);  //<--(結束點) 遞迴必須有結束點 使得函數得以往上追朔回去!!!!!
      inorder(p->right);
  	}
  }
  void findmin(BstNode *p){
    BstNode* h = p;
    while(h->left){
      h = h->left;
    }
    printf("%d \n",h->value);
  }
  void findmax(BstNode *p){
    BstNode* h = p;
    while(h->right){
      h = h->right;
    }
    printf("%d \n",h->value);
  }

 private:
};

int main(){
  
  BstNode *root;
  mytree tree; 
  root = tree.Insert(root,30);
  root = tree.Insert(root,20);
  root = tree.Insert(root,10);
  root = tree.Insert(root,40);
  root = tree.Insert(root,50);
  tree.inorder(root);
  printf("%d\n",tree.search(root,30));
  tree.findmin(root);
  tree.findmax(root);
}