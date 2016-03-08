template <class T>
class binarynode
{
public:
	T element;
	binarynode<T>* left;
	binarynode<T>* right;
	binarynode<T>(){};
	binarynode<T>(T &theelement, binarynode<T> *lt, binarynode<T> *rt) :
		element(theelement), left(lt), right(rt){ }
};
template <class T>
class binarysearchtree
{
public:
	binarysearchtree(){
		root = NULL;
	}
	
	~binarysearchtree();

	T &findmin(){
		return findmin(root)->element;
	}
	T &findmax(){
		return findmax(root)->element;
	}
	/*bool contains(T &x){
		return contains(x, root);
	}*/

	void printtree(){
		printtree(root);
	}
	void insert(T &x){
		insert(x, root);
	}

private:
	binarynode<T> *root;
	void insert(T &x, binarynode<T> *&t);
	binarynode<T> *findmin(binarynode<T> *t);
	binarynode<T> *findmax(binarynode<T> *t);
	/*bool contains(T &x, binarynode<T> *t){
		if (t == NULL)
			return false;
		else if (islessthan(x, t->element))
			return contains(x, t->left);
		else if (islessthan(t->element, x))
			return contains(x, t->right);
		else
			return true;
	}*/
	void printtree(binarynode<T> *t){
		if (t != NULL){
			printtree(t->left);
			cout << t->element<<"   ";
			printtree(t->right);
		}
	};
	
};
template <class T>
void binarysearchtree<T>::insert(T &x, binarynode<T> * &t) 
{
	if (t == NULL)
		t = new binarynode<T>(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else;
}
template <class T>
binarynode<T> * binarysearchtree<T>::findmin(binarynode<T> *t)
{
	if (t== NULL)
		return NULL;
	if (t->left == NULL)
		return t;
	else
		return findmin(t->left);
}
template <class T>
binarynode<T> * binarysearchtree<T>::findmax(binarynode<T> *t)
{
	if (t != NULL)
	{
		while (t->right != NULL)
			t = t->right;
	}
	return t;
}

