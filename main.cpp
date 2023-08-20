#include<iostream>
using namespace std;

class Beverage
{
    public:
     virtual int cost()
     {
        return 5;
     }
};
class Coffee :public Beverage
{
    public:
     int cost() override
     {
        return 10;
     }
};
class Tea: public Beverage
{

};
class Espresso : public Coffee
{
    public:
    int cost()
    {
        return Coffee::cost()+50;
    }
};
class Americano :public Coffee
{
    public:
    int cost()
    {
        return Coffee::cost()+55;
    }
};
class GreenTea :public Tea
{
    public:
    int cost()
    {
        return Tea::cost()+30;
    }
};
class WhiteTea :public Tea
{
    public:
    int cost()
    {
        return Tea::cost()+40;
    }
};
class Addons :public Beverage
{
    protected:
    Beverage* wrappee;
    public:
    Addons(){};
    Addons(Beverage* b)
    {
        this->wrappee = b ;
    }
    int cost() override
    {
        return this->wrappee->cost()+ 5;
    }

};
class WippedCream :public Addons
{
    public:
    WippedCream(Beverage* b)
    {
        this->wrappee = b;
    }
    int cost() override{

        return this->wrappee->cost()+ 20;
    }
    
};
class ChocolateSyrup: public Addons 
{
    public:
    ChocolateSyrup(Beverage* b)
    {
        this->wrappee = b ;
    }
    int cost() override
    {
         return this->wrappee->cost()+ 10;
    }
};
class Ginger: public Addons
{
    public:
    Ginger(Beverage* b)
    {
        this->wrappee = b ;
    }
};
class Masala:public Addons
{
    public:
    Masala(Beverage* b)
    {
        this->wrappee = b;
    }
    int cost() override
    {
        return this->wrappee->cost()+10;
    }
};


class Client
{
    public :
    Client()
    {
        Beverage* EspCofeeWithwipCreChocSyrup = new ChocolateSyrup(new WippedCream(new Espresso));
        Beverage* MashalaGingerGreenTea = new Masala(new Ginger(new GreenTea));
        cout<<"The Cost of Espresso coffee with wipped cream and chocolate syrup is  "<<EspCofeeWithwipCreChocSyrup->cost()<<endl;
        cout<<"The cost of Mashala Ginger Green Tea is "<<MashalaGingerGreenTea->cost()<<endl;
    }
};

int main()
{
    Client c1;
    return 0;
}
