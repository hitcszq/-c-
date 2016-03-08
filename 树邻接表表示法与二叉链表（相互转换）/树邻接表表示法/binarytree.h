#ifndef _BINARYTREE_H
#define _BINARYTREE_H
#include <iostream>
using namespace std;
#include "tree.h"
template <class T>
class Node{
public:
	T data;
	Node<T> *leftchild;
	Node<T> *rightchild;
	Node(Node<T> *leftchild = NULL, Node<T> *rightchild = NULL){

	}
	Node( T xdata){
		data = xdata;
		leftchild = NULL;
		rightchild = NULL;
	}
	void visit(){
		cout << data  <<" ";
	}//ABC##DE#G##F###
};
template<class T>
class binarytree{
public:
	Node<T>*root;
	void preorder(Node <T>* nd);
	void inorder(Node <T>* nd);
	void afterorder(Node<T>* nd);
	void createtree(Node<T>* &nd);
	void translate(tree<T> *&nd);
	void translatetrees(tree<T> *nd[],int n);
};
template <class T>
void binarytree<T>::createtree(Node<T>* &nd)
{
	nd = new Node<T>;
	cin >> nd->data;
	if (nd->data != 0)
	{
		createtree(nd->leftchild);
		createtree(nd->rightchild);
	}
}
template <class T>
void binarytree<T>::preorder(Node <T>* nd){
	if (nd !=NULL){
		nd->visit();
		preorder(nd->leftchild);
		preorder(nd->rightchild);
	}
}
template <class T>
void binarytree<T>::inorder(Node<T> *nd)
{
	if (nd!= NULL){
		inorder(nd->leftchild);
		nd->visit();
		inorder(nd->rightchild);
	}
}
template <class T>
void binarytree<T>::afterorder(Node<T>*nd)
{
	if (nd!=NULL){
		afterorder(nd->leftchild);
		afterorder(nd->rightchild);
		nd->visit();
	}
}
template <class T>
void binarytree<T>::translate(tree<T>*& nd)
{
	Node<T>* trans[max];
	int visited[max];
	for (int i = 1; i <= nd->num; i++)
	{
		visited[i] = 0;
	}
	//Node<T>* pbr, prr;
	node<T>* ptr;
	node<T>* pb;
	/*for (int i = 0; i < max; i++)
	{
	if (nd->head[i] == NULL)
	{
	trans[i] = NULL;
	}
	trans[i]->data = nd->head[i]->element;
	ptr = nd->head[i];
	while (ptr != NULL&&ptr->next != NULL)
	{
	pbr = trans[i];
	prr = new Node<T>();
	prr->data = prr->element;
	pbr->next = prr;
	ptr = ptr->next;
	prr = prr->next;
	pbr = pbr->next;
	}
	}*/
	Node<T>* point;
	Node<T>* pointlemoch;
	Node<T>* pointrimobr;
	Node<T>* pointrimobrb;
	/*for (int i = 1; i < max&&trans[i]!= NULL; i++)
	{
	point = trans[i];
	pointlemoch = trans[i]->next;
	point->leftchild = pointlemoch;
	if (pointlemoch != NULL)
	{
	pointrimobr = pointlemoch->next;
	point->rightchild = pointrimobr;
	}
	while (pointrimobr != NULL)
	{
	pointrimobrb = pointrimobr;
	pointrimobr = pointrimobr->next;
	pointrimobr = pointrimobrb->next;
	}
	}*/
	for (int i = 1; i <= nd->num; i++){
		if (visited[i] == 0)
		{
			point = new Node<T>(nd->head[i]->element); trans[i] = point; visited[i] = 1;
			ptr = nd->head[i]->next;
			if (ptr->element != 0)
			{
				pointlemoch = new Node<T>(ptr->element);
				visited[ptr->element] = 1;
				trans[ptr->element] = pointlemoch;
				point->leftchild = pointlemoch;
				pointrimobrb = pointlemoch;
				while (ptr->next != 0)
				{
					pb = ptr->next;
					pointrimobr = new Node<T>(pb->element);
					 visited[pb->element] = 1;
					pointrimobrb->rightchild = pointrimobr;
					trans[pb->element] = pointrimobr;
					ptr = ptr->next;
					pointrimobrb = pointrimobrb->rightchild;
				}
			}
		}
		else
		{
			if (nd->head[i]->next != NULL)
			{
				point = trans[i];
				ptr = nd->head[i]->next;
				pointlemoch = new Node<T>(ptr->element); visited[ptr->element] = 1;
				trans[i]->leftchild = pointlemoch;
				trans[ptr->element] = pointlemoch;

				while (ptr->next != NULL)
				{
					pb = ptr->next;
					pointrimobr = new Node<T>(pb->element);
					visited[pb->element] = 1;
					trans[ptr->element]->rightchild = pointrimobr;
					trans[pb->element] = pointrimobr;
					ptr = ptr->next;
				}
			}
		}
	}
	root = trans[nd->top];
}
template <class T>
void binarytree<T>::translatetrees(tree<T> *nd[],int n)
{
	int i = 1;
	tree<T> *point;
	binarytree<T> *ptr=new binarytree();
	Node<T> *pb = new Node<T>();
	//binarytree<T> *pt;
	this->translate(nd[0]);
	//pt = this;
	pb = this->root;
	while (i<2)
	{
		point = nd[i];
		ptr->translate(nd[i]);
		pb->rightchild = ptr->root;
		ptr->root = ptr->root->rightchild;
		pb = pb->rightchild;
		i++;
	}
}
#endif