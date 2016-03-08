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
HashTable < E,K>:: HashTable(int divisor) {// ���캯��
	D = divisor;
	// ����ɢ������ 
	ht = new E [D];
	empty = new bool[D];
	// ������Ͱ�ÿ�
	for (int i = 0; i < D; i++) 
		empty[i] = true;
}
template<class E, class K>
int HashTable<E, K>::hSearch(const K& k) const {// ����һ������ַ�� 
	// ������ڣ��򷵻�k��λ�� 
	// ���򷵻ز���㣨������㹻�ռ䣩 
	int i = k % D; 
	// ��ʼͰ
	int j = i;  
	// ����ʼͰ����ʼ
	do {
		if (empty[j] || ht[j].key==k) 
			return j;
		j = (j + 1) % D;  // ��һ��Ͱ
	} while (j != i); // �ַ�����ʼͰ?
	return j;  // ���Ѿ���
}
template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E& e) const 
{	// ������kƥ���Ԫ�ز�����e 
	// ���������������Ԫ�أ��򷵻�false 
	int b = hSearch(k); 
	if (empty[b]||ht[b].key!= k) 
		return false; 
	e = ht[b]; 
	return true; 
}
template<class E, class K> 
/*HashTable<E, K>& */void HashTable<E, K>::Insert(const E& e) {
	// ��ɢ�б��в��� 
	K k = e.key; // ��ȡk e yֵ 
	int b = hSearch(k);
	// ����Ƿ�����ɲ��� 
	if (empty[b]) 
	{
		empty[b] = false; 
		ht[b] = e; 
		//return *this;
	}
	//���ܲ���, ����Ƿ����ظ�ֵ����� 
	//if (ht[b] == k) 
		//throw BadInput(); 
	// ���ظ� 
	//throw NoMem(); // ����
}



