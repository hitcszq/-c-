#include <iostream>
using namespace std;
#define B 100
struct records{
	int key;
};
struct celltype{
	records data;
	celltype *next;
};
typedef celltype* cellptr;
class outhash{
	cellptr hashtable[B];
	
public:
	outhash(){
		for (int i = 0; i < B; i++)
			hashtable[i] = NULL;
	}
	cellptr search(int k)
	{
		cellptr bptr=NULL;
		bptr = hashtable[hash(k)];
		while (bptr != NULL)
		{
			if (bptr->data.key == k)
				return bptr;
			else bptr = bptr->next;
		}
		return bptr;
	}
	int hash(int k){
		return k%B;
	}
	void insert(records R)
	{
		int bucket;
		cellptr oldheader;
		if (search(R.key) == NULL)
		{
			bucket = hash(R.key);
			oldheader = hashtable[bucket];
			hashtable[bucket] = new celltype;
			hashtable[bucket]->data = R;
			hashtable[bucket]->next = oldheader;
		}
	}
	void deletel(int key) {
		int bucket;
		cellptr bptr;
		bool b;
		bucket = hash(key);
		b = false;
		if (hashtable[bucket] != NULL)
		if (hashtable[bucket]->data.key == key)
			hashtable[bucket] = hashtable[bucket]->next;
		else{
			bptr = hashtable[bucket];
			while ((bptr->next != NULL) && b == false)
			{
				if (bptr->next->data.key == key){
					bptr->next = bptr->next->next;
					b = true;
				}
			}
		}
		else
			bptr = bptr->next;
	}
};