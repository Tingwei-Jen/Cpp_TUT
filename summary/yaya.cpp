#include "stdio.h"
#include <iostream> 

#define size 1000 
int array[size];
int bank[size][size];

int summary(int i,int j){
   int sum = 0;
   for(i;i<=j;i++){
     sum = sum+array[i];
   }
   return sum;
}
void calculate(){

  for(int i=0;i<size;i++){
  	for(int j=0;j<size;j++){
      bank[i][j] = summary(i,j); 
  	}
  }
}
int check(int i,int j){
  return (bank[i][j]);
}


int main(){

  for(int i=0;i<1000;i++){
  	array[i] = i;
  }
  calculate();
  int Sum = check(998,999);
  printf("%d \n",Sum);
}