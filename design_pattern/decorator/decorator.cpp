#include <iostream>
using namespace std;

class Beverage{
  public:
    Beverage(){
        cout<<"Construct Beverage"<<endl;
    }
    virtual ~Beverage(){
        cout<<"Destroy Beverage"<<endl;
    }

    virtual void do_it() = 0;
    virtual double cost() = 0;
};

class coffee : public Beverage{
public:
    coffee(){
        cout<<"Construct Coffee"<<endl;
    }
    ~coffee(){
        cout<<"Destroy Coffee"<<endl;
    }
    /*virtual*/void do_it(){
        cout<<"Coffee ";
    }
    /*virtual*/double cost(){
        return 2.0;
    }
   
};

class decorator : public Beverage{
public:
    decorator(){
        cout<<"Construct Decorator"<<endl;
    }
    ~decorator(){
        cout<<"Destroy Decorator"<<endl;
    }
   
protected:
   

};
class milk : public decorator{
public:
    milk(Beverage *beverage):_beverage(beverage){
        cout<<"Construct Milk"<<endl;
    }
    ~milk(){
        cout<<"Destroy milk"<<endl;
    }
    /*virtual*/void do_it(){
        _beverage->do_it();
        cout<<"add milk ";
   
    }
    /*virtual*/double cost(){
        return 2.0 + _beverage->cost();
   
    }
   
private:
    Beverage *_beverage;

};
class choco : public decorator{
public:
    choco(Beverage *beverage):_beverage(beverage){
        cout<<"Construct Choco"<<endl;
    }
    ~choco(){
        cout<<"Destroy Choco"<<endl;
    }
    /*virtual*/void do_it(){
        _beverage->do_it();
        cout<<"add choco ";
    }
    /*virtual*/double cost(){
        return 3.0 + _beverage->cost();
       
    }
private:
    Beverage *_beverage;

};

int main(int argc, const char * argv[]) {
    
    Beverage *beverage1;
    beverage1 = new coffee();
    beverage1->do_it();
    cout<<beverage1->cost()<<endl;
   
    Beverage *beverage2;
    beverage2 = new choco(new milk(new milk(new coffee())));
    beverage2->do_it();
    cout<<beverage2->cost()<<endl;
   
   
    ////recursive!!!!!!!
   
    delete beverage1;
    delete beverage2;
   
    return 0;
}