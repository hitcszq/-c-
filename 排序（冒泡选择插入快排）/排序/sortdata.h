#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#define maxsize 100000
class sre{
public:
	struct records{
		int key;
	};
	records A[maxsize];
	int num;
public:
	sre(){
		cin >> num;
		srand(time(NULL));
		for (int i = 0; i < num; i++)
		{
			A[i].key = rand();
		}
	}
	void bubblesort(){
		for (int i = 0; i < num; i++){
			for (int j = num - 1; j >= i + 1; j--)
			{
				if (A[j].key < A[j - 1].key)
				{
					swap(A[j], A[j - 1]);
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			cout << A[i].key << endl;
		}
	}
	void insertsort(){
		A[0].key = -32768;
		int j;
		for (int i = 1; i < num; i++){
			j = i;
			while (A[j].key < A[j - 1].key)
			{
				swap(A[j], A[j - 1]);
				j--;
			}
		}
		for (int i = 1; i < num; i++)
		{
			cout << A[i].key << endl;
		}
	}
	void quicksort(int i, int j)
	{
		int pivot;
		int pivotindex;
		int k;
		pivotindex = findpivot(i, j);
		if (pivotindex != 0)
		{
			pivot = A[pivotindex].key;
			k = partition(i, j, pivot);
			quicksort(i, k - 1);
			quicksort(k, j);
		}

	}
	int findpivot(int i, int j)
	{
		int firstkey = A[i].key;
		int k;
		for (k = i + 1; k <= j; k++)
		{
			if (A[k].key > firstkey)
				return k;
			else if (A[k].key < firstkey)
				return i;
		}
		return 0;
	}
	int partition(int i, int j, int pivot)
	{
		int l, r;
		l = i; r = j;
		do{
			swap(A[l], A[r]);
			while (A[l].key < pivot)
				l++;
			while (A[r].key >= pivot)
				r--;
		} while (l <= r);
		return l;
	}
	void selectsort(){
		int select;
		for (int i = 0; i < num; i++)
		{
			select = i;
			for (int j = i+1; j < num; j++)
			{
				if (A[j].key < A[select].key)
					select = j;
			}
			swap(A[select], A[i]);
		}
		for (int i = 0; i < num; i++)
		{ 
			cout << A[i].key<<endl;
		}
	}
};