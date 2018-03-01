#include "stdio.h"
#include <iostream> 

int factorial1(int n){
  
  if(n==1 || n==0)
  	return(1);
  else 
  	return(n*factorial1(n-1));
}

int factorial2(int n){

  int sum = 1;
  if(n==1 || n==0)
    return(1);
  else {
  	for(int i=2;i<n+1;i++)
  	  sum = sum*i;
  	return sum;
  }
}

int fibonacci(int n){
  if(n==0)
  	return (0);
  else if(n==1)
  	return (1);
  else 
  	return (fibonacci(n-1)+fibonacci(n-2));
}

int main(){

  int ans;
  //ans = factorial(10);
  //ans = factorial2(10);
  ans = fibonacci(10);
  printf("%d ",ans);
}