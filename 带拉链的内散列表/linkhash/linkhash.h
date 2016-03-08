#include <iostream>
using namespace std;
#define B 15
struct records{
	int key;
	records* next;
};
class linkhash{
	records hashtable[B];
public:
	int hash(int i)
	{
		return i % 15;
	}
	void insert(records E)
	{
		int h = hash(E.key);
		if (hashtable[h].key == 0)
			hashtable[h] = E;
		else{
			records* ptr;
			ptr->key = E.key;
			ptr->next = hashtable[h].next;
			hashtable[h].next=ptr;
		}
	}
	bool search(int thekey)
	{
		int a = thekey%B;
		if (hashtable[a].key == 0)
			return false;
		else{
			records* ptr=&hashtable[a];
			while (ptr != NULL)
			{
				if (ptr->key == thekey)
					return true;
				ptr = ptr->next;
			}
		}
		return false;
	}
	linkhash(){
		for (int i = 0; i < B; i++)
		{
			hashtable[i].key = 0;
			hashtable[i].next = NULL;
		}
	}
};