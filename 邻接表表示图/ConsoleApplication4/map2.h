#include <iostream>
using namespace std;
#include <queue>
#define max 100
class map{
public:
	struct edgenode{
		int cost;
		int vertex;
		edgenode *next;
	};
	typedef edgenode* pointer;
	struct graph{
		pointer adj[max];
	};
	graph thegraph;
	int indegree[max];
	int vernum;
	map(int k){
		vernum = k;
		for (int i = 1; i <=k; i++)
		{
			thegraph.adj[i] = NULL;
			indegree[i] = 0;
		}
		for (int i = 1; i <= k; i++)
		{
			int flag = 1;
			cout << "请输入邻接与" << i << "点的点,并输入该边权值,-1结束"<<endl;
			while (flag == 1)
			{
				edgenode* newedge=new edgenode;
				cin >> newedge->vertex >> newedge->cost;
				if (newedge->vertex != -1)
				{
					newedge->next = thegraph.adj[i];
					thegraph.adj[i] = newedge;
				}
				else
					flag = 0;
			}
		}
		for (int i = 1; i <= k; i++)
		{
			pointer pr = thegraph.adj[i];
			while (pr != NULL)
			{
				indegree[pr->vertex]++;
				pr = pr->next;
			}
		}
	}
	void dfs(){
		int visited[max];
		for (int i = 0; i < max; i++)
		{
			visited[i] = 0;
		}
		dfsout(1, visited);//默认从1开始遍历；
	}
	void dfsout(int i, int visited[]){
		pointer ptr = thegraph.adj[i];
		cout << i << " ";
		visited[i] = 1;
		while (ptr!= NULL){
			if (visited[ptr->vertex] == 0)
				dfsout(ptr->vertex, visited);
			ptr = ptr->next;
		}
	}
	void toposort(){
		queue<int> Q;
		int v, w;
		int count=0;
		for (int i = 1; i <= vernum; i++)
		{
			if (indegree[i] == 0)
			{
				Q.push(i);
			}
		}
		while (!Q.empty())
		{
			v = Q.front();
			Q.pop();
			cout << v;
			count++;
			pointer pb = thegraph.adj[v];
			while (pb != NULL)
			{
				indegree[pb->vertex]--;
				if (indegree[pb->vertex] == 0)
					Q.push(pb->vertex);
				pb = pb->next;
			}
		}
		if (count < vernum)
			cout << "存在环路，无拓扑序列"<<endl;
	}
};