#include<iostream>
using namespace std; //写代码的时候这一行漏掉了 cout用不了才发现

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
typedef int Status;
typedef int ElemType;
typedef  struct{
    ElemType  *elem; 
    int length; //长度
 } SqList;

Status InitList(SqList &L);
Status CreateList(SqList &L);
Status InsertNum(SqList &L);
Status ListDelete(SqList &L);
Status OutputList(SqList &L);
Status SearchData(SqList &L);
Status ReturnData(SqList &L);//声明其实就是把函数第一行复制过来
//声明函数

int main() {
    int choice;
    SqList L;
    L.elem = nullptr;//这里是为了和输出线性表的函数在未初始化的时候能够检测到错误
    L.length = 0;
    while (true) {
        cout << "\n请选择你要进行的操作：";
        cout << "1. 初始化线性表\n";
        cout << "2. 创建包含n个正整数的线性表\n";
        cout << "3. 在第i个元素前插入数字x\n";
        cout << "4. 删除第i个元素\n";
        cout << "5. 按值查找元素（返回位序，无则0）\n";
        cout << "6. 按位置查找并输出元素\n";
        cout << "7. 输出线性表全部元素\n";
        cout << "0. 退出程序\n";
        cout << "\n";
        cout << "请输入操作序号：";
        cin >> choice;

        //菜单
        switch (choice) {
            case 1:
                InitList(L);
                cout << "线性表初始化完成！\n";
                break;
            case 2:
                CreateList(L);
                cout << "\n";
                break;
            case 3:
                InsertNum(L);
                cout << "\n";
                break;
            case 4:
                ListDelete(L);
                cout << "\n";
                break;
            case 5:
                SearchData(L);
                cout << "\n";
                break;
            case 6:
                ReturnData(L);
                cout << "\n";
                break;
            case 7:
                OutputList(L);
                cout << "\n";
                break;
            case 0:
                // 释放分配的内存
                delete[] L.elem;
                cout << "程序已退出\n";
                return 0;
            default:
                cout << "请输入0~7之间的数字！\n";
                break;
        }
    }
}


Status InitList(SqList &L){
    L.elem = new ElemType[LIST_INIT_SIZE];
    if(!L.elem){
        exit(OVERFLOW);//分配失败则退出
         
    }
    L.length = 0;
    return OK;
}

Status CreateList(SqList &L){
    if(!L.elem){
        cout << "线性表未初始化！" << endl;//防止未初始化就创建
        return ERROR;
    }
    int len;
    cout << "请输入线性表长度(不大于100):";
    cin >> len;

    ElemType num;
    cout << "请依次输入线性表的值：";
    for(int i=0;i<len;i++){
        while(true){
            cin >> num;
            if(!cin || num < 0){
                cout << "输入非法！请重试！";
                continue;
            }
            break;
        }
        L.elem[L.length] = num;
        L.length++;//表长增加1
    }
    cout << "创建成功！";
    cout << "当前线性表状态：\n";
    OutputList(L);//线性表有变化 输出
    return OK;
}

Status InsertNum(SqList &L){
    if(!L.elem){
        cout << "线性表未初始化！" << endl;//防止未初始化就创建
        return ERROR;
    }
    //在第i个位置插入e
    if(L.length>=MAXSIZE){
        cout << "已达到最大长度！";//满了就不能插入了
        return ERROR;
    }
    ElemType e;
    int location;
    cout << "请输入你要插入的位置(之前):";
    cin >> location;
    if(location<1 || location>=MAXSIZE){//防止插入不合理的地方
        cout << "位置不允许！";
        return ERROR;
    }
    cout << "请输入插入的内容：";
    cin >> e;
    for(int j=L.length-1;j>=location-1;j--){//这里的循环控制有些不好理解 是在演草纸上面画了一下才明白
        L.elem[j+1]=L.elem[j];
    }
    L.elem[location-1]=e;
    ++L.length;
    cout << "当前线性表状态：\n";
    OutputList(L);//线性表发生变化 输出
    return OK;
}

Status ListDelete(SqList &L){
    if(!L.elem){
        cout << "线性表未初始化！" << endl;//防止未初始化就删除
        return ERROR;
    }
    int location;
    cout << "请输入要删除的元素的位置：";
    cin >> location;
    if(location<1 || location>L.length){//防止删除不存在的位置
        cout << "输入的位置不合法！";
        return ERROR;
    }
    for(int j=location;j<=L.length;j++){
        L.elem[j-1] = L.elem[j];
    }
    --L.length;//表长减一
    cout << "当前线性表状态：\n";
    OutputList(L);
    return OK;
}

Status OutputList(SqList &L){
    if(!L.elem){
        cout << "线性表还未初始化！";//防止未初始化就打印
        return ERROR;
    }
    if(L.length == 0){
        cout << "线性表为空！";//防止是空表
        return ERROR;
    }
    for(int i=0;i<L.length;i++){
        cout << "第" << i+1 << "个元素为" << L.elem[i] << endl; 
    }
    return OK;
    
}

Status SearchData(SqList &L){
    if(!L.elem){
        cout << "线性表未初始化！" << endl;//防止未初始化就搜索
        return ERROR;
    }
    int num;
    cout << "请输入要查找的元素：";
    cin >> num;
    for(int i=0;i<L.length;i++){
        if(L.elem[i]==num){
            cout << "存在此元素！在第" << i+1 << "个位置！";
            return OK;
        }
        cout << "未找到此元素！";
        return 0;
    }    
    return 0;
}

Status ReturnData(SqList &L){
    if(!L.elem){
        cout << "线性表未初始化！" << endl;//防止未初始化就返回值
        return ERROR;
    }
    int Location;
    cout << "请输入要返回的位置：";
    cin >> Location;
    if(Location<L.length || Location>0){
        cout << "第" << Location << "个元素是" << L.elem[Location-1];
        return OK;
    }
    cout << "位置不存在！";
    return ERROR;
}//刚开始总是漏写分号 大概写了五十行才适应
