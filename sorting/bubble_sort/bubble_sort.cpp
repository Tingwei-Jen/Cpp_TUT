#include "iostream"

using namespace std;

void bubble_sort(int data[],int size){

  int flag,temp;
  for(int i=0;i< size-1 ;i++){
    flag = 0;
    for(int j=0;j< size-i-1;j++ ){
      if(data[j]>data[j+1]){
        flag =1;
        temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
      }
    }
    if(flag==0){
      break;	
    }
  }
}
void select_sort(int data[],int size){

  int min,temp;
  for(int i=0;i<size-1;i++){
    min = i;
    for(int j=i+1; j<size; j++){
      if(data[j]<data[min])
      	min = j;
    }
    temp = data[min];
    data[min] = data[i];
    data[i] = temp;
  }
}



int main(){

  int data[5];
  data[0] = 10;
  data[1] = 8;
  data[2] = 6;
  data[3] = 4;
  data[4] = 2;

  //bubble_sort(data,5);
  select_sort(data,5);
  for(int i=0;i<5;i++){
    cout<<data[i]<<"  ";
  }
  cout<<endl;

  return 0;	
}
