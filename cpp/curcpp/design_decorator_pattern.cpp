// more easy example https://www.tutorialspoint.com/design_pattern/decorator_pattern.htm
#include<iostream>
using namespace std;

class Burger{
public:
    virtual int get_cost() = 0;
};

class ConcretteBurger: public Burger{
public:
    int get_cost(){
        return 3;
    }
};

class BurgerDecorator:public Burger{
private:
    Burger *b;

public:
    BurgerDecorator(Burger* bb){
      b = bb;
    }
    ~BurgerDecorator(){
        delete b;
    }
    int get_cost(){
        return b->get_cost();
    }
};

class Tomato:public BurgerDecorator{
public:
    Tomato(Burger *b):BurgerDecorator(b){

    }
    int get_cost(){

        return BurgerDecorator::get_cost() + 4;
    }
};
class Cheese:public BurgerDecorator{
public:
    Cheese(Burger *b):BurgerDecorator(b){}
    int get_cost(){
        return BurgerDecorator::get_cost()+3;

    }
};

int main(){
    Burger* burger = new ConcretteBurger();
    Burger* burgerWithCheese = new Cheese(burger);
    cout<<burgerWithCheese->get_cost();

    system("pause");
}
