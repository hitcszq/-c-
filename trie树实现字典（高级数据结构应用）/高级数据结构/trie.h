
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
typedef class node{//�ڵ���
	bool has;//��ע�ýڵ��Ƿ������Ϣ
	node * child[LenChild];//��ĸ������ָ�������Ŷ��ӽڵ�
	string * inf;//�ڵ���Ϣ����������
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

class TREE{//Trie����
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
	bool Insert_word(char *word, char *ch){//���뵥��
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
	bool has_word(char *word, tree &the){//�ж�ĳ�����Ƿ����
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

	bool delete_word(char *word){//ɾ��ĳ����
		int i = 0; node *p = T;
		while (word[i]){
			int index = word[i] - 'a';
			if (!p->child[index]) break;
			p = p->child[index];
			i++;
		}
		if (p->has && i == strlen(word)){//�߼�ɾ��
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
		cout << endl << endl << "\t\t��������......" << endl;
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
		cout << endl << endl << "\t\t�������......\n\n\t\t";
		system("pause");
	}
	void DF(tree p, fstream &outfile, char *e, int len){//�����������
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
		cout << endl << endl << "\t\t���ڹر�......" << endl;
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
		cout << endl << endl << "\t\t�ر����......\n\n\t";
		system("pause");
	}
};

bool check_ok(char *s){
	int len = strlen(s);
	if (len == 0)return false;
	cout << endl;
	if (len>Max_Word_Len) {
		cout << "\t������ĵ��ʹ���" << endl << endl;
		cout << "\t";
		system("pause");
		return false;
	}
	bool flag = true;
	for (int i = 0; i<len; i++){
		if (!isalpha(s[i])) {
			cout << "\t�������˺Ϸ����ַ������� a~z" << endl << endl;
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
	cerr << "\n\n\n\n\t\t~~��ʾ~~���������볬������!�㽫��ǿ�Ʒ���!!\n\n\n" << endl;
	cout << "\t\t";
	system("pause");
}
void findword(TREE& Tree){//��ѯ����ģ��
	char s[100];
	int Count = 0;
	string *w[10];
	node *ans[10];
	int K = 0;
	while (true){
		system("cls");
		cout << endl << endl;
		cout << "\n" << endl;
		cout << "\t���룺BACK ����" << endl << endl;
		cout << "\t�����뵥�ʣ�";
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
			cout << "\n\t��Ҫ���ҵĵ���" << s << endl << endl;
			cout << "\t�Բ���û�иõ���" << endl << endl;
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
		cout << "\n\n\t��Ҫ���ҵĵ���" << s << endl;
		for (int i = 0; i<Count; i++){
			cout << "\t" << i + 1 << "  " << *w[i] << endl << endl;
		}
		cout << "\t0" << "  " << "����" << endl << endl;
		cout << "\t������Ų鿴���ʣ�";
		cin.getline(A, 100);
		if (strlen(A) == 1 && isdigit(A[0]) && '0' <= A[0] && A[0] - '0' <= Count)
		{
			b = A[0] - '0';
		}
		else{
			cerr << "\n\t��������!\n\n\t";
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
void insertword(TREE &Tree){//���뵥��ģ��
	char s[100], ch[300];
	int K = 1; node *p;
	while (true){
		system("cls");
		cout << "\n\n\t���룺BACK ����\n\n" << endl;
		cout << "\t����Ҫ���ӵĵ���:";
		cin.getline(s, 100);
		if (!strcmp(s, "BACK"))return;
		if (!check_ok(s)){
			if (++K>3){
				back(); return;
			}
			continue;
		}
		if (Tree.has_word(s, p)){
			cout << "\n\t��Ҫ����ĵ����Ѿ�������\n\n\t";
			system("pause");
			K = 0;
		}
		else break;
	}
	while (true){
		system("cls");
		cout << "\n\n\t��Ҫ���ӵĵ����ǣ�" << s << endl << endl;
		cout << "\tȡ�����뵥�����벢����������:BACK" << endl;
		cout << "\n\t���ʽ���:";
		cin.getline(ch, 300);
		if (!strcmp(ch, "BACK")) return;
		if (strlen(ch) == 0)continue;
		if (Tree.Insert_word(s, ch)){
			cout << "\n\t�Ӵʳɹ�\n\n\t";
			system("pause");
			return;
		}
	}
}
void deleteword(TREE &Tree){//ɾ������ģ��
	char s[100];
	int K = 1;
	while (true){
		system("cls");
		cout << "\n\n\n\t���룺BACK ����" << endl << endl;
		cout << "\t����Ҫɾ���ĵ���:";
		cin.getline(s, 100);
		if (!strcmp(s, "BACK"))return;
		if (!check_ok(s)){
			if (++K>3){
				back(); return;
			}
			continue;
		}
		if (Tree.delete_word(s)){
			cout << "\tɾ���ɹ�\n\n\t";
			system("pause");
			return;
		}
		else{
			cout << "\tû���ҵ��˵���\n\n\t";
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
			cout << "\t\t\t\t�ֵ�\n\n" << endl;
			cout << "\t\t********************************************\n";
			cout << "\t\t********************************************\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               ��ӭʹ��!                  *\n"
				<< "\t\t*     ������ʽ:                            *\n"
				<< "\t\t*               1.��ѯ����                 *\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               2.���ӵ���                 *\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               3.ɾ������                 *\n"
				<< "\t\t*                                          *\n"
				<< "\t\t*               0.�˳�ϵͳ                 *\n"
				<< "\t\t********************************************\n" << endl;


			cout << "\t\t\t��ѡ�������ʽ: ";
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





