

#include "SinglyList.h"
template <class T>
class stack :public SinglyList<T>{
	//stack():SinglyList();
public:
	T top();
	void pop();
	void push(T puda);
};
template <class T>
T stack<T>::top()
{
	return this->head->next->data;
}
template <class T>
void stack<T>::pop()
{
	Node<T> *pr = this->head->next;
	this->head->next = this->head->next->next;
}
template <class T>
void stack<T>::push(T puda)
{
	Node<T>* pr =new Node<T>(puda, this->head->next);
	this->head->next = pr;
}
