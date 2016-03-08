#include <iostream>
using namespace std;
#include "binarytree.h"
int main(){
	binarytree<char>* bt = new binarytree<char>();
	bt->createtree(bt->root);
	
	bt->preorder(bt->root);
	cout << endl;
	bt->inorder(bt->root);
	cout << endl;
	bt->afterorder(bt->root);
	cout << endl;
	bt->levelorder();
	cout << endl;
	return 0;
}