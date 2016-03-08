#include "SinglyList.h"
template <class T>
class SortedSinglyList:public SinglyList<T>
{
private:
	bool asc;//升序为真
public:
	SortedSinglyList(bool asc = true);
	SortedSinglyList(T values[], int n, bool asr = true);
	SortedSinglyList(SinglyList<T> &list, bool asr = true);

	void set(int i, T x);//不支持该项操作，抛出异常，覆盖父类方法
	Node<T>* insert(T x);//覆盖
	//id insertUnrepeatable(T x);//覆盖
	Node<T> *search(T key);//覆盖
	void removeFirst(T key);//删除首次出现的关键字为Key的元素的节点，由于是排序单链表，显然覆盖
};
template <class T>
SortedSinglyList <T>::SortedSinglyList(bool asc)
{
	this->asc = asc;
}
template <class T>
SortedSinglyList <T>::SortedSinglyList(T values[], int n, bool asc)
{
	this->asc = asc;
	for (int i = 0; i < n; i++)
	{
		this->insert(values[i]);
	}
}
template <class T>
void SortedSinglyList<T>::set(int i, T x)
{
	throw logic_error("该数据结构不支持此操作");
}
template <class T>
Node<T>* SortedSinglyList<T>::insert(T x)//覆盖基类insert(int i,T x),insert(T x),覆盖虚基类,记住数据类型T需重载>=,<=运算符
{
	Node<T> *front = head; *p = head->next;
	while (p != NULL && (asc ? x >= p->data : x <= p->data))
	{
		front = p;
		p = p->next;
	}
	Node<T> *q = new Node(x, p);
	front->next = q;
	return q;
}
template <class T>
void SortedSinglyList<T>::removeFirst(T key)
{
	Node<T> *front = head, *p = head->next;
	while (p != NULL && (asc ? key > p->data:key < p->data))
	{
		front = p;
		p = p->next;
	}
	if (p != NULL&&key == p->data)
	{
		front->next = p->next;
		delete(p);
	}
}