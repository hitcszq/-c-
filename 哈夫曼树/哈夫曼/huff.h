#include <iostream>
using namespace std;
#include <string.h>
#include <stack>
#define n 200
#define m 2*n-1
class huff{
public:
	char ch;
	int code[50];
	int weight;
	int parent;
	int leftchild;
	int rightchild;
	huff(){
		ch = '#';
		weight=0;
		parent = -1;
		leftchild = -1;
		rightchild = -1;
	}
};
class huffcode{
public:
	char article[100];
	huff HUT[m];
	void initial();
	void encode();
	void decode();
	void build();
	int basiccode;
};
void huffcode::initial(){
	cout << "请输入要进行编码的内容" << endl;
	cin >> article;
	int num; int flagnum = 0; int j = 1;
	int th=1;
	num = sizeof(article);
	for (int i = 0; i < num; i++)
	{
		while (HUT[j].ch!= article[i]&&j<=flagnum)
		{
			j++;
		}
		if (HUT[j].ch == article[i])
		{
			HUT[j].weight++;
		}
		if (j > flagnum)
		{
			HUT[j].ch = article[i];
			HUT[j].weight = 1;
			flagnum++;
		}
	}
	while (HUT[th].ch != '#'){
		th++;
	}
	basiccode =th-1;
}
void huffcode::build(){
	int pmin1 ,  pmin2 ; int flag = 0;//找到两个不同的初始点
	for (int j = basiccode + 1; j <= 2 * basiccode - 1; j++)
	{
		for (int i = 1; i < j&&HUT[i].parent == -1 && HUT[i].ch != '#'; i++)
		{
			if (flag == 0)
			{
				pmin1 = i;
				flag = 1;
			}
			else if (flag == 1)
			{
				pmin2 = i;
				break;
			}
		}
		for (int i = 1; i <j&&HUT[i].parent == -1; i++)//选出最小的两个点
		{
			if (HUT[pmin1].weight > HUT[i].parent)
				pmin1 = i;
		}
		for (int i = 1; i <j&&HUT[i].parent == -1; i++)//选出最小的两个点
		{
			if (HUT[pmin2].weight > HUT[i].parent&&i != pmin1)
				pmin2 = i;
		}
		HUT[pmin1].parent = j;
		HUT[pmin2].parent = j;
		HUT[j].ch = '*';
		HUT[j].leftchild = pmin1;
		HUT[j].rightchild = pmin2;
	}
}
void huffcode::encode(){
	int p, mi; stack<int> code;
	int j ;
	for (int i = 1; i <= basiccode; i++)
	{
		j = 0;
		mi = i;
		while (HUT[i].parent != -1)
		{
			p = HUT[i].parent;
			if (HUT[p].leftchild == i)
				code.push(0);
			else if (HUT[p].rightchild == i)
				code.push(1);
			i = p;
		}
		i = mi;
		while (!code.empty())
		{
			HUT[i].code[j] = code.top();
			code.pop();
			j++;
		}
		HUT[i].code[j] = -1;
	}

}
void huffcode::decode(){

	for (int i = 1; i <= basiccode; i++)
	{
		cout << HUT[i].ch << endl;
		int j=0;
		while (HUT[i].code[j] != -1)
		{
			cout << HUT[i].code[j];
			j++;
		}
		cout << endl;
	}
}