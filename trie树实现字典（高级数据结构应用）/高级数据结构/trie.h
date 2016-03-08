
#include <stdlib.h>
#include<iostream>
#include<string>
#include <conio.h>
#include<ctype.h>
#include<fstream>
using namespace std;
const int LenChild = 26;
const int Max_Word_Len = 30;
const int Max_Word_Information_Len = 300;
typedef class node{//节点类
	bool has;//标注该节点是否存有信息
	node * child[LenChild];//字母总数的指针数组存放儿子节点
	string * inf;//节点信息，单词释义
	friend class TREE;
public:
	node(){
		has = false;
		inf = NULL;
		for (int i = 0; i<LenChild; i++) child[i] = NULL;
	}
	~node(){
		delete inf;
	}
	string * getinf(){
		return inf;
	}
}node, *tree;

class TREE{//Trie树类
	tree T;
public:
	TREE(){
		T = new node;;
	}
	void clear(node *p){
		for (int i = 0; i<LenChild; i++){
			if (p->child[i]) clear(p);
		}
		delete p;
	}
	~TREE(){
		clear(T);
	}
	bool Insert_word(char *word, char *ch){//插入单词
		int i = 0; node *p = T;
		while (word[i]){
			int index = word[i] - 'a';
			if (!p->child[index]){
				p->child[index] = new node;
			}
			p = p->child[index];
			i++;
		}
		p->has = true;
		p->inf = new string(ch);
		return true;
	}
	bool has_word(char *word, tree &the){//判断某单词是否存在
		int i = 0; node *p = T;
		while (word[i]){
			int index = word[i] - 'a';
			if (!p->child[index]) break;
			p = p->child[index];
			i++;
		}
		the = p;
		return p->has && i == strlen(word);
	}

	bool delete_word(char *word){//删除某单词
		int i = 0; node *p = T;
		while (word[i]){
			int index = word[i] - 'a';
			if (!p->child[index]) break;
			p = p->child[index];
			i++;
		}
		if (p->has && i == strlen(word)){//逻辑删除
			delete p->inf;
			p->has = false; return true;
		}
		else { return false; }
	}
	void dfs(tree p, string *w[], node *ans[], int & Count, char *e, int len){
		if (Count >= 8) return;
		e[len] = '\0';
		if (p->has){
			ans[Count] = p;
			w[Count++] = new string(e);
		}
		for (int i = 0; i<LenChild; i++){
			if (p->child[i]){
				e[len] = i + 'a';
				dfs(p->child[i], w, ans, Count, e, len + 1);
			}
		}
	}
	void Find_word(char *word, string *w[], node *ans[], int & Count){
		char e[Max_Word_Len];
		int i = 0, len = 0; node *p = T;
		while (word[i]){
			int index = word[i] - 'a';
			e[len++] = word[i];
			if (!p->child[index]) break;
			p = p->child[index];
			i++;
		}
		if (i == strlen(word)){
			dfs(p,w,ans,Count,e,len);
		}
	}
	void Creat(){
		system("cls");
		cout << endl << endl << "\t\t正在启动......" << endl;
		fstream infile;
		infile.open("word.data", ios::in);
		if (!infile){
			cout << "file word.txt not find" << endl;
			system("pause");
			abort();
		}
		char s[Max_Word_Len + 1], ch[Max_Word_Information_Len];
		while (!infile.eof()){
			infile.getline(s, sizeof(s));
			infile.getline(ch, sizeof(ch));
			//   cout<<s<<endl<<ch<<endl;
			Insert_word(s, ch);
		}
		infile.close();
		cout << endl << endl << "\t\t启动完成......\n\n\t\t";
		system("pause");
	}
	void DF(tree p, fstream &outfile, char *e, int len){//深度优先搜索
		e[len] = '\0';
		if (p->has){
			outfile << e << endl << *p->inf << endl;
		}
		for (int i = 0; i<LenChild; i++){
			if (p->child[i]){
				e[len] = i + 'a';
				DF(p->child[i], outfile, e, len + 1);
			}
		}
	}
	void Wreat_to_file(char* filename){
		system("cls");
		cout << endl << endl << "\t\t正在关闭......" << endl;
		fstream outfile;
		outfile.open(filename, ios::out);
		if (!outfile){
			cout << "file word.txt not find\n\n\t";
			system("pause");
			abort();
		}
		char e[Max_Word_Len];
		DF(T, outfile, e, 0);
		outfile.close();
		cout << endl << endl << "\t\t关闭完成......\n\n\t";
		system("pause");
	}
};

bool check_ok(char *s){
	int len = strlen(s);
	if (len == 0)return false;
	cout << endl;
	if (len>Max_Word_Len) {
		cout << "\t你输入的单词过长" << endl << endl;
		cout << "\t";
		system("pause");
		return false;
	}
	bool flag = true;
	for (int i = 0; i<len; i++){
		if (!isalpha(s[i])) {
			cout << "\t请输入了合法法字符请输入 a~z" << endl << endl;
			cout << "\t";
			system("pause");
			return false;
		}
	}
	return true;
}
void display(string *s, node *p){
	system("cls");
	cout << "\n\n" << *s << endl << endl;
	cout << *(*p).getinf() << endl << endl << endl;
	system("pause");
}
void back(){
	system("cls");
	cerr << "\n\n\n\n\t\t~~提示~~：错误输入超过三次!你将被强制返回!!\n\n\n" << endl;
	cout << "\t\t";
	system("pause");
}
void findword(TREE& Tree){//查询单词模块
	char s[100];
	int Count = 0;
	string *w[10];
	node *ans[10];
	int K = 0;
	while (true){
		system("cls");
		cout << endl << endl;
		cout << "\n" << endl;
		cout << "\t输入：BACK 返回" << endl << endl;
		cout << "\t请输入单词：";
		cin.getline(s, 100);
		if (!strcmp(s, "BACK"))return;
		if (!check_ok(s)){
			if (++K>3){
				back(); return;
			}
			else continue;
		}
		for (int i = 0; i<strlen(s); i++) s[i] = tolower(s[i]);
		Tree.Find_word(s, w, ans, Count);
		if (Count == 0){
			cout << "\n\t你要查找的单词" << s << endl << endl;
			cout << "\t对不起没有该单词" << endl << endl;
			cout << "\t";
			system("pause");
			K = 0;
			continue;
		}
		else break;
	}
	char A[10]; int k = 0, b;
	while (true){
		system("cls");
		cout << "\n\n\t你要查找的单词" << s << endl;
		for (int i = 0; i<Count; i++){
			cout << "\t" << i + 1 << "  " << *w[i] << endl << endl;
		}
		cout << "\t0" << "  " << "返回" << endl << endl;
		cout << "\t输入序号查看单词：";
		cin.getline(A, 100);
		if (strlen(A) == 1 && isdigit(A[0]) && '0' <= A[0] && A[0] - '0' <= Count)
		{
			b = A[0] - '0';
		}
		else{
			cerr << "\n\t输入有误!\n\n\t";
			system("pause");
			k++;
			if (k>2)
			{
				back();
				b = 0;
			}
			else continue;
		}
		if (b == 0){
			for (int i = 0; i<Count; i++){
				delete w[i];
			}
			return;
		}
		display(w[b - 1], ans[b - 1]);
		K = 0;
	}
}
void insertword(TREE &Tree){//插入单词模块
	char s[100], ch[300];
	int K = 1; node *p;
	while (true){
		system("cls");
		cout << "\n\n\t输入：BACK 返回\n\n" << endl;
		cout << "\t输入要增加的单词:";
		cin.getline(s, 100);
		if (!strcmp(s, "BACK"))return;
		if (!check_ok(s)){
			if (++K>3){
				back(); return;
			}
			continue;
		}
		if (Tree.has_word(s, p)){
			cout << "\n\t你要插入的单词已经存在了\n\n\t";
			system("pause");
			K = 0;
		}
		else break;
	}
	while (true){
		system("cls");
		cout << "\n\n\t你要增加的单词是：" << s << endl << endl;
		cout << "\t取消插入单词输入并返回请输入:BACK" << endl;
		cout << "\n\t单词解释:";
		cin.getline(ch, 300);
		if (!strcmp(ch, "BACK")) return;
		if (strlen(ch) == 0)continue;
		if (Tree.Insert_word(s, ch)){
			cout << "\n\t加词成功\n\n\t";
			system("pause");
			return;
		}
	}
}
void deleteword(TREE &Tree){//删除单词模块
	char s[100];
	int K = 1;
	while (true){
		system("cls");
		cout << "\n\n\n\t输入：BACK 返回" << endl << endl;
		cout << "\t输入要删除的单词:";
		cin.getline(s, 100);
		if (!strcmp(s, "BACK"))return;
		if (!check_ok(s)){
			if (++K>3){
				back(); return;
			}
			continue;
		}
		if (Tree.delete_word(s)){
			cout << "\t删除成功\n\n\t";
			system("pause");
			return;
		}
		else{
			cout << "\t没有找到此单词\n\n\t";
			system("pause");
			continue;
		}
	}
}
void test(){
	TREE Tree;
	Tree.Creat();
	while (true){
		char A[10]; int k = 0, b;
		while (true)
		{
			system("cls");
			cout << endl << endl;
			cout << "\t\t\t\t字典\n\n" << endl;
			cout << "\t\t********************************************\n";
			cout << "\t\t********************************************\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               欢迎使用!                  *\n"
				<< "\t\t*     操作方式:                            *\n"
				<< "\t\t*               1.查询单词                 *\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               2.增加单词                 *\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               3.删除单词                 *\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               0.退出系统                 *\n"
				<< "\t\t********************************************\n" << endl;


			cout << "\t\t\t请选择操作方式: ";
			cin.getline(A, 100);
			if (strlen(A) == 1 && '0' <= A[0] && A[0] <= '3')
			{
				b = A[0]; break;
			}
		}
		switch (b){
		case '0': Tree.Wreat_to_file("word.data"); return;
		case '1': findword(Tree);
			break;
		case '2': insertword(Tree);
			break;
		case '3': deleteword(Tree);
			break;
		}
	}
}





