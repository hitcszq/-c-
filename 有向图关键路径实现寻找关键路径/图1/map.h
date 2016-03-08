#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <ctime>
#include <stdlib.h>
#include "mfset.h"
#define max 100
class map{
private:
	int vernum;
	int adjvertex[max][max];//问题二维向量如何构造
	int indegree[max];
	int outdegree[max];
public:
	struct edge{
		int i;
		int j;
		int cost;
	};
	map(int thenum)//thenum为图的顶点数
	{
		vernum = thenum;
		for (int i = 1; i <= thenum; i++)
		{
			adjvertex[i][i] = -1;
			indegree[i] = 0;
			outdegree[i] = 0;
			for (int j =   1; j <= thenum; j++)
			{
				if (j != i)
				{
					cout << "please input distance from" << i << "to" << j << endl;
					cin >> adjvertex[i][j];
				}
			}
		}
		for (int i = 1; i <= vernum; i++)
		{
			for (int j = 1; j <= vernum; j++)
			{
				if (adjvertex[j][i] != -1)
					indegree[i]++;
				if (adjvertex[i][j] != -1)
					outdegree[i]++;
			}
		}
	}
	void dfs(int k){
		int visited[max];
		for (int i = 1; i <= vernum; i++)
		{
			visited[i] = 0;
		}
		visited[k] = 1;
		cout << k << " ";
		DFSout(k, visited);
		cout << endl;
	}
	void DFSout(int i,int visited[]){//深度搜索并输出
	
		for (int j = 1; j <=vernum; j++)
		{
			if (adjvertex[i][j] != -1&&visited[j]==0)
			{
				cout << j<<" ";
				visited[j] = 1;
				DFSout(j,visited);
			}
		}
	}
	bool dfsjudge(){//深度搜索判断图是否连通
		int i;
		int visited[max];
		for (int i = 1; i <= vernum; i++)
		{
			visited[i] = 0;
		}
		stack<int> dfsver,dfsrec;
		srand(time(NULL));
		i = rand() % vernum + 1;
		dfsver.push(i);
		visited[i] = 1;
		dfsrec.push(i);
		while (!dfsver.empty())
		{
			int ver;
			ver = dfsver.top();
			dfsver.pop();
			for (int j = 1; j <= vernum; j++)
			{
				if (adjvertex[j][ver] != -1&&visited[j]==0)
				{
					dfsver.push(j);
					dfsrec.push(j);
					visited[j] = 1;
					break;
				}
			}
		}
		int nu=0;//该连通分量的顶点数
		while (!dfsrec.empty())
		{
			dfsrec.pop();
			nu++;
		}
		return (nu == vernum);
	}
	void bfs(int k){
		int visited[max];
		for (int i = 1; i <= vernum; i++)
		{
			visited[i] = 0;
		}
		BFSout(k, visited);
	}
	void BFSout(int i,int visited[]){//广度搜索并输出
		queue<int> verque;
		verque.push(i);
		visited[i] = 1;
		while (!verque.empty())
		{
			int ver;
			ver = verque.front();
			cout << ver << ' ';
			verque.pop();
			for (int j = 1; j <=vernum; j++)
			{
				if (adjvertex[ver][j] != -1&&visited[j]==0)
				{
					verque.push(j);
					visited[j] = 1;
				}
			}
		}
	}
	void prim(){

		/*if (!dfsjudge())
		{
			cout << "图不连通，最小生成树不存在" << endl;
		}
		else
		{*/
		
			int tvernum = vernum - 1;
			edge memedge[max*max];
			bool mem[max];
			int closet[max];
			for (int i = 1; i <= vernum; i++)
			{
				mem[i] = false;
			}
			int i; 
			srand(time(NULL));
			i = rand() % vernum + 1;
			int distance[max];
			mem[i] = true;
			for (int k = 1; k <= vernum; k++)
			{
				closet[k] = i;
			}
			for (int j = 1; j <=vernum; j++)
			{
				if (j != i)
				{
					distance[j] = adjvertex[i][j];
				}
				else
					distance[j] = -1;
			}
			int flag = 0;//标志找到初始最小边
			int minedge;
			int remem;//记住新加入顶点
			int k = 0;
			while (tvernum >= 1)
			{
				for (int j = 1; j <= vernum; j++)//找出距离树集最小的边
				{
					if (!mem[j] && flag == 0&&distance[j]>0){ minedge = distance[j]; remem = j; flag = 1; }
					else if (!mem[j]){
						if (distance[j] < minedge&&distance[j]>0)
						{
							minedge = distance[j];
							remem = j;
						}
					}
				}
				flag=0;
				mem[remem] = true;//加入树集
				memedge[k].i = closet[remem];
				memedge[k].j = remem;
				k++;//记录边的数目
				//更新closet数组
				for (int j = 1; j <= vernum; j++)
				{
					if (mem[j] == false)
					{
						if ((distance[j] > adjvertex[remem][j]&&adjvertex[remem][j]>0)||distance[j]<0)//包含了边为负的情况,若定义正无穷为不可到达，则省去一个判断
						{
							closet[j] = remem;
							distance[j] = adjvertex[remem][j];
						}
					}
				}
				tvernum--;
			}
			cout << "输出最小生成树" << endl;
			for (int h = 0; h < k; h++)
			{
				cout << memedge[h].i << memedge[h].j << endl;
			}
	}
	//}
	void floyd(){
		int A[max][max];
		for (int i = 1; i <= vernum; i++)
		{
			for (int j = 1; j <= vernum; j++)
			{
				A[i][j] = adjvertex[i][j];
			}
		}
		for (int k = 1; k <= vernum; k++)
		{
			for (int i = 1; i <= vernum; i++)
			{
				for (int j = 1; j <= vernum; j++){
					if (A[i][k] + A[k][j] < A[i][j])
						A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
		for (int i = 1; i <= vernum; i++)
		{
			for (int j = i+1; j <= vernum; j++)
			{
				if (A[i][j]<1000)
					cout << i << " " << j << "的最小距离为" << A[i][j] << endl;
			}
		}
	}
	void dijkstra(int i){//单源最短路经
		int R[max];//标志已经计算过的点
		R[i] = 1;
		int select;
		int D[max];//记录最小距离
		for (int j = 1; j <= vernum; j++){
			if (j != i)
			{
				R[j] = 0;
			}
		}
		for (int k = 1; k <= vernum; k++){
			D[k] = adjvertex[i][k];
		}
		for (int h = 1; h <= vernum-1; h++)
		{
			for (int p = 1; p <= vernum; p++)
			{
				if (R[p] == 0)
				{
					select = p; break;
				}
			}
			for (int q = select; q <= vernum; q++)
			{
				if (D[q] < D[select]&&R[q]==0)
					select = q;
			}
			R[select] = 1;
			for (int x = 1; x <= vernum; x++)
			{
				if (R[x] == 0 && D[x]>D[select] + adjvertex[select][x])
					D[x] = D[select] + adjvertex[select][x];
			}
		}
		for (int m = 1; m <= vernum; m++)
		{
			if (m != i)
				cout << i << "与" << m << "的最小距离为" << D[m]<<endl;
		}
	}
	void kruskal(){
		set setedge;
		int edgenum = 0;
		int n = vernum;
		edge edgeuni[max];
		int markedge[max];
		int select;
		for (int i = 1; i <= vernum;i++)
		{
			for (int j = i + 1; j <= vernum;j++)
			{
				if (adjvertex[i][j] < 1000)
				{
					edgeuni[edgenum].i = i;
					edgeuni[edgenum].j = j;
					edgeuni[edgenum].cost = adjvertex[i][j];
					edgenum++;
				}
			}
		}
		for (int e = 0; e < edgenum; e++)
		{
			markedge[e] = 0;
		}
		while (n>1)//生成树的边数为顶点数减1
		{
			for (int k = 0; k < edgenum; k++)
			{
				if (markedge[k] == 0)
				{
					select = k;
				}
			}
			for (int p = select; p < edgenum; p++)
			{
				if (edgeuni[p].cost < edgeuni[select].cost&&markedge[p] == 0 && !setedge.judge(edgeuni[p].i, edgeuni[p].j))
					select = p;
			}
			markedge[select] = 1;
			setedge.unionset(edgeuni[select].i, edgeuni[select].j);
			n--;
		}
		cout << "kruskal算法输出最小生成树" << endl;
		for (int j = 0; j < edgenum; j++)
		{
			if (markedge[j] == 1)
				cout << edgeuni[j].i << " " << edgeuni[j].j << endl;
		}
	}
	void findnepath(){
		int ACT[max][max];
		int VE[max];
		int VL[max];
		int mu[max][max];
		for (int k = 1; k <= vernum; k++)
		{
			VE[k] = 0;
		}
		for (int i = 1; i <= vernum; i++)
		{
			for (int j = 1; j <= vernum; j++)
			{
				ACT[i][j] = adjvertex[i][j];
			}
		}
		queue<int> Q;
		int v;
		for (int k = 1; k <= vernum; k++)
		{
			if (indegree[k] == 0)
				Q.push(k);
		}
		while (!Q.empty())
		{
			v = Q.front();
			Q.pop();
			for (int i = 1; i <= vernum; i++)
			{
				if ((ACT[i][v] > 0) && (VE[v] < VE[i] + ACT[i][v]))
					VE[v] = VE[i] + ACT[i][v];
			}
			for (int h = 1; h <= vernum; h++)
			{
				if (adjvertex[v][h] != -1)
				{
					indegree[h]--;
					if (indegree[h]==0)
						Q.push(h);
				}
			}
		}
		queue<int> QQ;
		for (int u = 1; u <= vernum; u++)
		{
			if (outdegree[u] == 0)
			{
				QQ.push(u);
				for (int y = 1; y <= vernum; y++)
				{
					VL[y] = VE[u];
				}
			}
		}
		while (!QQ.empty())
		{
			v = QQ.front();
			QQ.pop();
			for (int i = 1; i <= vernum; i++)
			{
				if ((ACT[v][i] > 0) && (VL[v] > VL[i] - ACT[v][i]))
					VL[v] = VL[i]-ACT[v][i];
			}
			for (int h = 1; h <= vernum; h++)
			{
				if (adjvertex[h][v] != -1)
				{
					outdegree[h]--;
					if (outdegree[h] == 0)
						QQ.push(h);
				}
			}
		}
		for (int a = 1; a <= vernum; a++)
		{
			for (int s = 1; s <= vernum; s++)
			{
				mu[a][s] = VL[s] - ACT[a][s] - VE[a];
			}
		}
		for (int a = 1; a <= vernum; a++)
		{
			for (int s = 1; s <= vernum; s++)
			{
				if (mu[a][s] == 0&&ACT[a][s]>0)
					cout << a << "  " << s << "为关键路径上的一条边" << endl;
			}
		}
	}
};