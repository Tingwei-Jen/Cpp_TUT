#include "iostream"

using namespace std;

class Apple
{
public:
	Apple();
public:
	int apple;
};

class B
{
public:
	B();
	void addA(Apple* A)
	{
		curr_ = A;
		curr_->apple = 100;
	}
public:
	Apple* curr_;

};

int main()
{
	Apple* AA;
	AA->apple = 10;
	cout<<"apple : "<<AA->apple<<endl;

	B* BB;
	BB->addA(AA);
	cout<<"apple : "<<AA->apple<<endl;   //change!!!!

	return 0;
}