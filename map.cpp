#include <map>
#include <iostream>
#include <vector>

using namespace std;

int main(){

	std::map<char,int>::iterator it;
	std::map<char, int> mymap;

	mymap['a'] = 100;
	mymap['b'] = 200;	
	mymap['c'] = 300;


	// show content:
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.insert(std::pair<char, int> ('d',400));

	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout<<it->first << " => " << it->second <<std::endl;


	it = mymap.find('c');
	if(it != mymap.end())
		std::cout<< it->second <<std::endl;

	it = mymap.find('b');
	if(it != mymap.end())
		mymap.erase(it);


	// print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';


	return 0;
}