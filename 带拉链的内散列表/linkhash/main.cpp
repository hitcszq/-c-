#include <iostream>
using namespace std;
#include "linkhash.h"
int main(){
	linkhash test = linkhash();
	int n = 1;
	int m = 1;
	while (n != -1)
	{
		cin >> n;
		if (n!=-1)
		{
			records miao;
			miao.key = n;
			miao.next = NULL;
			test.insert(miao);
		}
	}
	while (m != -1)
	{
		cin >> m;
		if (m != -1)
		{
			if (test.search(m))
				cout << "found" << endl;
			else
				cout << "not found" << endl;
		}
	}
}