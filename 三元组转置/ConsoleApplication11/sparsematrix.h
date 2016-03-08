#include <iostream>
using namespace std;
template <class T>
class term{
public:
	int row, col;
	T value;
};
template <class T>
class sparsematrix{
	friend ostream& operator<< (ostream &out,sparsematrix<T>& x)
	{
		out << "rows=" << x.rows << "columns =" << x.cols << endl;
		out << "非零元素个数为" << x.terms << endl;
		for (int i = 0; i < x.terms; i++)
			out << "a(" << x.a[i].row << ","<<x.a[i].col<<")="<< x.a[i].value << endl;
		return out;
	}
	friend istream& operator>> (istream &in,  sparsematrix<T>& x)
	{
		cout << "输入行数列数，非零元素数";
		in >> x.rows >> x.cols >> x.terms;
		for (int i = 0; i < x.terms; i++)
		{
			in >> x.a[i].row >> x.a[i].col >> x.a[i].value;
		}
		return in;
	}
public:
	sparsematrix( int maxterms = 100 );
	~sparsematrix(){ delete []a; }
	void transpose(sparsematrix<T> &b);
	term <T>*a;
	int rows, cols;
	int terms;
	int maxterms;
};
/*template <class T>
ostream& operator<< <>(ostream &out, const sparsematrix<T>& x)
{
	out << "rows=" << x.rows << "columns =" << x.cols << endl;
	out << "非零元素个数为" << x.terms << endl;
	for (int i = 0; i < x.terms; i++)
		out << "a(" << x.a[i].row << "," << x.a[i].value << endl;
	return out;
}
template <class T>
istream& operator>> <>(istream &in, sparsematrix<T> x)
{
	cout << "输入行号列号，非零元素";
	in >> x.rows >> x.cols >> x.terms;
	if (x.terms>x.maxterms)
		throw NoMem();
	for (int i = 0; i < terms; i++)
	{
		in >> x.a[i].row >> a[j].col >> x.a[i].value;
	}
	return in;
}*/
template <class T>
sparsematrix<T>::sparsematrix(int maxterms)
{
	maxterms = maxterms;
	a = new term<T>[maxterms];
	terms = rows = cols = 0;
}
template <class T>
void sparsematrix<T>::transpose(sparsematrix <T> & b)
{
	b.cols = rows;
	b.rows = cols;
	b.terms = terms;
	int *colsize, *rownext;
	colsize = new int[cols + 1];
	rownext = new int[rows + 1];
	for (int i = 1; i <=cols; i++)
	{
		colsize[i] = 0;
	}
	for (int i = 0; i < terms; i++)
	{
		colsize[a[i].col]++;
	}
	rownext[1] = 0;
	for (int i = 2; i <= cols; i++)
	{
		rownext[i] = rownext[i - 1] + colsize[i - 1];
	}
	for (int i = 0; i < terms; i++)
	{
		int j = rownext[a[i].col]++;
		b.a[j].row = a[i].col;
		b.a[j].col = a[i].row;
		b.a[j].value = a[i].value;
	}
}