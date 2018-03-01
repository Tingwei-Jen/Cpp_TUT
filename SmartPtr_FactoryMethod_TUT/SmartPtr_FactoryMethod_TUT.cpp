#include <iostream>
#include <memory>

using namespace std;

class Dog
{
public: 
	Dog(){
		cout<<"build a dog"<<endl;
	}
	Dog(int id):_id(id){
		cout<<"build a dog"<<"id: "<<_id<<endl;
	}

	static Dog* createDog();  //factory method 
							  //static, mean belong to class not object
private:
	int _id;
};

Dog* Dog::createDog()
{
	Dog *dog = new Dog();
	return dog;
}

void SharedPtr_ex(){

	std::shared_ptr<int> p1;
  	std::shared_ptr<int> p2 (nullptr);
  	std::shared_ptr<int> p3 (new int);
  	std::shared_ptr<int> p4 (new int(10));
  	std::shared_ptr<int> p5 (p4);
  	// how much pointer point to same place in the same time
    std::cout << "use_count:\n";
  	std::cout << "p1: " << p1.use_count() << '\n';
  	std::cout << "p2: " << p2.use_count() << '\n';
  	std::cout << "p3: " << p3.use_count() << '\n';
  	std::cout << "p4: " << p4.use_count() << '\n';
  	std::cout << "p5: " << p5.use_count() << '\n';
}

class Cat
{
public:
	Cat(){
		cout<<"build a cat"<<endl;
	}

	typedef std::shared_ptr<Cat> ptr;
	static Cat::ptr createCat();
};

Cat::ptr Cat::createCat()
{
	return Cat::ptr(new Cat());   //two methods are same
/*	Cat::ptr p1(new Cat());
	return p1;*/
}

int main()
{
	Dog *dog = Dog::createDog();
	SharedPtr_ex();
	Cat::ptr cat = Cat::createCat();

	return 0;
}