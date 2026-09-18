#define OK 1
#define False 0
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


int plus_func(int i1 = 1,int i2 = 2) //函数可以传默认值
{
    return i1 + i2;
}

void prime(int num)
{
    bool flag;
    int len = int (sqrt(float(num))+1);
    if(len ==  1 || len == 2)
    {
        cout << "请输入正确的数字！";
    }
    else
    {
        for(int i=2;i<len;i++)
        {
            if(num%i == 0)
            {
                cout << num << "=" << i << "x" << num/i;
                flag = false;
                break;
            }
        }
        
    }
    if(flag)
    {
        cout << num << "是一个质数！";
    }

}

void plus_func2(int i1,int i2,int &res)
{
    res = i1 + i2;
}

void samp(int &x,int &y)
{
    int s = x;
    x = y;
    y = s;
}



int main()
{   
    int fal1 = 0;
    bool fal2 = false;
    if(fal1)
    {
        //cout << "0!";
    }
    else if(fal2)
    {
        //cout << "flase!";
    }
    else
    {
        //cout << "none!";
    }

    for(int i = 1;i < 3;i ++)
    {
        //cout << i;
    }
    int ress;
    int outer = plus_func(1,2);
    plus_func2(3,4,ress);
    //cout << outer << ress;
    int x = 6;
    int y = 7;
    //cout << x << y;
    samp(x,y);
    //cout << x << y;
    prime(1479698723);
    return 0;
}