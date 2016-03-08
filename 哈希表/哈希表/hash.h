template<class E, class K>
class HashTable {
	public:
		HashTable(int divisor = 11);
		~HashTable() 
		{
			delete[] ht; 
			delete[] empty;
		} 
		bool Search(const K& k, E& e) const; 
		/*HashTable<E, K>& */void Insert(const E& e);
	private : 
		int hSearch(const K& k) const; 
		int D; 
		E* ht;
		bool* empty;
		
};
template<class E, class K> 
HashTable < E,K>:: HashTable(int divisor) {// 构造函数
	D = divisor;
	// 分配散列数组 
	ht = new E [D];
	empty = new bool[D];
	// 将所有桶置空
	for (int i = 0; i < D; i++) 
		empty[i] = true;
}
template<class E, class K>
int HashTable<E, K>::hSearch(const K& k) const {// 查找一个开地址表 
	// 如果存在，则返回k的位置 
	// 否则返回插入点（如果有足够空间） 
	int i = k % D; 
	// 起始桶
	int j = i;  
	// 在起始桶处开始
	do {
		if (empty[j] || ht[j].key==k) 
			return j;
		j = (j + 1) % D;  // 下一个桶
	} while (j != i); // 又返回起始桶?
	return j;  // 表已经满
}
template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E& e) const 
{	// 搜索与k匹配的元素并放入e 
	// 如果不存在这样的元素，则返回false 
	int b = hSearch(k); 
	if (empty[b]||ht[b].key!= k) 
		return false; 
	e = ht[b]; 
	return true; 
}
template<class E, class K> 
/*HashTable<E, K>& */void HashTable<E, K>::Insert(const E& e) {
	// 在散列表中插入 
	K k = e.key; // 抽取k e y值 
	int b = hSearch(k);
	// 检查是否能完成插入 
	if (empty[b]) 
	{
		empty[b] = false; 
		ht[b] = e; 
		//return *this;
	}
	//不能插入, 检查是否有重复值或表满 
	//if (ht[b] == k) 
		//throw BadInput(); 
	// 有重复 
	//throw NoMem(); // 表满
}



