
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
#pragma warning(disable:4996)
using namespace std;
const int N = 100007;
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
struct node {
	node *next[36];
	int gs;
}root;
string line[N];
int num_line, eft_num, eft_char, eft_word;//num_line Ϊ�ļ������� eft_numΪ��Ч���� eft_charΪ�ַ��� eft_wordΪ��Ч������
int Atoatoint(char c) { //����д�ַ�ת��ΪСд��ĸ����hash��0~25���Լ���0~9hash��26~35.
	if (c >= 'A'&&c <= 'Z')c += 'A' - 'a';
	if (c >= 'a'&&c <= 'z') return c - 'a';
	else return c - '0' + 26;
}
char FAtoatoint(int c) { //���ϸ������ķ�����
	if (c >= 0 && c <= 25)return 'a' + c;
	else return c - 26 + '0';
}
void qinsert(string s) {  //�ֵ������뵥��
	int len = s.size(), tmp;
	node *p;
	p = &root;
	rep(i, 0, len) {
		tmp = Atoatoint(s[i]);
		if (p->next[tmp] == NULL) {
			p->next[tmp] = new node(); p->next[tmp]->gs = 0;
		}
		p = p->next[tmp];
		if (i == len - 1) { p->gs++; }
	}
}
void MYscanf(char s[]) {  // �����ܿ���̨
	freopen(s, "r", stdin);
	//freopen("0.in", "r", stdin);
	string str;
	while (getline(cin, str)) {
		int len = str.size();
		line[num_line++] = str;
		if (len == 0)continue;
		bool f = 0;
		rep(i, 0, len) {
			if (str[i] != ' ')f = 1;
		}
		if (f) { eft_num++; }
	}
}
int CountChar() {
	int ret = 0;
	rep(i, 0, num_line) {
		int lim = line[i].size();
		rep(j, 0, lim) {
			if (line[i][j] >= 0 && line[i][j] <= 255)ret++;//ͳ����Ч�ַ�
		}
		ret++;//���ӻ��з�,ÿ�ж��У��������
	}
	return ret - 1;//���һ��û�л��з�����ȥ֮��
}
bool is_efct_char(char c) {
	if ((c >= '0'&&c <= '9') || (c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z'))return true;
	return false;
}
int CountWord() {
	int ret = 0;
	rep(i, 0, num_line) {
		bool f = 1; int lim = line[i].size();
		rep(j, 0, lim) {
			if (is_efct_char(line[i][j])) {
				string str = ""; str += line[i][j];
				rep(k, j + 1, lim) {
					if (is_efct_char(line[i][k]))str += line[i][k], j = k;
					else { j = k;  break; }
				}
				bool f = 0;; int siz = str.size() - 1;
				rep(k, 0, siz) {
					if (str[k] >= '0'&&str[k] <= '9' && (str[k + 1]<'0' || str[k + 1]>'9'))f = 1;
				}
				if (!f) {//�ж��Ƿ�����Ч����
					ret++;
					qinsert(str);//���ֵ����в����������,Ϊ���㵥�ʳ��ִ�����׼�����ֵ�����Լ�ռ��Լ�Ϊ����ͳ�ƴ��������ʱ�临�Ӷ�
				}
			}
		}
	}
	return ret;
}
string tmp;
set<pair<int, string> >qur;//����set���򣬵��ʴ���Ϊ��һ���ȼ���string�ֵ���Ϊ�ڶ����ȼ�
set<pair<int, string> >::iterator it;
void dfs_getword(node u) {
	if (u.gs != 0) {
		qur.insert(make_pair(-u.gs, tmp));
		if (qur.size() > 10) {
			it = qur.end();
			it--;
			qur.erase(it);
		}
	}
	rep(i, 0, 36) {
		if (u.next[i] != NULL) {
			tmp += FAtoatoint(i);
			dfs_getword(*u.next[i]);
			tmp.erase(tmp.size() - 1);
		}
	}
}
void CountMxWord() {
	qur.clear(); tmp = "";
	dfs_getword(root);
}
void MYprint() {
	freopen("result.txt", "w", stdout);
	cout << "character: " << eft_char << endl;
	cout << "words: " << eft_word << endl;
	cout << "lines: " << eft_num << endl;
	for (it = qur.begin(); it != qur.end(); it++) {
		cout << "<" << it->second << ">: " << -it->first << endl;
	}
}
void init() {
	root.gs = 0;
}
int main(int argc, char *argv[])
{
	init();
	MYscanf(argv[1]);
	eft_char = CountChar();
	eft_word = CountWord();
	CountMxWord();
	MYprint();
	return 0;
}