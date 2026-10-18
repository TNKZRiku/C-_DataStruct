#include<iostream>
using namespace std;

#define OK 1;
#define ERROR 0;
typedef int Status;
typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next; //这里可以在声明的时候写进去 不影响运行
}LNode,*Linklist;

Status Initlist(Linklist &L);
Status Createlist(Linklist &L);
Status Listinsert(Linklist &L, int i, Elemtype x);
Status Listdelete(Linklist &L, int i, Elemtype &e);
int Locateelem(Linklist L, Elemtype e);
Status Getelem(Linklist L, int i);
Status Printlist(Linklist L);


int main()
{
    Linklist L;
    int choice;    
    int i, pos;    
    Elemtype x, e, target; //写这一段的时候 一开始写的变量不够 是后来又补的

    while (true)
    {
        cout << "\n请选择你要进行的操作：" << endl;
        cout << "1. 初始化链表" << endl;
        cout << "2. 创建n个正整数链表" << endl;
        cout << "3. 在第i个元素前插入x" << endl;
        cout << "4. 删除第i个元素" << endl;
        cout << "5. 查找元素" << endl;
        cout << "6. 查找并输出元素" << endl;
        cout << "7. 输出全部元素" << endl;
        cout << "0. 退出" << endl;
        cout << "" << endl;
        cout << "请输入操作序号：";
        cin >> choice;

        if (!cin)
        {
            cout << "输入非法！请输入数字0-7\n";//健壮性 防止非法输入
            cin.clear();
            cin.ignore(1024, '\n');
            system("pause");
            continue;
        }

        switch (choice)
        {
            case 1:
                Initlist(L);
                cout << "链表初始化完成！" << endl;
                break;
            case 2:
                Createlist(L);
                Printlist(L); // 创建后自动打印
                break;
            case 3:
                cout << "请输入插入位置i、插入数值x：";
                cin >> i >> x;
                Listinsert(L, i, x);
                Printlist(L); // 插入后自动打印
                break;
            case 4:
                cout << "请输入要删除的位序i：";
                cin >> i;
                Listdelete(L, i, e);
                Printlist(L); // 删除后自动打印
                break;
            case 5:
                cout << "请输入要查找的元素值：";
                cin >> target;
                pos = Locateelem(L, target);
                if (pos == 0)
                    cout << "链表中不存在该元素！" << endl;
                else
                    cout << "元素" << target << "位于第" << pos << "位" << endl;
                break;
            case 6:
                cout << "请输入要查询的位置i：";
                cin >> i;
                Getelem(L, i);
                break;
            case 7:
                Printlist(L);
                break;
            case 0:
                cout << "程序结束！" << endl;
                return 0;
            default:
                cout << "输入序号超出范围！" << endl;
                break;
        }
    }
    return 0;//这句似乎没必要
}

Status Initlist(Linklist &L)
{
    L = new LNode;
    if(!L)
    {
        return ERROR;
    }
    L -> next = NULL;
    return OK;
}

Status Createlist(Linklist &L)
{
    if(!L)
    {
        cout << "未初始化链表！";
        return ERROR;
    }
    int n;
    while(true)
    {
        cout << "请输入链表长度：";
        cin >> n;
        if(!n)
        {
            cout << "请输入合法的值！";
            cin.clear();
            cin.ignore(1024,'\n');
            continue;
        }
        if(n>0)
        {
            break;
        }
        cout << "请输入正整数！";
    }

    LNode *r = L;
    Elemtype num;
    cout << "请依次输入" << n << "个正整数";
    for(int i=0;i<n;i++)
    {
        while(true)
        {
            cin >> num;
            if(!cin)
            {
                cout << "输入非法！请重试！";
                cin.clear();
                cin.ignore(1024,'\n');
                continue;
            }
            if (num>0)
            {
                break;
            }
            cout << "请输入正整数！:";
        }
        LNode *p = new LNode;
        p -> data = num;
        p -> next = NULL;
        r -> next = p;
        r = p;
    }
    cout << "初始化完成！";
    return OK;
}

Status Listinsert(Linklist &L,int i,Elemtype x)
{
    if(!L)
    {
        cout << "未初始化！";
        return ERROR;
    }

    LNode *p = L;
    int j = 0;
    while(p!=NULL && j<i-1)
    {
        p = p -> next;
        j++;
    }
    if (!p || j>i-1)
    {
        cout << "插入位置不合法！";
        return ERROR;
    }

    LNode *s = new LNode;
    s -> data = x;
    s -> next = p -> next;
    p -> next = s;

    cout << "已将" << x << "插入到" << i << "之前" << endl;
    return OK;
}

Status Listdelete(Linklist &L,int i,Elemtype &e)
{
    if(!L)
    {
        cout << "未初始化！";
        return ERROR;
    }
    LNode *p = L;
    int j = 0;

    while(p -> next != NULL && j < i-1)
    {
        p = p -> next;
        j++;
    }

    if (!(p -> next) || j > i-1)
    {
        cout << "删除的位置不合法！";
        return ERROR;
    }

    LNode *d = p -> next;
    e = d -> data;
    p -> next = d -> next;
    delete d;

    cout << "已删除，删除的数据为：" << e;
    return OK;
}

Status Locateelem(Linklist L,Elemtype e)
{
    if(!L)
    {
        cout << "未初始化！";
        return ERROR;
    }
    LNode *p = L -> next;
    int index = 1;
    while(p!=NULL)
    {
        if(p -> data == e)
        {
            return index;
        }
        p = p -> next;
        index++;
    }
    return ERROR;
}

Status Getelem(Linklist L,int i)
{
    if(!L)
    {
        cout << "未初始化！";
        return ERROR;
    }
    LNode *p = L -> next;
    int j = 1;

    while(p != NULL && j < i)
    {
        p = p -> next;
        j++;
    }
    if(!p)
    {
        cout << "此位置不存在！";
        return ERROR;
    }
    cout << "链表的第" << i << "个元素为：" << p -> data << endl;
    return OK;
}

Status Printlist(Linklist L)
{
    if(!L)
    {
        cout << "未初始化！";
        return ERROR;
    }
    LNode *p = L -> next;
    if(p == NULL)
    {
        cout << "链表为空！";
        return ERROR;
    }
    cout << "所有元素:";
    while(p != NULL)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << '\n';
    return OK;
}