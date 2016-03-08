#include <iostream>
#include <stack>
using namespace std;
#include <time.h>
#include <stdlib.h>
int main(){
	const int max = 100;
	int visited[max];
	int lost[max][max];
	int load[max];
	int n,i,j,m,k,l,s;
	int flag = 0;
	int count= 0;
	cout << "输入迷宫的节点数";
	cin >> n;
	cin >> l >> s;
	srand(time(NULL));
	for (int i = 0; i < n; i++){
		visited[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			lost[i][j] = rand() % 2;
			lost[j][i] = rand() % 2;
			
		}
	}
	for (i = 0; i < n; i++){
		lost[i][i] = 0;
	}
	stack<int> ti;
	ti.push(l);
	visited[l] = 1;
	while (!ti.empty()){
		int find = 0;
		m=ti.top();
		for (k = 0; k < n; k++)
		{
			if (lost[m][k] == 1 && k == s)
			{
				ti.push(k);
				flag = 1;
				find = 1;
				break;
			}
			if (lost[m][k] == 1&&visited[k]==0)
			{
				ti.push(k);
				find = 1;
				visited[k] = 1;
				break;
			}
		}
		if (find == 0)
		{
			ti.pop();
		}
		if (flag == 1)
			break;
	}
	if (flag == 0)
		printf("迷宫中的这两点没有可到达路径");
	if (flag == 1)
	while (!ti.empty())
	{
		load[count] = ti.top();
		ti.pop();
		count++;
	}
	for (k = 0; k <count ; k++)
	{
		cout << load[k];
	}
}
