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
	cout << "������Ҫɢ�е����ݼ�ֵ" << endl;
	while (n != -1)
	{
		cin >> n;
		records te;
		te.key = n;
		if (n != -1)
		test.insert(te);
	}
	cout << "������Ҫɾ�������ݼ�ֵ" << endl;
	cin >> h;
	test.deletel(h);
	cout << "������Ҫ���ҵ����ݼ�ֵ" << endl;
	cin >> m;
	cellptr wa = test.search(m);
	output(wa);

}