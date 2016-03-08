#include <iostream>
#include "sparsematrix.h"
using  namespace std;
int main(){
	sparsematrix<int> ma; sparsematrix<int>  mb;
	cin >> ma;
	ma.transpose(mb);
	cout << mb;
	return 0;
}