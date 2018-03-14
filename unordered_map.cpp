#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	//declaration container and iterator
	unordered_map<int, std::string> map;
	unordered_map<int, std::string> map2;
	unordered_map<int, std::string>::iterator it;
	
	//insert element
	//1.
	map.insert(make_pair(1, "A"));
	map.insert(make_pair(2, "B"));
	map.insert(make_pair(3, "C"));
	map.insert(make_pair(4, "D"));
	//2.
	map[5] = "E";
	//3.
	map2 = {{6,"Canberra"}};


	//traversal
    //1.
	for (it = map.begin(); it != map.end(); it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
	//2.
	for (auto iter = map.begin(); iter != map.end(); iter++)
	{
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	cout<<endl;
	//3.
	for (auto& x: map) 
	{
		std::string a;
		a = x.second;
		cout<<x.first <<" "<< a<<endl;
	}
	cout<<endl;


	//find and erase the element
	it = map.find(3);
	if (it != map.end())
		cout<<"found: "<<it->second<<endl;
	else
		cout<<"not found"<<endl;

	map.erase(it);

	it = map.find(3);
	if (it != map.end())
		cout<<"found: "<<it->second<<endl;
	else
		cout<<"not found"<<endl;	
	
	return 0;
}