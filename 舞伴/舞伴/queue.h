
#include "SinglyList.h"
template <class T>
class queue :public SinglyList<T>{
	//queue():SinglyList();
public:
	T front();
	void pop();
	void push(T puda);                                           
};
template <class T>
T queue<T>::front()
{
	return this->head->next->data;
}
template <class T>
void queue<T>::pop()
{
	Node<T> *pr = this->head->next;
	this->head->next = this->head->next->next;
}
template <class T>
void queue<T>::push(T puda)
{
	Node<T>* pr = new Node<T>(puda, this->head->next);
	this->head->next = pr;
}
