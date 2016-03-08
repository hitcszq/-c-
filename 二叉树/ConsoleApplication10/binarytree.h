#include <iostream>
using namespace std;
#include <queue>
template <class T>
class Node{
public:
	T data;
	Node<T> *leftchild;
	Node<T> *rightchild;
	Node(Node<T> *leftchild = NULL, Node<T> *rightchild = NULL){

	}

	void visit(){
		cout << data;
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
	void levelorder();
};
template <class T>
void binarytree<T>::createtree(Node<T>* &nd)
{
	nd = new Node<T>;
	cin >> nd->data;
	if (nd->data != '#')
	{
		createtree(nd->leftchild);
		createtree(nd->rightchild);
	}
}
template <class T>
void binarytree<T>::preorder(Node <T>* nd){
	if (nd->data != '#'){
		nd->visit();
		preorder(nd->leftchild);
		preorder(nd->rightchild);
	}
}
template <class T>
void binarytree<T>::inorder(Node<T> *nd)
{
	if (nd->data != '#'){
		inorder(nd->leftchild);
		nd->visit();
		inorder(nd->rightchild);
	}
}
template <class T>
void binarytree<T>::afterorder(Node<T>* nd)
{
	if (nd->data != '#'){
		afterorder(nd->leftchild);
		afterorder(nd->rightchild);
		nd->visit();
	}
}
template <class T>
void binarytree<T>::levelorder(){
	queue<Node<T>*> levelq;
	Node<T>* fro;
	levelq.push(root);
	while (!levelq.empty())
	{
		fro = levelq.front();
		fro->visit();
		levelq.pop();
		if (fro->leftchild->data!='#')
		levelq.push(fro->leftchild);
		if (fro->rightchild->data!= '#')
		levelq.push(fro->rightchild);
	}
}