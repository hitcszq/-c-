template <class E, class K>
class skipnode{
	friend skiplist<E,K>
	private:
		skipnode(int size)
		{
			link = new skipnode<E, K> *[size];
		}
		~skipnode(){ delete[] link;}
		E data;
		skipnode <E,K>
};