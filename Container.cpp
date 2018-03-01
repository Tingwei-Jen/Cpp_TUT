
#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

void vectortut();
void stacktut();
void listtut();

int main() {

	vectortut();
	stacktut();
	listtut();
	return 0;
}

void vectortut(){

	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.pop_back();

	cout<<"size: "<<v1.size()<<endl;

	for(int i=0; i<v1.size(); i++)
		cout<<v1[i]<<"  ";
	cout<<endl;

	cout<<v1.empty()<<"  "<<v1.size()<<"  "<<v1.capacity()<<endl;
	cout<<v1.front()<<"  "<<v1.back()<<"  "<<v1.at(1)<<"  "<<endl;

	cout << "v1 contains:  ";
	for (vector<int>::iterator it = v1.begin() ; it != v1.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';

	v1.clear();
	cout<<v1.empty()<<"   "<<v1.capacity()<<endl;

}

void stacktut(){

	stack<int> s1;
	cout<<"Stack empty ? "<<s1.empty()<<endl;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);

	while(!s1.empty()){
		cout<<s1.top()<<"  ";
		s1.pop();
	}
	cout<<endl;

}

void listtut(){

	list<int> l1;
	list<int> l2(5,20);

	for (list<int>::iterator it=l2.begin(); it!=l2.end(); ++it)
		cout <<*it<<"  ";
	cout << '\n';

	l1.push_front (200);
	l1.push_front (300);
	l1.push_back(600);
    //l1.pop_back();

	for (list<int>::iterator it=l1.begin(); it!=l1.end(); ++it)
	    cout <<*it<<"  ";
	cout << '\n';

	cout<<l1.front()<<"  "<<l1.back()<<endl;
	cout<<l1.max_size()<<"  "<<l1.size()<<endl;
}
