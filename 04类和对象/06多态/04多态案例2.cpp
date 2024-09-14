#include <iostream>
using namespace std;

//多态案例2，制作饮品
class AbstractDrinking
{
public:
    //以下函数代表制作饮品的各个步骤
    virtual void Boil()=0;
    virtual void Brew()=0;
    virtual void PourInCup()=0;
    virtual void PutSomething()=0;
    void makeDrink()
    {
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }
};

//制作咖啡
class Coffee: public AbstractDrinking
{
    virtual void Boil()
    {
        cout<<"煮农夫山泉"<<endl;
    }
    virtual void Brew()
    {
        cout<<"冲泡咖啡"<<endl;
    }
    virtual void PourInCup()
    {
        cout<<"倒入杯中"<<endl;
    }
    virtual void PutSomething()
    {
        cout<<"加入糖和牛奶"<<endl;
    }
};

//制作茶叶
class Tea: public AbstractDrinking
{
    virtual void Boil()
    {
        cout<<"煮矿泉水"<<endl;
    }
    virtual void Brew()
    {
        cout<<"冲泡茶叶"<<endl;
    }
    virtual void PourInCup()
    {
        cout<<"倒入杯中"<<endl;
    }
    virtual void PutSomething()
    {
        cout<<"加入枸杞"<<endl;
    }
};

void doWork(AbstractDrinking*abs)
{
    abs->makeDrink();
    delete abs;//释放
}

void test01()
{
    //制作咖啡
    doWork(new Coffee);
    cout<<"---------------------"<<endl;
    //制作茶叶
    doWork(new Tea);
}

int main()
{
    test01();
    return 0;
}