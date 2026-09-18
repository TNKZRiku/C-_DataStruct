#include <iostream>
using namespace std;

void swap(int num_a,int num_b);
void swap1(int *path_a,int *path_b);
void swap2(int &num_a,int &num_b);
void swap3(int &num_a,int &num_b);
void Circle_perimeter(float radius,float &peri);

int main()
{
    int k;
    int a = 6,b = 7;
    float radius = 2.5;
    float peri;

    do{
        cout << endl <<"选择方法：" << endl;
        cout << "1.swap" << endl;
        cout << "2.swap1" << endl;
        cout << "3.swap2" << endl;
        cout << "4.swap3" << endl;
        cout << "5.Circle_Perimeter" << endl;
        cout << "0.退出" << endl;
        cout << "请输入你的选择：" << endl;
        cin >> k;
        
        switch(k)
        {
            case 1:
                cout << "Before:" << a << " " << b << endl;
                swap(a,b);
                cout << "After:" << a << " " << b << endl;
                break;

            case 2:
                cout << "Before:" << a << " " << b << endl;
                swap1(&a,&b);
                cout << "After:" << a << " " << b << endl;
                break;

            case 3:
                cout << "Before:" << a << " " << b << endl;
                swap2(a,b);
                cout << "After:" << a << " " << b << endl;
                break;

            case 4:
                cout << "Before:" << a << " " << b << endl;
                swap3(a,b);
                cout << "After:" << a << " " << b << endl;
                break;

            case 5:
                Circle_perimeter(radius,peri);
                cout << "半径为" << radius << "的圆周长约等于" << peri <<endl;
                break;

            case 0:
                cout << "程序退出！";
                break;
            
            default:
                cout << "输入非法！请重试" << endl;


        }
    }while(k != 0);
    return 0;

}

void swap(int num_a,int num_b)
{
    int temp = num_a;
    num_a = num_b;
    num_b = temp;
}

void swap1(int *path_a,int *path_b)
{
    int temp1 = *path_a;
    *path_a = *path_b;
    *path_b = temp1;
}

void swap2(int &num_a,int &num_b)
{
    int temp2 = num_a;
    num_a = num_b;
    num_b = temp2;
}

void swap3(int &num_a,int &num_b)
{
    int temp3 = num_a;
    num_a = num_b;
    num_b = temp3;
}

void Circle_perimeter(float radius,float &peri)
{
    peri = radius*2*3.1416;
}