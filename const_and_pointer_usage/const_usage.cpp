#include <iostream>

using namespace std;

void PointerTutorial();

void func(const int &a);

const int func2();

class TEST
{
public:
	TEST();
	void set(int number){
		this->number = number;
	}
	int get() const;   ////说明其不会修改数据成员

private:
	int number;
};

TEST::TEST()
{

}
int TEST::get() const 
{
	// number++; //wrong!!
	return number;
}

int main()
{
	/*1.*/
	const int a = 100;
	// a = 10;   //wrong !!
	cout<<"a: "<<a<<endl;

	//PointerTutorial();

	/*2.*/
	const int *b=&a; //指向常數的指針，即指針本身的值是可以改變的，
					 //但指向的內容是不能改變的;

	// *b = 10; //wrong !!
	
	/*3.*/
	int c = 1;
	cout<<"c: "<<c<<endl;
	int * const d = &c; //常指針，即指針本身的值是不可改變的，
      					//但指向的內容是可改變的;

	*d = 10;  //ok
	cout<<"c: "<<c<<endl;

	/*4.*/
	func(50);

	/*5.*/
	const int output = func2();
	//output = 40;   //wrong!!
	cout<<"output: "<<output<<endl;

	/*6.*/
	TEST test;
	test.set(5000);
	int g = test.get();
	cout<<"g: "<<g<<endl;



	return 0;
}

//如果输入参数采用“值传递”，由于函数将自动产生临时变量用于复制该参数，
//该输入参数本来就无需保护，所以不要加const 修饰。
//例如不要将函数void Func1(int x) 写成void Func1(const int x)。
//同理不要将函数void Func2(A a) 写成void Func2(const A a)。

//对于非内部数据类型的参数而言，象void Func(A a) 这样声明的函数注定效率比较底。
//因为函数体内将产生A 类型的临时对象用于复制参数a，而临时对象的构造、复制、析构过程都将消耗时间。
//为了提高效率，可以将函数声明改为void Func(A &a)
//但是函数void Func(A &a) 存在一个缺点：“引用传递”有可能改变参数a
//解决这个问题很容易，加const修饰即可，因此函数最终成为void Func(const A &a)。

void func(const int &a)
{
 	//a = 100;  //wrong!!
	cout<<"input: "<<a<<endl;
}
const int func2()
{
	return 50;
}

void PointerTutorial()
{

	int b = 2;

    cout<<"變數 b 的值: "<<b<<endl;
    cout<<"變數 b 的記憶體位址："<<&b<<endl;  //有個運算符號是用來「取址」，就是「&」。
    cout<<"變數 b 的值："<<*&b<<endl;//從這個地址中取出變數b的值  
                                    //use "*" get value in that address
    								//*&b == b 
    //指標 (Pointer) 就是某變數的位址。
    //而這邊的指標變數 (Pointer Variable)，則是用來存放指標的變數。
    //指標變數就是用來存「地址」的變數。

    int c = 2;
    int* pointer = &c;
 
    printf("變數 c 的值：%d\n", c);
    printf("變數 c 的地址：%p\n", &c);
    printf("pointer 的值：%p\n", pointer);
    printf("\n"); //換行
    
    *pointer = 100;     //*pointer 代表的就是變數 c !!!
 
    printf("*pointer 的值：%d\n", *pointer);
    printf("變數 c 的值：%d\n", c);
    printf("變數 pointer 的地址：%p\n", &pointer);
    printf("pointer 的值：%p\n", pointer);


    int d = 5;
    pointer = &d; 
	//把變數b的地址值給pointer，注意不能寫成 pointer = b;
    printf("*pointer 的值：%d\n", *pointer);
    printf("變數 pointer 的地址：%p\n", &pointer);
    printf("pointer 的值：%p\n", pointer);
}