#include<iostream>
#include"qglist.h"
#include<new>
using namespace std;
QGList::QGList() {
	head = new Node;
	tail = new Node;
	head->next = tail;
	head->prior = nullptr;
	tail->prior = head;
	ElemType num;
	cout << endl << "输入" << endl;
	cin >> num;
	while (1) {
		tail->data = num;
		cout << "继续？Y/N" << endl;
		cin.clear();
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y') {
			cout << "输入" << endl;
			cin >> num;
			Node* temp = new Node;
			temp->next = nullptr;
			temp->prior = tail;
			tail->next = temp;
			tail = temp;
			tail->data = num;
		}
		else if (c == 'N' || c == 'n') {
			break;
		}
		else {
			cout << "bad enter " << endl;
			cin.clear();
			break;
		}
	}
	cout << "链表内容:" << endl;
	Node* T = head->next;
	while (T != nullptr) {
		cout << T->data << " ";
		T = T->next;
	}
}
QGList::~QGList() {
	Node* p1 = head->next;
	Node* p2;
	while (p1 != nullptr) {
		p2 = p1->next;
		delete p1;
		p1 = p2;
	}
	p1 = p2 = nullptr;
	cout << "指针释放";
}
QGList::ElemType& QGList::front() {
	return head->next->data;
}
QGList::ElemType& QGList::back() {
	Node* p = head->next;
	if (p != nullptr) {
		while (p->next != nullptr) {
			p = p->next;
		}
		return p->data;
	}
	else cout << "空链表返回-1";
	QGList::ElemType i = -1;
	return i;
}
bool QGList::push_front(ElemType& e) {
	if (Node* temp = new Node) {
		temp->next = nullptr;
		temp->data = e;
		temp->next = head->next->next;
		head->next->next->prior = temp;
		temp->prior = head;
		head->next = temp;
		return true;
	}
	else  return false;
}
bool QGList::pop_front() {
	Node* p = head->next;
	if (p) {
		head->next = p->next;
		delete p;
		return true;
	}
	return false;
}
bool QGList::push_back(ElemType& e) {
	Node* T = head->next;
	while (T->next) {
		T = T->next;
	}
	Node* N = new Node;
	N->next = nullptr;
	N->prior = T;
	T->next = N;
	N->data = e;
	return true;
}
bool QGList::insert(unsigned int index, ElemType& e) {
	int rec = 0;
	Node* p = head;
	while (p != nullptr && rec < index) {
		p = p->next;
		rec++;
	}
	if (p == nullptr)return false;
	if (Node* add = new Node) {
		add->data = e;
		add->next = p->next;
		add->prior = p;
		p->next->prior = add;
		p->next = add;
		return true;
	}
	else return true;
}
bool QGList::erase(unsigned int index) {
	int rec = 1;
	Node* f = head->next;
	Node* t = head;
	while (f != nullptr && rec < index) {
		f = f->next;
		t = t->next;
		rec++;
	}
	if (f == nullptr)return false;
	else {
		t->next = f->next;
		f->next->prior = t;
		delete f;
		return true;
	}
	return false;
}
bool QGList::clear() {
	Node* q = head->next;
	while (q) {
		q->data = 0;
		q = q->next;
	}
	return true;
}
bool QGList::contain(ElemType& e) {
	Node* p = head->next;
	int flag = 0;
	while (p != nullptr) {
		if (p->data == e) {
			cout << "链表里有" << e << endl;
			return true;
		}
		p = p->next;
	}
	cout << "链表里没" << e << endl;
	return false;
}
unsigned int  QGList::size() {
	unsigned int num = 0;
	Node* p = head->next;
	while (p != nullptr) {
		num++;
		p = p->next;
	}
	return num;
}
bool  QGList::traverse(void (*visit)(ElemType& e)) {
	Node* p = head->next;
	while (p != nullptr) {
		(*visit)(p->data);
		p = p->next;
	}
	return true;
}