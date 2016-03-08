#include <iostream>
#include "BST.h"
using namespace std;
int main()
{
	
	int miao; 
	binarysearchtree<int>* ptr = new binarysearchtree<int>();
	cout << "插入节点,-1表示结束"<<endl;
	cin >> miao;
	while (miao != -1)
	{
		ptr->insert(miao);
		cin >> miao;
	}
	cout << "最大最小值是" << endl;
	cout << ptr->findmax()<< " " << ptr->findmin()<<endl;
	ptr->printtree();
	return 0;
}