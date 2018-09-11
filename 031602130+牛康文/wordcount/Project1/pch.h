
#ifndef PCH_H
#define PCH_H
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<utility>
#include<set>
#include<map>
using namespace std;
const int N = 100007;
#pragma warning(disable:4996)
#define de(x) cout<<#x<<" = "<<x<<endl
#define rep(i,a,b) for(int i=(a);i<(b);++i)
class  QWE_wordCount {
public:
	string line[N];
	string tmp;
	set<pair<int, string> >qur;//����set���򣬵��ʴ���Ϊ��һ���ȼ���string�ֵ���Ϊ�ڶ����ȼ�
	set<pair<int, string> >::iterator it;
	struct node {
		node *next[36];
		int gs;
	}root;
	int num_line, eft_num, eft_char, eft_word;//num_line Ϊ�ļ������� eft_numΪ��Ч���� eft_charΪ�ַ��� eft_wordΪ��Ч������
	int Atoatoint(char c);
	char FAtoatoint(int c);
	void qinsert(string s);
	void MYscanf(char s[]);
	int CountChar();
	bool is_efct_char(char c);
	int CountWord();
	void dfs_getword(node u);
	void CountMxWord();
	void MYprint();
	void init();
};
// TODO: ���Ҫ�ڴ˴�Ԥ����ı�ͷ
#endif //PCH_H#pragma once
