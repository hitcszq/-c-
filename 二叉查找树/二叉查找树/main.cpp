#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
	
	int miao; 
	binarysearchtree<int>* ptr = new binarysearchtree<int>();
	cout << "����ڵ�,-1��ʾ����"<<endl;
	cin >> miao;
	while (miao != -1)
	{
		ptr->insert(miao);
		cin >> miao;
	}
	cout << "�����Сֵ��" << endl;
	cout << ptr->findmax()<< " " << ptr->findmin()<<endl;
	ptr->printtree();
	return 0;
}