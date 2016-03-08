#include <iostream>
#include <queue>
using namespace std;
typedef struct{
	char name[20];
	char sex;
}Person;
void Dancepartner(Person dancer[], int num)
{
	int i;
	Person p,m,n;
	queue<Person> Mdancers, Fdancers;
	for (i = 0; i < num; i++){
		p = dancer[i];
		if (p.sex == 'F')
			Fdancers.push(p);
		else
			Mdancers.push(p);
	}
	while (!Fdancers.empty() && !Mdancers.empty())
	{
		cout << "输已经配对的舞伴"<<endl;
		m = Fdancers.front();
		Fdancers.pop();
		cout << m.name << m.sex<<endl;
		n = Mdancers.front();
		Mdancers.pop();
		cout << n.name << n.sex<<endl;
	}
	cout << "未配对的女性";
	while (!Fdancers.empty())
	{
		m = Fdancers.front();
		Fdancers.pop();
		cout << m.name << m.sex << endl;
	}
	cout << "未配对的男性";
	while (!Mdancers.empty())
	{
		m = Mdancers.front();
		Mdancers.pop();
		cout << m.name << m.sex<<endl;
	};
}
int main(){
	const int max = 50;
	int n;
	Person dancer[50];
	cin >> n;
	for (int i=0; i < n; i++)
	{
		cin >> dancer[i].name >> dancer[i].sex;
	}
	Dancepartner(dancer, n);
	return 0;
}