#include "SinglyList.h"
template <class T>
class SortedSinglyList:public SinglyList<T>
{
private:
	bool asc;//����Ϊ��
public:
	SortedSinglyList(bool asc = true);
	SortedSinglyList(T values[], int n, bool asr = true);
	SortedSinglyList(SinglyList<T> &list, bool asr = true);

	void set(int i, T x);//��֧�ָ���������׳��쳣�����Ǹ��෽��
	Node<T>* insert(T x);//����
	//id insertUnrepeatable(T x);//����
	Node<T> *search(T key);//����
	void removeFirst(T key);//ɾ���״γ��ֵĹؼ���ΪKey��Ԫ�صĽڵ㣬����������������Ȼ����
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
	throw logic_error("�����ݽṹ��֧�ִ˲���");
}
template <class T>
Node<T>* SortedSinglyList<T>::insert(T x)//���ǻ���insert(int i,T x),insert(T x),���������,��ס��������T������>=,<=�����
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