#include <iostream>
using namespace std;
#include "map2.h"
int main(){
	map test = map(6);
	test.dfs();
	test.toposort();
	return 0;
}