/*
 * Demo.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: tingwei
 */

#include <iostream>
using namespace std;

class Demo{
 public:
  Demo();
  Demo(int n1, int n2);
  ~Demo();
  void setA(int n);
  void setB(int n);
  int getA();
  int getB();
  int cal();

 private:
  int a;
  int b;
  int *array;

};

Demo::Demo():a(10),b(20){
	cout<<"Construct Demo & array!!"<<endl;
	array = new int [10];

}
Demo::Demo(int n1, int n2){
	cout<<"Construct Demo2 & array!!"<<endl;
	this->a = n1;
	this->b = n2;
	array = new int [10];
}
Demo::~Demo(){
	cout<<"Destructor Demo & array"<<endl;
	delete [] array;

}
void Demo::setA(int n){
	this->a = n;
}
void Demo::setB(int n){
	this->b = n;
}
int Demo::getA(){
	return this->a;
}
int Demo::getB(){
	return this->b;
}
int Demo::cal(){
	return getA()+getB();
}


int main(){

	Demo demo;
	demo.setA(100);
	demo.setB(200);
	cout<<demo.getA()<<endl;
	cout<<demo.getB()<<endl;
	cout<<demo.cal()<<endl;

	Demo *_demo = new Demo(1000,2000);
	_demo->setA(1500);
	_demo->setB(2500);
	cout<<_demo->getA()<<endl;
	cout<<_demo->getB()<<endl;
	cout<<_demo->cal()<<endl;

	delete _demo;

	return 0;




}

