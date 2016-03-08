#include <iostream>
using namespace std;
struct unionfind{//若是根节点，则
	int parent;
	double data;
	int num;
};
int findroot(const unionfind &a, const unionfind set[]){
	int t = a.num;
	while (set[t].parent != -1)
	{
		t = set[t].parent;
	}
	if (set[t].parent == -1)
		return t;
}
bool find(const unionfind &a, const unionfind &b, unionfind set[]){

	return (findroot(a, set) == findroot(b, set));
}
int findroot( unionfind &a, unionfind set[]){
	int t = a.num;
	while (set[t].parent != -1)
	{
		t = set[t].parent;
	}
	if (set[t].parent == -1)
		return t;
}
void union2(unionfind &a, unionfind &b, unionfind set[])
{
	if (find(a, b, set))
		cout << "两个元素已经再同一集合中"<<endl;
	else
	{
		int m;
		m= findroot(b, set);
		set[m].parent = a.num;
	}

}


int main(){
	const int max = 100;
	unionfind ufset[max];
	int n,k,h; cin >> n;
	int select=0;
	for (int i = 0; i < n; i++)
	{
		ufset[i].num = i;
		cin>>ufset[i].data;
		ufset[i].parent = -1;
	}
	while (n != 3)
	{
		cout << "1.并,2.查,3退出" << endl;
		cin >> n;
		if (n == 1)
		{
			cin >> k >> h;
			union2(ufset[k], ufset[h], ufset);
		}
		else if (n == 2)
		{
			cin >> k >> h;
			if (find(ufset[k], ufset[h], ufset))
			{
				cout << "在同一集合中"<<endl;
			}
			else
				cout << "不在同一集合中"<<endl;
		}
	}
	return 0;
}