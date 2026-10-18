#include<iostream>
#include<cstdlib>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

#define STACK_INIT_SIZE 100
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;

Status InitStack(SqStack &S);
void CreateStack(SqStack &S);
Status Push(SqStack &S,SElemType x);
Status Pop(SqStack &S,SElemType &e);
Status GetTop(SqStack S,SElemType &e);
int StackLength(SqStack S);
void PrintStack2(SqStack S);
void PrintStack(SqStack S);

int main(){
    SqStack S;
    InitStack(S);
    int choice;
    SElemType x,e;
    cout << "请选择：" << endl;
    cout << "1. 创建栈(输入正数,-1结束)" << endl;
    cout << "2. 入栈" << endl;
    cout << "3. 弹出栈顶元素" << endl;
    cout << "4. 获取栈顶元素" << endl;
    cout << "5. 求栈长度" << endl;
    cout << "6. 输出所有元素" << endl;
    cout << "0. 退出" << endl;
    while(true){
        cout << "\n请输入选项：";
        cin >> choice;
        if(choice == 0){
            cout << "程序结束";
            break;
        }
        switch(choice){
            case 1:
                CreateStack(S);
                break;
            case 2:
                cout << "请输入要入栈的正整数x：";
                cin >> x;
                if(x <=0){
                    cout << "非法！必须输入正整数" << endl;
                    break;
                }
                if(Push(S,x)){
                    cout << x << "入栈成功！当前栈（栈顶→栈底）：";
                    PrintStack2(S);
                }else{
                    cout << "栈满，入栈失败！" << endl;
                }
                break;
            case 3:
                if(Pop(S,e)){
                    cout << "弹出的元素值 = " << e << endl;
                    cout << "当前栈（栈顶→栈底）：";
                    PrintStack2(S);
                }else{
                    cout << "栈空，无法弹出！" << endl;
                }
                break;
            case 4:
                if(GetTop(S,e)){
                    cout << "栈顶元素值：" << e << endl;
                }else{
                    cout << "栈为空！" << endl;
                }
                break;
            case 5:
                cout << "栈当前长度 = " << StackLength(S) << endl;
                break;
            case 6:
                cout << "栈底到栈顶元素：";
                PrintStack2(S);
                cout << endl;
                break;
            default:
                cout << "选项输入错误，请重新选择！" << endl;
        }
    }
    delete [] S.base;
    return 0;
}

Status InitStack(SqStack &S){
    S.base = new SElemType[STACK_INIT_SIZE];
    if(!S.base) exit(OVERFLOW);
    S.top = S.base;//这里是用来初始化 两个指针在一起
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

void CreateStack(SqStack &S){
    SElemType num;
    cout << "请按入栈顺序输入元素 输入-1结束" << endl;
    while(cin >> num){
        if(num == -1)break;
        if (num <= 0){
            cout << "请输入正整数！" << endl;
            continue;
        }
        if(Push(S,num) == ERROR){
            cout << "栈满 无法添加！" << endl;
            break;
        }
        cout << "创建完成！";
        PrintStack(S);
    }
}

Status Push(SqStack &S,SElemType x){
    if(S.top - S.base >= S.stacksize){//相减如果不小于栈长 代表已经满了
        return ERROR;
    }
    *S.top = x;
    S.top++;
    return OK;
}

Status Pop(SqStack &S,SElemType &e){
    if(S.top == S.base){//指针在一起 代表没有任何元素
        return ERROR;
    }
    S.top --;
    e = *S.top;
    return OK;
}

Status GetTop(SqStack S,SElemType &e){
    if(S.top == S.base){
        return ERROR;
    }
    e = *(S.top - 1);
    return OK;
}

int StackLength(SqStack S){
    return S.top - S.base;
}

void PrintStack(SqStack S){
    if(S.top == S.base){
        cout << "栈为空！";
        return;
    }
    SElemType *p = S.base;
    cout << "从底到顶：";
    while(p < S.top){
        cout << *p << " ";
        p++;
    }

}

void PrintStack2(SqStack S){
    if(S.top == S.base){
        cout << "栈为空！" << endl;
        return;
    }
    SElemType *p = S.top-1;
    while(p >= S.base){//在同一片内存中 指针也可以比大小
        cout << *p << " ";
        p --;
    }
    cout << endl;
}