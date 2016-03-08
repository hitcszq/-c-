#include <iostream>
using namespace std;
#include "map.h"
int main(){
	map test = map(5);
	test.dfs(1);
	test.bfs(1);
	test.prim();
	return 0;
}