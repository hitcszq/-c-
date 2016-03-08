#include <iostream>
#include "dataclass.h"
#include "Node.h"
#include "SortedSinglyList.h"
//typedef SortedSinglyList <dataclass> liPolynomial;
template <class anytype>
char compareexp(anytype a, anytype b)
{
	if (a < b)
		return '<';
	if (a>b)
		return '>';
	if (a == b)
		return '=';
}

class Polynomial :public SortedSinglyList<dataclass>
{ 
public:
	Polynomial();
	Polynomial(dataclass terms[], int n)£ºliPolynomial(terms,n);

	void print();
	void operator+=(Polynomial &poly);
	Polynomial &operator+(Polynomial &poly);
	Polynomial &operator*(Polynomial &poly);
	Polynomial &operator-(Polynomial &poly);
	Node<dataclass> &Attach(dataclass term, Node<dataclass> &d);

};

Node<dataclass> &Attach(const dataclass *term, Node<dataclass> &d)
{
	Node<dataclass>* x = new Node<dataclass>();
	x->data->exp = term->exp;
	x->data->coef = term->coef;
	d->next = x;
	return *x;
}

Polynomial Polynomial::operator +(Polynomial &poly)
{
	Node<dataclass>* p, q, c, d;
	int x;
	p = this->head->next;
	q = poly.head->next;
	d = c;
	while ((p != NULL) && (q != NULL))
		switch (compareexp(p->data->exp,q->data->exp)
	{
		case '=':
			p->data->coef = p->data->coef + q->data->coef;//
			if (x != 0)
				d = Attach(p->data, d);
			p = p->next; q = q->next;
			break;
		case'>':
			d = Attach(p->data, c);
			p = p->next;
			break;
		case'<':
			d = Attach(q->data, c);
			q = q->next;
	}
	while (p != NULL){
		d = Attach(p->data, d);
		p = p->next;
	}
	while (q != NULL)
	{
		d = Attach(q->data, d);
		q = q->next;
	}
	d->next = NULL;
	return *c;

}

