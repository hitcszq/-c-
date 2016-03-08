#include <iostream>
#define max 100
class set{
private:
	struct mfset{
		int parent;
	};
	mfset mfsetarr[max];
public:
	int find(int i){
		while (mfsetarr[i].parent != -1)
			i = mfsetarr[i].parent;
		return i;
	}
	bool judge(int i,int j){
		if (find(i) == find(j))
			return true;
		else
			return false;
	}
	void unionset(int i,int j){
		mfsetarr[find(i)].parent = j;
	}
	set(){
		for (int i = 0; i < max; i++)
			mfsetarr[i].parent = -1;
	}
};