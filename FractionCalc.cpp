// FractionCalc.cpp : 定义控制台应用程序的入口点。
//

#include "head.h"



int _tmain(int argc, _TCHAR* argv[])
{
	cout << "请输入题目个数（1~100）：";
	int time, down, up, muldiv=0, frac=0, par=0;
	cin >> time;//time题目数
	cout <<"请输入数值绝对值范围:";
	cin >> down >> up;//[down,up]为运算数范围
	cout << "是否允许乘除法参与运算（y/n):";
	char yn1;
	cin >> yn1;
	yn1 == 'y' || yn1 == 'Y' ? muldiv = 1 : muldiv = 0;
	cout << "是否允许括号参与运算（y/n):";
	char yn2;
	cin >> yn2;
	yn2 == 'y' || yn2 == 'Y' ? par  = 1 : par = 0;
	cout << "是否允许真分数参与运算（y/n):";
	char yn3;
	cin >> yn3;
	yn3 == 'y' || yn3 == 'Y' ? frac = 1 : frac = 0;
	cout << "****************************************************************************" << endl;
	generate(time, down, up, muldiv, frac, par);
	system("pause");
	return 0;
}

