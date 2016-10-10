// Calc.cpp : 定义控制台应用程序的入口点。
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
	s += "#$";     //#将栈中运算符都弹出，$表示算式结尾
	int res = Calc(s, ss);
	cout << "Output:" << res;
	return 0;
}