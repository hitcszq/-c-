#include <iostream>
using namespace std;
#include "binarytree.h"

int main(){
	//*tree<int>* test = new tree<int>();
	//test->createtree();
	//binarytree<int>* trtest = new binarytree<int>();
	binarytree<int>* trts = new binarytree<int>();
	//trtest->translate(test);
	//trtest->preorder(trtest->root);
	//cout << endl;
	//trtest->inorder(trtest->root);
	//cout << endl;
	//trtest->afterorder(trtest->root);
	//cout << endl;
	tree<int>* ts[2];
	ts[1]=new tree<int>();
	ts[0] = new tree<int>();
	ts[0]->createtree();
	ts[1]->createtree();
	trts->translatetrees(ts,2);
	trts->preorder(trts->root);
	return 0;
}