#ifndef _TREE_H
#define _TREE_H
#include <iostream>
using namespace std;
#include "binarytree.h"
#define max 100
template <class T>
class node{
public:
	T element;
	node<T>* next;
};
template <class T>
class tree{
public:
	node<T>* head[max];
	int top;
	int num;
	void createtree();
	tree(){
		for (int i = 0; i < max; i++)
		{
			head[i] = NULL;
		}
		top = 1;
	}
};
template <class T>
void tree<T>::createtree(){
	   cin >> this->num;
	for (int i = 1; i <=this->num; i++){
			head[i] = new node<T>();
			head[i]->element = i;
			node<T> *pb = head[i];
			node<T>* pr;
			T data;
			cout << "请输入第" << i << "个节点的所有邻接点,0表示结束" << endl;
			cin >> data;
			while (data != 0)
			{
				pr = new node<T>();
				pr->element = data;
				pb->next = pr;
				pr = pr->next;
				pb = pb->next;
				cin >> data;
			}
	}
}
#endif