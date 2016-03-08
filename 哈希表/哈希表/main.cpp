#include <iostream>
using namespace std;
#include "hash.h"
struct records{
	int key;
};
int main(){
	HashTable<records, int> test = HashTable<records, int>();
	int n = 1;
	int m=1;
	cout << "输入要散列的键值" << endl;
	while (n != -1)
	{
		cin >> n;
		if (n != -1)
		{
			records miao;
			miao.key = n;
			test.Insert(miao);
		}
	}
	cout << "输入要查询的键值" << endl;
	while (m != -1)
	{
		cin >> m;
		if (m != -1)
		{
			records miao;
			if (test.Search(m, miao))
				cout << miao.key<<endl;
			else
				cout << "not found" << endl;
		}
	}
}