#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void heapsort(vector<T> &a)
{
	for (int i = a.size() / 2; i >= 0; i--)
	{
		pushdown(a, i, a.size());
	}
	for (int j = a.size() - 1; j > 0; j--)
	{
		swap1(a[0], a[j]);
		pushdown(a, 0, j);
	}
}
int leftchild(int i)
{
	return 2 * i + 1;
}
template <typename T>
void pushdown(vector<T> &a,int i,int n)
{
	int child;
	T tem;
	for (tem = a[i]; leftchild(i) < n; i = child)
	{
		child = leftchild(i);
		if (child!= n - 1 && a[child] < a[child + 1])
			child++;
		if (tem < a[child])
			a[i] = a[child];
		else
			break;
	}
	a[i] = tem;
}
template <typename T>
void swap1(T& a, T& b)
{
	T te;
	te = a;
	a = b;
	b = te;
}
int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i<n; i ++)
	{
		cin >> vec[i];
	}
	heapsort(vec);
	for (int i = 0; i<n; i++)
	{
		cout<<vec[i]<<endl;
	}
	return 0;
}