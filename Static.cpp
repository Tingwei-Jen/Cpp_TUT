/*
 * Static.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: tingwei
 *  
 *  ref : http://kamory0931.pixnet.net/blog/post/119201381
 */

#include <iostream>
using namespace std;

class A{
public:
	A(){
		cout<<"Construct A "<<endl;
		count++;
	}
    static int getvalue(){
    	return value_;
    }
    static int getcount(){
    	return count;
    }

private:
	static int value_;
	static int count;
};

//use non-static variables and functions
class B{
public:
	B(){
		m_pthis = this;
		value_b_ = 10;
		value_c_ = 20;
	}

	static int GetValue(){
		return value_;
	}
	static int GetValue_b(){
		return m_pthis->value_b_;
	}
	static int StaticGetValue_c(){
		return m_pthis->GetValue_c();
	}
	int GetValue_c(){
		return value_c_;
	}
	void SetValue_c(int val){
		value_c_ = val;
	}

private:
	static B *m_pthis;
	static int value_;
	int value_b_;
	int value_c_;

};

int A::value_ = 10; //static variables initialization
int A::count = 0;
B *B::m_pthis = 0;
int B::value_ = 10;

int main(){

	cout<<"A::GetValue(): "<<A::getvalue()<<endl;
	A a1;
	cout<<"a1.GetCount(): "<<a1.getcount()<<endl;
	cout<<"A::GetCount(): "<<A::getcount()<<endl;
	A a2;
	cout<<"a2.GetCount(): "<<a2.getcount()<<endl;
	cout<<"A::GetCount(): "<<A::getcount()<<endl;


	cout<<"B::GetValue(): "<<B::GetValue()<<endl;
	B b1;
	cout<<"b1.GetValue_b(): "<<b1.GetValue_b()<<endl;
	cout<<"b1.GetValue_c(): "<<b1.GetValue_c()<<endl;
	cout<<"b1.StaticGetValue_c(): "<<b1.StaticGetValue_c()<<endl;
	B b2;
	cout<<"b2.GetValue_b(): "<<b2.GetValue_b()<<endl;
	b2.SetValue_c(1000);
	cout<<"b2.StaticGetValue_c(): "<<b2.StaticGetValue_c()<<endl;
	cout<<"b1.StaticGetValue_c(): "<<b1.StaticGetValue_c()<<endl;
	cout<<"b1.GetValue_c(): "<<b1.GetValue_c()<<endl;

	return 0;
}


