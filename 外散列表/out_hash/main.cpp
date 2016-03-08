#include <iostream>
using namespace std;
#include "outhash.h"
void output(cellptr pt){
	if (pt == NULL)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << pt->data.key << endl;
	}
}
int main(){
	int n,m,h;
	n = 998;
	outhash test = outhash();
	cout << "输入需要散列的数据键值" << endl;
	while (n != -1)
	{
		cin >> n;
		records te;
		te.key = n;
		if (n != -1)
		test.insert(te);
	}
	cout << "输入需要删除的数据键值" << endl;
	cin >> h;
	test.deletel(h);
	cout << "输入需要查找的数据键值" << endl;
	cin >> m;
	cellptr wa = test.search(m);
	output(wa);

}