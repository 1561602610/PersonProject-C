#include "stdafx.h"

int main()
{
	cout << "����Ҫд����ļ�·�����ļ�����" << endl;
	string filename;
	cin >> filename;
	File f;
	f.Infile(filename);
	f.Wordscount(filename);
	f.Wordsway();
	f.Show();
	cout << "����Ҫ��ȡ���ļ�·�����ļ�����" << endl;
	cin >> filename;
	f.Outfile(filename);
	system("pause");
	return 0;
}