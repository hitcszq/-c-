#include <iostream>
using namespace std;
#include "map.h"
int main(){
	map test = map(5);
	test.dijkstra(1);
	test.floyd();
	test.kruskal();
	return 0;
}