#include <iostream>//单链表含无数据的头结点，序号为-1；
#include "Node.h"
using namespace std;
template <class T>
class SinglyList{
public:
	Node<T> *head;
	SinglyList();
	SinglyList(T values[], int n);
	~SinglyList();

	bool empty();
	int count();
	T& get(int i);
	virtual void set(int i, T x);
	Node <T> *insert(int i; T x);
	Node <T> *insert(T x);
	T remove(int i);
	void removeAll();
	Node<T> *search(T key);
	//void insertUnrepeatable(T x);
	//void removeFirst(T key);
	bool operator==(SinglyList<T> &list);//重载==
	bool operator!=(SinglyList<T> &list);//重载！=
	SinglyList(SinglyList <T> &list);//拷贝构造函数（深拷贝）
	SinglyList<T> &operator=(SinglyList <T> &list);//重载赋值运算符
	void operator+=(SinglyList<T> &list);//重载+=，表示连接
};
template <class T>
SinglyList<T>::SinglyList()
{
	this->head = new Node<T>();
}
template <class T>
SinglyList<T>::SinglyList(T values[], int n)
{
	this->head = new Node<T>();
	Node<T> *rear = this->head;
	for (int i = 0; i < n; i++)
	{
		rear->next = new Node(values[i]);
		rear = rear->next;
	}
}
template <class T>
SinglyList<T>::~SinglyList()
{
	this->removeAll();
	delete this->head;
}
template <class T>
bool SinglyList<T>::empty()
{
	return this->head->next == NULL;
}
/*template <class T>
ostream &operator<< >> (ostream &out, SinglyList<T> &list)
{
out << "(";
for (Node <T> *p = list->head->next; p != NULL; p = p->next)
{
out << p->data;
if (p->next != NULL)
out << ",";
}
out << ")\n"
return out;
}*/
template <class T>
T& SinglyList<T>::get(int i)
{
	Node<T> *p = this->head->next;
	for (int j = 0; p != NULL&&j < i; j++)
		p = p->next;
	if (i >= 0 && p != NULL)
		return T->data;
	else
		throw out_of_range("参数超出指定范围");
}
template <class T>
Node<T>* SinglyList::insert(int i, T x)
{
	Node<T> *front = this->head;
	for (int j = 0; front->next != NULL&&j < i; j++)
		front = front->next;
	front->next = new Node<T>(x, front->next);
	return front->next;
}
template <class T>
T SinglyList<T>::remove(int i)
{
	Node<T>*front = this->head;
	for (int j = 0; front->next != NULL&&j < i; j++)
	{
		front = front->next;
	}
	if (i>0 && front - next != NULL)
	{
		Node <T>*q = front->next;
		T old = q->data;
		front->next = q->next;
		delete(q);
		return old;
	}
	throw out_of_range("参数i指定元素超出元素范围")
}
template <class T>
void SinglyList<T>::operator+=(SinglyList<T> &list)
{
	Node<T> *rear = this->head;
	while (rear->next != NULL)
	{
		rear = rear->next;
	}
	rear->next = list.head->next;
	list.head->next = NULL;
}
template <class T>
SinglyList<T> &operator=(SinglyList <T> &list)
{
	this->head = new Node<T>();
	Node<T> *rear = this->head;
	Node<T> *ptr = this->head->next;
	while (ptr != NULL)
	{
		rear->next = new Node(ptr->data);
		rear = rear->next;
		ptr = ptr->next;
	}
}
template <class T>
bool SinglyList<T>:: operator==(SinglyList<T> &list)
{
	Node<T> *ptr1 = this->head->next;
	Node<T> *ptr2 = list.head->next;
	int flag = 1;
	while (ptr1 != NULL&&ptr2 != NULL)
	{
		if (ptr1->data != ptr2->data)
		{
			flag = 0;
			break;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if ((ptr1 == NULL&&ptr2 != NULL || ptr2 == NULL&&ptr1 != NULL))
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
template <class T>
bool SinglyList<T>:: operator!=(SinglyList<T> &list)
{
	return (!this = list);
}
template <class T>
SinglyList<T>::SinglyList(SinglyList <T> &list)//拷贝构造函数（深拷贝）
{
	this = list;
}
template <class T> 
void SinglyList<T>::removeAll(){
	for (int i = 0; i<this->count(); i++)
	{
		this->remove(i);
	}
}
template <class T>
int  SinglyList<T>::count(){
	int count = 0;
	Node<T>* p = this->head->next;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}