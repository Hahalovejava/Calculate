// Calc.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Calc.h"
#include "iostream"
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	string s = "";
	string ss;
	
	cout << "Input:" ;
	cin >> s;
	ss = s;
	s += "#$";     //#��ջ���������������$��ʾ��ʽ��β
	int res = Calc(s, ss);
	cout << "Output:" << res;
	return 0;
}