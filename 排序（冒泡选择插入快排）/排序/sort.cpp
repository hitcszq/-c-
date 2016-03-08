
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#define maxsize 100000
#include "sortdata.h"
int main(){
	sre test1 = sre();
	/*test1.quicksort(1,test1.num-1);
	for (int i = 1; i < test1.num; i++)
	{
		cout << test1.A[i].key << endl;
	}*/
	test1.selectsort();
	return 0;
}