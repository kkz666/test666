#include<iostream>
#include<array>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<stack>
#include"qgforwardlist.h"
#include"qglist.h"
using namespace std;
void fx(QGForwardList::ElemType& e) {
    e = e + 3;
}
void fy(QGList::ElemType& e) {
    e = e + 3;
}
int main() {
    char ch;
    QGForwardList L;
    cout << endl<<"b:返回第一个引用" << endl;
    cout << "c:返回最后一个引用" << endl;
    cout << "d:在链表第一个元素前添加元素" << endl;
    cout << "e:删除链表第一个元素" << endl;
    cout << "f:在链表最后一个元素后添加元素" << endl;
    cout << "g:删除链表最后一个元素" << endl;
    cout << "h:在链表的第index + 1个元素前插入元素e" << endl;
    cout << "i:删除任意位置元素" << endl;
    cout << "j:清空链表" << endl;
    cout << "k:查找元素是否存在" << endl;
    cout << "l:返回链表中元素的数量" << endl;
    cout << "n:遍历链表, 对每个元素调用visit指向的函数" << endl;
    cout << "m:反转链表，1234反转后变成4321" << endl;
    cout << "p:偶节点反转，1234反转后变成2143" << endl;
    cout << "q:返回中间节点" << endl;
    cout << "T:退出" << endl;
    cin >> ch;
    while (ch) {
        system("cls");
        if (ch == 'T' || ch == 't')return 0;
        cout << "b:返回第一个引用" << endl;
        cout << "c:返回最后一个引用" << endl;
        cout << "d:在链表第一个元素前添加元素" << endl;
        cout << "e:删除链表第一个元素" << endl;
        cout << "f:在链表最后一个元素后添加元素" << endl;
        cout << "g:删除链表最后一个元素" << endl;
        cout << "h:在链表的第index + 1个元素前插入元素e" << endl;
        cout << "i:删除任意位置元素" << endl;
        cout << "j:清空链表" << endl;
        cout << "k:查找元素是否存在" << endl;
        cout << "l:返回链表中元素的数量" << endl;
        cout << "n:遍历链表, 对每个元素调用visit指向的函数" << endl;
        cout << "m:反转链表，1234反转后变成4321" << endl;
        cout << "p:偶节点反转，1234反转后变成2143" << endl;
        cout << "q:返回中间节点" << endl;
        cout << "T:退出" << endl;
        switch (ch) {
        case'b':cout << L.front(); cout << endl << "输T结束"; cin >> ch; break;
        case'c':cout << L.back(); cout << endl << "输T结束"; cin >> ch; break;
        case'd':QGForwardList::ElemType a; cout << "输入要加的数"; cin >> a; L.push_front(a);
            cout << endl << "输T结束"; cin >> ch; break;
        case'e':L.pop_front(); cout << endl << "输T结束"; cin >> ch; break;
        case'f':QGForwardList::ElemType b; cout << "输入要加的数"; cin >> b; L.push_back(b);
            cout << endl << "输T结束"; cin >> ch; break;
        case'g':L.pop_back(); cout << endl << "输T结束"; cin >> ch; break;
        case 'h':unsigned int c; cout << endl << "输入插入的位置c"; cin >> c;
            QGForwardList::ElemType d; cout << "输入插入的数d"<<endl; cin >> d;
            L.insert(c, d); cout << endl << "输T结束"; cin >> ch; break;
        case'i': unsigned int e; cout << "输入删除位置e" << endl;
            cin >> e; L.erase(e); cout << endl << "输0结束"; cin >> ch; break;
        case'j':L.clear(); cout << endl << "输T结束"; cin >> ch; break;
        case'k':QGForwardList::ElemType f; cout << endl << "输入你要查找的数"<<endl; cin >> f; L.contain(f); cout << endl << "输T结束"; cin >> ch; break;
        case'l':cout << endl<<"链表中元素数量为"<< L.size(); cout << endl << "输T结束"; cin >> ch; break;
        case'n':cout << "不知道这个怎么玩写了个每项加3的";
            L.traverse(fx); cout << endl << "输T结束"; cin >> ch; break;
        case'm':L.reverse(); cout << endl << "输T结束"; cin >> ch; break;
        case'p':L.reverseEven(); cout << endl << "输T结束"; cin >> ch; break;
        case'q': ; cout << endl << "中间数为" <<L.middleElem();
            cout << endl << "输T结束"; cin >> ch; break;
        
        default:cin >> ch; break;
        }
    }
    return 0;
}