#include <iostream>
using namespace std;
#include <queue>
#define max 100000
class records{
	struct data {
		int key;
	};
	data ABC[max];
	int num;
	int figure;
public:
	records(){
		cout << "数据量，数据位数" << endl;
		cin >> num;
		cin >> figure;
		for (int i = 0; i < num; i++)
		{
			cin >> ABC[i].key;
		}
	}
	void radixsort(){
		queue<data> A;
		queue<data> Q[10];
		for (int i = 0; i < num; i++)
		{
			A.push(ABC[i]);
		}
		for (int pass = 1; pass <= figure; pass++)
		{
			data miao;
			int r;
			while (!A.empty())
			{
				miao = A.front();
				A.pop();
				r = radix(miao.key,pass);
				Q[r].push(miao);
			}
			for (int i = 0; i <= 9; i++)
			{
				while (!Q[i].empty())
				{
					miao = Q[i].front();
					Q[i].pop();
					A.push(miao);
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			ABC[i] = A.front();
			A.pop();
		}
	}
	int radix(int k, int p)
	{
		int power;
		power = 1;
		for (int i = 1; i <= p - 1; i++)
			power = power * 10;
		return ((k % (power * 10)) / power);
	}
	void output(){
		for (int i = 0; i < num; i++)
		{
			cout << ABC[i].key << endl;
		}
	}
};