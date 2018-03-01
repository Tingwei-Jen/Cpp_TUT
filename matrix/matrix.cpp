#include "stdio.h"
#include <iostream> 


int rowCount1 = 3;
int colCount1 = 2;
int rowCount2 = 2;
int colCount2 = 3;
using namespace std; 

void matrixmultiplication(int **a, int **b){
  
 int** c = new int*[rowCount1];
   for(int i = 0; i < rowCount1; ++i)
    c[i] = new int[colCount2];

  for(int i=0;i<rowCount1;i++){
    for(int j=0;j<colCount2;j++){
      c[i][j] = 0;
	}
  }
  for(int i=0;i<rowCount1;i++){
    for(int j=0;j<colCount2;j++){
      for(int k=0;k<colCount1;k++){
        c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
  for(int i=0;i<rowCount1;i++){  
    for(int j=0;j<colCount2;j++){
   	  printf("%d ", c[i][j]);
    }	
   	printf("\n");
  }
}

int main(){

  int** a = new int*[rowCount1];
  for(int i = 0; i < rowCount1; ++i)
    a[i] = new int[colCount1];

  int** b = new int*[rowCount2];
  for(int i = 0; i < rowCount2; ++i)
    b[i] = new int[colCount2];

  for(int i=0;i<rowCount1;i++){
    for(int j=0;j<colCount1;j++)
      a[i][j] = 1;
  }

  for(int i=0;i<rowCount2;i++){
    for(int j=0;j<colCount2;j++)
      b[i][j] = 1;
  }

  matrixmultiplication(a,b);

  delete a;
  delete b;

  int *aa = new int[10]; //all are zero!!
  aa[1] = 80;
  cout<<*aa<<"  "<<aa[0]<<"  "<<aa[1]<<endl;

  int var = 10;
  int *ptr = &var;
  *ptr = 20; //change the money in the house 
  cout<<var<<"  "<<&var<<endl;
  cout<<ptr<<"  "<<&ptr<<"  "<<*ptr<<endl;


  int *rr = 0;//設定初值為0，表示不指向任何物件
  cout<<rr<<endl;

  int ary[10];
  printf("%p , %p\n", ary, &ary[1]);  //


}

